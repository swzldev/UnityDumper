#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <functional>

#include <IL2CPP/Metadata/MetadataClasses.h>
#include <CppReflection/Reflection.h>
#include <IO/Output.h>

#define UDUMPER_MIN_METADATA_VERSION 16
#define UDUMPER_MAX_METADATA_VERSION 31

class MetadataFile
{
public:
	MetadataFile() = default;
	~MetadataFile();

	bool Load(const std::string& path);

public: // Metadata structures
	const Il2CppGlobalMetadataHeader& GetHeader() const { return m_Header; }
	const std::vector<Il2CppImageDefinition>& GetImageDefs() const { return m_ImageDefs; }
	const std::vector<Il2CppAssemblyDefinition>& GetAssemblyDefs() const { return m_AssemblyDefs; }
	const std::vector<Il2CppTypeDefinition>& GetTypeDefs() const { return m_TypeDefs; }
	const std::vector<Il2CppMethodDefinition>& GetMethodDefs() const { return m_MethodDefs; }
	const std::vector<Il2CppParameterDefinition>& GetParameterDefs() const { return m_ParameterDefs; }
	const std::vector<Il2CppFieldDefinition>& GetFieldDefs() const { return m_FieldDefs; }
	const std::unordered_map<int32_t, Il2CppFieldDefaultValue>& GetFieldDefaultValuesDic() const { return m_FieldDefaultValuesDic; }
	const std::unordered_map<int32_t, Il2CppParameterDefaultValue>& GetParameterDefaultValuesDic() const { return m_ParameterDefaultValuesDic; }
	const std::vector<Il2CppPropertyDefinition>& GetPropertyDefs() const { return m_PropertyDefs; }
	const std::vector<Il2CppCustomAttributeTypeRange>& GetAttributeTypeRanges() const { return m_AttributeTypeRanges; }
	const std::vector<Il2CppCustomAttributeDataRange>& GetAttributeDataRanges() const { return m_AttributeDataRanges; }
	const std::unordered_map<Il2CppImageDefinition*, std::unordered_map<uint32_t, int32_t>>& GetAttributeTypeRangesDic() const { return m_AttributeTypeRangesDic; }
	const std::vector<Il2CppStringLiteral>& GetStringLiterals() const { return m_StringLiterals; }
	const std::vector<Il2CppMetadataUsageList>& GetMetadataUsageLists() const { return m_MetadataUsageLists; }
	const std::vector<Il2CppMetadataUsagePair>& GetMetadataUsagePairs() const { return m_MetadataUsagePairs; }
	const std::vector<int32_t>& GetAttributeTypes() const { return m_AttributeTypes; }
	const std::vector<int32_t>& GetInterfaceIndices() const { return m_InterfaceIndices; }
	const std::unordered_map<Il2CppMetadataUsage, std::unordered_map<uint32_t, uint32_t>>& GetMetadataUsageDic() const { return m_MetadataUsageDic; }
	int64_t GetMetadataUsagesCount() const { return m_MetadataUsagesCount; }
	const std::vector<int32_t>& GetNestedTypeIndices() const { return m_NestedTypeIndices; }
	const std::vector<Il2CppEventDefinition>& GetEventDefs() const { return m_EventDefs; }
	const std::vector<Il2CppGenericContainer>& GetGenericContainers() const { return m_GenericContainers; }
	const std::vector<Il2CppFieldRef>& GetFieldRefs() const { return m_FieldRefs; }
	const std::vector<Il2CppGenericParameter>& GetGenericParameters() const { return m_GenericParameters; }
	const std::vector<int32_t>& GetConstraintIndices() const { return m_ConstraintIndices; }
	const std::vector<uint32_t>& GetVtableMethods() const { return m_VtableMethods; }
	const std::vector<Il2CppRGCTXDefinition>& GetRgctxEntries() const { return m_RgctxEntries; }

