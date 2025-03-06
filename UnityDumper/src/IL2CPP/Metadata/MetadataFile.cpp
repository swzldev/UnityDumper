#include "MetadataFile.h"

#include <algorithm>

#include <IL2CPP/Il2Cpp.h>

MetadataFile::~MetadataFile() {
	if (m_MetadataFile.is_open()) {
		m_MetadataFile.close();
	}
}

bool MetadataFile::Load(const std::string& path) {
	// Open metadata file
	m_MetadataFile.open(path, std::ios::binary);
	if (!m_MetadataFile.is_open()) {
		Output::Error("Failed to open metadata file: %s", path.c_str());
		return false;
	}

	// Read sanity
	uint32_t sanity{};
	ReadData(&sanity, sizeof(sanity));
	if (sanity != 0xFAB11BAF) {
		Output::Error("Invalid metadata sanity: %s", path.c_str());
		return false;
	}
	// Read version
	int32_t version{};
	ReadData(&version, sizeof(version));
	if (!IsMetadataSupported(version)) {
		Output::Error("Unsupported metadata version: %d", version);
		return false;
	}
	m_Version = (float)version;

	// Read header
	Output::Log("Reading header, size: %u", m_Header.GetTrueSize(m_Version));
	m_Header = ReadMetadataClass<Il2CppGlobalMetadataHeader>(0, m_Header.GetTrueSize(m_Version));
	if (!m_MetadataFile.good()) {
		Output::Error("Failed to read metadata header: %s", path.c_str());
		return false;
	}
	if (m_Version == 24) {
		if (m_Header.stringLiteralOffset.value == 264) {
			m_Version = 24.2f;
			m_Header = ReadMetadataClass<Il2CppGlobalMetadataHeader>(0, m_Header.GetTrueSize(m_Version));
		}
		else {
			m_ImageDefs = ReadMetadataClassArray<Il2CppImageDefinition>(m_Header.imagesOffset.value, m_Header.imagesSize.value);
			if (std::any_of(m_ImageDefs.begin(), m_ImageDefs.end(), [](const Il2CppImageDefinition& image) { return image.token.value != 1; })) {
				m_Version = 24.1f;
			}
		}
	}
	m_ImageDefs = ReadMetadataClassArray<Il2CppImageDefinition>(m_Header.imagesOffset.value, m_Header.imagesSize.value);
	if (m_Version == 24.2f && m_Header.assembliesSize.value / 68 < m_ImageDefs.size())
	{
		m_Version = 24.4;
	}
	bool v241Plus = false;
	if (m_Version == 24.1 && m_Header.assembliesSize.value / 64 == m_ImageDefs.size())
	{
		v241Plus = true;
	}
	if (v241Plus)
	{
		m_Version = 24.4;
	}
	m_AssemblyDefs = ReadMetadataClassArray<Il2CppAssemblyDefinition>(m_Header.assembliesOffset.value, m_Header.assembliesSize.value);
	if (v241Plus)
	{
		m_Version = 24.1;
	}
	m_TypeDefs = ReadMetadataClassArray<Il2CppTypeDefinition>(m_Header.typeDefinitionsOffset.value, m_Header.typeDefinitionsSize.value);
	m_MethodDefs = ReadMetadataClassArray<Il2CppMethodDefinition>(m_Header.methodsOffset.value, m_Header.methodsSize.value);
	m_ParameterDefs = ReadMetadataClassArray<Il2CppParameterDefinition>(m_Header.parametersOffset.value, m_Header.parametersSize.value);
	m_FieldDefs = ReadMetadataClassArray<Il2CppFieldDefinition>(m_Header.fieldsOffset.value, m_Header.fieldsSize.value);
	std::vector<Il2CppFieldDefaultValue> fieldDefaultValues = ReadMetadataClassArray<Il2CppFieldDefaultValue>(m_Header.fieldDefaultValuesOffset.value, m_Header.fieldDefaultValuesSize.value);
	std::vector<Il2CppParameterDefaultValue> parameterDefaultValues = ReadMetadataClassArray<Il2CppParameterDefaultValue>(m_Header.parameterDefaultValuesOffset.value, m_Header.parameterDefaultValuesSize.value);
	m_FieldDefaultValuesDic = ToMap<int32_t, Il2CppFieldDefaultValue>(fieldDefaultValues, [](const Il2CppFieldDefaultValue& x) { return x.fieldIndex.value; });
	m_ParameterDefaultValuesDic = ToMap<int32_t, Il2CppParameterDefaultValue>(parameterDefaultValues, [](const Il2CppParameterDefaultValue& x) { return x.parameterIndex.value; });
	m_PropertyDefs = ReadMetadataClassArray<Il2CppPropertyDefinition>(m_Header.propertiesOffset.value, m_Header.propertiesSize.value);
	m_InterfaceIndices = ReadArray<int32_t>(m_Header.interfacesOffset.value, m_Header.interfacesSize.value);
	m_NestedTypeIndices = ReadArray<int32_t>(m_Header.nestedTypesOffset.value, m_Header.nestedTypesSize.value);
	m_EventDefs = ReadMetadataClassArray<Il2CppEventDefinition>(m_Header.eventsOffset.value, m_Header.eventsSize.value);
	m_GenericContainers = ReadMetadataClassArray<Il2CppGenericContainer>(m_Header.genericContainersOffset.value, m_Header.genericContainersSize.value);
	m_GenericParameters = ReadMetadataClassArray<Il2CppGenericParameter>(m_Header.genericParametersOffset.value, m_Header.genericParametersSize.value);
	m_ConstraintIndices = ReadArray<int32_t>(m_Header.genericParameterConstraintsOffset.value, m_Header.genericParameterConstraintsSize.value);
	m_VtableMethods = ReadArray<uint32_t>(m_Header.vtableMethodsOffset.value, m_Header.vtableMethodsSize.value);
	m_StringLiterals = ReadMetadataClassArray<Il2CppStringLiteral>(m_Header.stringLiteralOffset.value, m_Header.stringLiteralSize.value);
	if (m_Version > 16) {
		m_FieldRefs = ReadMetadataClassArray<Il2CppFieldRef>(m_Header.fieldRefsOffset.value, m_Header.fieldRefsSize.value);
		if (m_Version < 27) {
			m_MetadataUsageLists = ReadMetadataClassArray<Il2CppMetadataUsageList>(m_Header.metadataUsageListsOffset.value, m_Header.metadataUsageListsCount.value);
			m_MetadataUsagePairs = ReadMetadataClassArray<Il2CppMetadataUsagePair>(m_Header.metadataUsagePairsOffset.value, m_Header.metadataUsagePairsCount.value);
			// TODO: process dictionary
		}
	}
	if (m_Version > 20 && m_Version < 29) {
		m_AttributeTypeRanges = ReadMetadataClassArray<Il2CppCustomAttributeTypeRange>(m_Header.attributeTypesOffset.value, m_Header.attributeTypesCount.value);
		m_AttributeTypes = ReadArray<int32_t>(m_Header.attributeDataOffset.value, m_Header.attributeDataSize.value);
	}
	if (m_Version >= 29) {
		m_AttributeDataRanges = ReadMetadataClassArray<Il2CppCustomAttributeDataRange>(m_Header.attributeDataRangeOffset.value, m_Header.attributeDataRangeSize.value);
	}
	if (m_Version <= 24.1) {
		m_RgctxEntries = ReadMetadataClassArray<Il2CppRGCTXDefinition>(m_Header.rgctxEntriesOffset.value, m_Header.rgctxEntriesCount.value);
	}
	return true;
	if (!m_MetadataFile.eof()) {
		Output::Error("Unexpected data in metadata file: %s", path.c_str());
	}
}

std::string MetadataFile::GetString(uint32_t index) {
	// Check if string is contained in the cache
	auto it = m_StringCache.find(index);
	if (it != m_StringCache.end()) {
		return it->second;
	}
	if (!m_MetadataFile.is_open()) {
		Output::Warn("Trying to read string without metadata file open.");
	}
	if (index >= m_Header.stringSize.value) {
		Output::Error("String index outside bounds: %u", index);
		return "";
	}
	// Save original file position
	std::streampos pos = m_MetadataFile.tellg();
	// Read null terminated utf-8 string
	m_MetadataFile.seekg(m_Header.stringOffset.value + index);
	std::string str;
	char c{};
	while (m_MetadataFile.get(c) && c != '\0') {
		str += c;
	}
	// Restore original file position
	m_MetadataFile.seekg(pos);
	// Cache string
	m_StringCache[index] = str;
	return str;
}