	const float GetVersion() const { return m_Version; }

private: // Metadata structures
	Il2CppGlobalMetadataHeader m_Header;
    std::vector<Il2CppImageDefinition> m_ImageDefs;
    std::vector<Il2CppAssemblyDefinition> m_AssemblyDefs;
    std::vector<Il2CppTypeDefinition> m_TypeDefs;
    std::vector<Il2CppMethodDefinition> m_MethodDefs;
    std::vector<Il2CppParameterDefinition> m_ParameterDefs;
    std::vector<Il2CppFieldDefinition> m_FieldDefs;
    std::unordered_map<int32_t, Il2CppFieldDefaultValue> m_FieldDefaultValuesDic;
    std::unordered_map<int32_t, Il2CppParameterDefaultValue> m_ParameterDefaultValuesDic;
    std::vector<Il2CppPropertyDefinition> m_PropertyDefs;
    std::vector<Il2CppCustomAttributeTypeRange> m_AttributeTypeRanges;
    std::vector<Il2CppCustomAttributeDataRange> m_AttributeDataRanges;
    std::unordered_map<Il2CppImageDefinition*, std::unordered_map<uint32_t, int32_t>> m_AttributeTypeRangesDic;
    std::vector<Il2CppStringLiteral> m_StringLiterals;
    std::vector<Il2CppMetadataUsageList> m_MetadataUsageLists;
    std::vector<Il2CppMetadataUsagePair> m_MetadataUsagePairs;
    std::vector<int32_t> m_AttributeTypes;
    std::vector<int32_t> m_InterfaceIndices;
    std::unordered_map<Il2CppMetadataUsage, std::unordered_map<uint32_t, uint32_t>> m_MetadataUsageDic;
    int64_t m_MetadataUsagesCount;
    std::vector<int32_t> m_NestedTypeIndices;
    std::vector<Il2CppEventDefinition> m_EventDefs;
    std::vector<Il2CppGenericContainer> m_GenericContainers;
    std::vector<Il2CppFieldRef> m_FieldRefs;
    std::vector<Il2CppGenericParameter> m_GenericParameters;
    std::vector<int32_t> m_ConstraintIndices;
    std::vector<uint32_t> m_VtableMethods;
    std::vector<Il2CppRGCTXDefinition> m_RgctxEntries;

public: // Public utility functions
	std::string GetString(uint32_t index);

private: // Private member vars
	std::unordered_map<uint32_t, std::string> m_StringCache;
	float m_Version;
	std::ifstream m_MetadataFile;

private: // Private utility functions
	bool ReadData(void* buffer, size_t size) {
		m_MetadataFile.read(reinterpret_cast<char*>(buffer), size);
		return m_MetadataFile.good();
	}

	template<typename T>
	std::vector<T> ReadArray(std::streampos offset, size_t count) {
		std::vector<T> data(count);
		m_MetadataFile.seekg(offset);
		for (size_t i = 0; i < count; i++) {
			ReadData(&data[i], sizeof(T));
		}
		return data;
	}

	template<typename T>
	T ReadMetadataClass(std::streampos offset, size_t size) {
		T klass{};
		Il2CppMetadataClass* klassBase = dynamic_cast<Il2CppMetadataClass*>(&klass);
		if (klassBase == nullptr) {
			Output::Fatal("Attempted to read non metadata class type.", METADATA_CLASS_READ_FAIL);
		}
		m_MetadataFile.seekg(offset);
		for (CppObject* field : klassBase->fields) {
			if (m_Version < field->minVersion || m_Version > field->maxVersion) {
				continue;
			}
			const CppType& fieldType = field->GetType();
			std::vector<uint8_t> data(fieldType.size);
			ReadData(data.data(), fieldType.size);
			try {
				field->SetValue(data.data());
			}
			catch (std::exception& e) {
				Output::Fatal("Failed to set value for field: %s", METADATA_CLASS_READ_FAIL, e.what());
			}
		}
		return klass;
	}

	template<typename T>
	std::vector<T> ReadMetadataClassArray(std::streampos offset, size_t count) {
		T klass{};
		Il2CppMetadataClass* klassBase = dynamic_cast<Il2CppMetadataClass*>(&klass);
		if (klassBase == nullptr) {
			Output::Fatal("Attempted to read non metadata class type.", METADATA_CLASS_READ_FAIL);
		}
		std::vector<T> data;
		size_t klassSize = klassBase->GetTrueSize(m_Version);
		for (size_t i = 0; i < count / klassSize; i++) {
			T k = ReadMetadataClass<T>(offset + static_cast<std::streamoff>(i * klassSize), klassSize);
			Il2CppMetadataClass* kBase = dynamic_cast<Il2CppMetadataClass*>(&k);
			kBase->position = offset + static_cast<std::streamoff>(i * klassSize);
			data.push_back(k);
		}
		return data;
	}

	template<typename TKey, typename TVal>
	std::unordered_map<TKey, TVal> ToMap(const std::vector<TVal>& vec, std::function<TKey(const TVal& x)> fn) {
		std::unordered_map<TKey, TVal> map;
		for (const TVal& val : vec) {
			map[fn(val)] = val;
		}
		return map;
	}
};