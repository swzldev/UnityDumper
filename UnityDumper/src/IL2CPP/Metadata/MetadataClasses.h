#pragma once

#include <cstdint>

#include <CppReflection/Reflection.h>

struct Il2CppMetadataClass {
	std::vector<CppObject*> fields;

    std::streampos position;

    size_t GetTrueSize(float version) const {
        size_t size = 0;
		for (CppObject* field : fields) {
			if (version < field->minVersion || version > field->maxVersion) continue;
            size += field->GetType().size;
		}
		return size;
    }
};

struct Il2CppGlobalMetadataHeader : Il2CppMetadataClass {
    CppUInt32 sanity;
    CppInt32 version;
    CppUInt32 stringLiteralOffset;
    CppInt32 stringLiteralSize;
    CppUInt32 stringLiteralDataOffset;
    CppInt32 stringLiteralDataSize;
    CppUInt32 stringOffset;
    CppInt32 stringSize;
    CppUInt32 eventsOffset;
    CppInt32 eventsSize;
    CppUInt32 propertiesOffset;
    CppInt32 propertiesSize;
    CppUInt32 methodsOffset;
    CppInt32 methodsSize;
    CppUInt32 parameterDefaultValuesOffset;
    CppInt32 parameterDefaultValuesSize;
    CppUInt32 fieldDefaultValuesOffset;
    CppInt32 fieldDefaultValuesSize;
    CppUInt32 fieldAndParameterDefaultValueDataOffset;
    CppInt32 fieldAndParameterDefaultValueDataSize;
    CppInt32 fieldMarshaledSizesOffset;
    CppInt32 fieldMarshaledSizesSize;
    CppUInt32 parametersOffset;
    CppInt32 parametersSize;
    CppUInt32 fieldsOffset;
    CppInt32 fieldsSize;
    CppUInt32 genericParametersOffset;
    CppInt32 genericParametersSize;
    CppUInt32 genericParameterConstraintsOffset;
    CppInt32 genericParameterConstraintsSize;
    CppUInt32 genericContainersOffset;
    CppInt32 genericContainersSize;
    CppUInt32 nestedTypesOffset;
    CppInt32 nestedTypesSize;
    CppUInt32 interfacesOffset;
    CppInt32 interfacesSize;
    CppUInt32 vtableMethodsOffset;
    CppInt32 vtableMethodsSize;
    CppInt32 interfaceOffsetsOffset;
    CppInt32 interfaceOffsetsSize;
    CppUInt32 typeDefinitionsOffset;
    CppInt32 typeDefinitionsSize;
    CppUInt32 rgctxEntriesOffset;
    CppInt32 rgctxEntriesCount;
    CppUInt32 imagesOffset;
    CppInt32 imagesSize;
    CppUInt32 assembliesOffset;
    CppInt32 assembliesSize;
    CppUInt32 metadataUsageListsOffset;
    CppInt32 metadataUsageListsCount;
    CppUInt32 metadataUsagePairsOffset;
    CppInt32 metadataUsagePairsCount;
    CppUInt32 fieldRefsOffset;
    CppInt32 fieldRefsSize;
    CppInt32 referencedAssembliesOffset;
    CppInt32 referencedAssembliesSize;
    CppUInt32 attributesInfoOffset;
    CppInt32 attributesInfoCount;
    CppUInt32 attributeTypesOffset;
    CppInt32 attributeTypesCount;
    CppUInt32 attributeDataOffset;
    CppInt32 attributeDataSize;
    CppUInt32 attributeDataRangeOffset;
    CppInt32 attributeDataRangeSize;
    CppInt32 unresolvedVirtualCallParameterTypesOffset;
    CppInt32 unresolvedVirtualCallParameterTypesSize;
    CppInt32 unresolvedVirtualCallParameterRangesOffset;
    CppInt32 unresolvedVirtualCallParameterRangesSize;
    CppInt32 windowsRuntimeTypeNamesOffset;
    CppInt32 windowsRuntimeTypeNamesSize;
    CppInt32 windowsRuntimeStringsOffset;
    CppInt32 windowsRuntimeStringsSize;
    CppInt32 exportedTypeDefinitionsOffset;
    CppInt32 exportedTypeDefinitionsSize;

    Il2CppGlobalMetadataHeader() {
		fields = {
			&sanity, &version, &stringLiteralOffset, &stringLiteralSize, &stringLiteralDataOffset, &stringLiteralDataSize, &stringOffset, &stringSize,
			&eventsOffset, &eventsSize, &propertiesOffset, &propertiesSize, &methodsOffset, &methodsSize, &parameterDefaultValuesOffset,
			&parameterDefaultValuesSize, &fieldDefaultValuesOffset, &fieldDefaultValuesSize, &fieldAndParameterDefaultValueDataOffset,
			&fieldAndParameterDefaultValueDataSize, &fieldMarshaledSizesOffset, &fieldMarshaledSizesSize, &parametersOffset, &parametersSize,
			&fieldsOffset, &fieldsSize, &genericParametersOffset, &genericParametersSize, &genericParameterConstraintsOffset,
			&genericParameterConstraintsSize, &genericContainersOffset, &genericContainersSize, &nestedTypesOffset, &nestedTypesSize,
			&interfacesOffset, &interfacesSize, &vtableMethodsOffset, &vtableMethodsSize, &interfaceOffsetsOffset, &interfaceOffsetsSize,
			&typeDefinitionsOffset, &typeDefinitionsSize, &rgctxEntriesOffset, &rgctxEntriesCount, &imagesOffset, &imagesSize,
			&assembliesOffset, &assembliesSize, &metadataUsageListsOffset, &metadataUsageListsCount, &metadataUsagePairsOffset,
			&metadataUsagePairsCount, &fieldRefsOffset, &fieldRefsSize, &referencedAssembliesOffset, &referencedAssembliesSize,
			&attributesInfoOffset, &attributesInfoCount, &attributeTypesOffset, &attributeTypesCount, &attributeDataOffset, &attributeDataSize,
			&attributeDataRangeOffset, &attributeDataRangeSize, &unresolvedVirtualCallParameterTypesOffset, &unresolvedVirtualCallParameterTypesSize,
			&unresolvedVirtualCallParameterRangesOffset, &unresolvedVirtualCallParameterRangesSize, &windowsRuntimeTypeNamesOffset, &windowsRuntimeTypeNamesSize,
			&windowsRuntimeStringsOffset, &windowsRuntimeStringsSize, &exportedTypeDefinitionsOffset, &exportedTypeDefinitionsSize
		};

        rgctxEntriesOffset = CppUInt32(0.0f, 24.1f);
        rgctxEntriesCount = CppInt32(0.0f, 24.1f);
        metadataUsageListsOffset = CppUInt32(19.0f, 24.5f);
        metadataUsageListsCount = CppInt32(19.0f, 24.5f);
        metadataUsagePairsOffset = CppUInt32(19.0f, 24.5f);
        metadataUsagePairsCount = CppInt32(19.0f, 24.5f);
        fieldRefsOffset = CppUInt32(19.0f);
        fieldRefsSize = CppInt32(19.0f);
        attributesInfoOffset = CppUInt32(21.0f, 27.2f);
        attributesInfoCount = CppInt32(21.0f, 27.2f);
        attributeTypesOffset = CppUInt32(21.0f, 27.2f);
        attributeTypesCount = CppInt32(21.0f, 27.2f);
        attributeDataOffset = CppUInt32(29.0f);
        attributeDataSize = CppInt32(29.0f);
        attributeDataRangeOffset = CppUInt32(29.0f);
        attributeDataRangeSize = CppInt32(29.0f);
    }
};

struct Il2CppAssemblyNameDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppUInt32 cultureIndex;
    CppInt32 hashValueIndex;
    CppUInt32 publicKeyIndex;
    CppUInt32 hash_alg;
    CppInt32 hash_len;
    CppUInt32 flags;
    CppInt32 major;
    CppInt32 minor;
    CppInt32 build;
    CppInt32 revision;
	CppArray<CppUInt8> public_key_token = CppArray<CppUInt8>(8);

    Il2CppAssemblyNameDefinition() {
        fields = {
            &nameIndex, &cultureIndex, &hashValueIndex, &publicKeyIndex, &hash_alg, &hash_len, &flags, &major, &minor, &build, &revision
        };

        hashValueIndex = CppInt32(0.0f, 24.3f);
    }
};

struct Il2CppAssemblyDefinition : Il2CppMetadataClass {
    CppInt32 imageIndex;
    CppUInt32 token;
    CppInt32 customAttributeIndex;
    CppInt32 referencedAssemblyStart;
    CppInt32 referencedAssemblyCount;
    struct Il2CppAssemblyNameDefinition aname;

    Il2CppAssemblyDefinition() {
        fields = {
            &imageIndex, &token, &customAttributeIndex, &referencedAssemblyStart, &referencedAssemblyCount
        };

        token = CppUInt32(24.1f);
        customAttributeIndex = CppInt32(0.0f, 24.0f);
        referencedAssemblyStart = CppInt32(20.0f);
        referencedAssemblyCount = CppInt32(20.0f);
    }
};

struct Il2CppImageDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppInt32 assemblyIndex;
    CppInt32 typeStart;
    CppUInt32 typeCount;
    CppInt32 exportedTypeStart;
    CppUInt32 exportedTypeCount;
    CppInt32 entryPointIndex;
    CppUInt32 token;
    CppInt32 customAttributeStart;
    CppUInt32 customAttributeCount;

    Il2CppImageDefinition() {
        fields = {
            &nameIndex, &assemblyIndex, &typeStart, &typeCount, &exportedTypeStart, &exportedTypeCount, &entryPointIndex, &token,
            &customAttributeStart, &customAttributeCount
        };

        exportedTypeStart = CppInt32(24.0f);
        exportedTypeCount = CppUInt32(24.0f);
        token = CppUInt32(19.0f);
        customAttributeStart = CppInt32(24.1f);
        customAttributeCount = CppUInt32(24.1f);
    }
};

struct Il2CppTypeDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppUInt32 namespaceIndex;
    CppInt32 customAttributeIndex;
    CppInt32 byvalTypeIndex;
    CppInt32 byrefTypeIndex;
    CppInt32 declaringTypeIndex;
    CppInt32 parentIndex;
    CppInt32 elementTypeIndex;
    CppInt32 rgctxStartIndex;
    CppInt32 rgctxCount;
    CppInt32 genericContainerIndex;
    CppInt32 delegateWrapperFromManagedToNativeIndex;
    CppInt32 marshalingFunctionsIndex;
    CppInt32 ccwFunctionIndex;
    CppInt32 guidIndex;
    CppUInt32 flags;
    CppInt32 fieldStart;
    CppInt32 methodStart;
    CppInt32 eventStart;
    CppInt32 propertyStart;
    CppInt32 nestedTypesStart;
    CppInt32 interfacesStart;
    CppInt32 vtableStart;
    CppInt32 interfaceOffsetsStart;
    CppUInt16 method_count;
    CppUInt16 property_count;
    CppUInt16 field_count;
    CppUInt16 event_count;
    CppUInt16 nested_type_count;
    CppUInt16 vtable_count;
    CppUInt16 interfaces_count;
    CppUInt16 interface_offsets_count;
    CppUInt32 bitfield;
    CppUInt32 token;

    Il2CppTypeDefinition() {
        fields = {
            &nameIndex, &namespaceIndex, &customAttributeIndex, &byvalTypeIndex, &byrefTypeIndex, &declaringTypeIndex, &parentIndex,
            &elementTypeIndex, &rgctxStartIndex, &rgctxCount, &genericContainerIndex, &delegateWrapperFromManagedToNativeIndex,
            &marshalingFunctionsIndex, &ccwFunctionIndex, &guidIndex, &flags, &fieldStart, &methodStart, &eventStart, &propertyStart,
            &nestedTypesStart, &interfacesStart, &vtableStart, &interfaceOffsetsStart, &method_count, &property_count, &field_count,
            &event_count, &nested_type_count, &vtable_count, &interfaces_count, &interface_offsets_count, &bitfield, &token
        };

        customAttributeIndex = CppInt32(0.0f, 24.0f);
        byrefTypeIndex = CppInt32(0.0f, 24.5f);
        rgctxStartIndex = CppInt32(0.0f, 24.1f);
        rgctxCount = CppInt32(0.0f, 24.1f);
        delegateWrapperFromManagedToNativeIndex = CppInt32(0.0f, 22.0f);
        marshalingFunctionsIndex = CppInt32(0.0f, 22.0f);
        ccwFunctionIndex = CppInt32(21.0f, 22.0f);
        guidIndex = CppInt32(21.0f, 22.0f);
        token = CppUInt32(19.0f);
    }

    bool IsValueType() const { return bitfield.value & 0x1; }
    bool IsEnum() const { return (bitfield.value >> 1) & 0x1; }
};

struct Il2CppMethodDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppInt32 declaringType;
    CppInt32 returnType;
    CppInt32 returnParameterToken;
    CppInt32 parameterStart;
    CppInt32 customAttributeIndex;
    CppInt32 genericContainerIndex;
    CppInt32 methodIndex;
    CppInt32 invokerIndex;
    CppInt32 delegateWrapperIndex;
    CppInt32 rgctxStartIndex;
    CppInt32 rgctxCount;
    CppUInt32 token;
    CppUInt16 flags;
    CppUInt16 iflags;
    CppUInt16 slot;
    CppUInt16 parameterCount;

    Il2CppMethodDefinition() {
        fields = {
            &nameIndex, &declaringType, &returnType, &returnParameterToken, &parameterStart, &customAttributeIndex, &genericContainerIndex,
            &methodIndex, &invokerIndex, &delegateWrapperIndex, &rgctxStartIndex, &rgctxCount, &token, &flags, &iflags, &slot, &parameterCount
        };

        returnParameterToken = CppInt32(31.0f);
        customAttributeIndex = CppInt32(0.0f, 24.0f);
        methodIndex = CppInt32(0.0f, 24.1f);
        invokerIndex = CppInt32(0.0f, 24.1f);
        delegateWrapperIndex = CppInt32(0.0f, 24.1f);
        rgctxStartIndex = CppInt32(0.0f, 24.1f);
        rgctxCount = CppInt32(0.0f, 24.1f);
    }
};

struct Il2CppParameterDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppUInt32 token;
    CppInt32 customAttributeIndex;
    CppInt32 typeIndex;

    Il2CppParameterDefinition() {
        fields = {
            &nameIndex, &token, &customAttributeIndex, &typeIndex
        };

        customAttributeIndex = CppInt32(0.0f, 24.0f);
    }
};

struct Il2CppFieldDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppInt32 typeIndex;
    CppInt32 customAttributeIndex;
    CppUInt32 token;

    Il2CppFieldDefinition() {
        fields = {
            &nameIndex, &typeIndex, &customAttributeIndex, &token
        };

        customAttributeIndex = CppInt32(0.0f, 24.0f);
        token = CppUInt32(19.0f);
    }
};

struct Il2CppFieldDefaultValue : Il2CppMetadataClass {
    CppInt32 fieldIndex;
    CppInt32 typeIndex;
    CppInt32 dataIndex;

    Il2CppFieldDefaultValue() {
        fields = {
            &fieldIndex, &typeIndex, &dataIndex
        };
    }
};

struct Il2CppPropertyDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppInt32 get;
    CppInt32 set;
    CppUInt32 attrs;
    CppInt32 customAttributeIndex;
    CppUInt32 token;

    Il2CppPropertyDefinition() {
        fields = {
            &nameIndex, &get, &set, &attrs, &customAttributeIndex, &token
        };

        customAttributeIndex = CppInt32(0.0f, 24.0f);
        token = CppUInt32(19.0f);
    }
};

struct Il2CppCustomAttributeTypeRange : Il2CppMetadataClass {
    CppUInt32 token;
    CppInt32 start;
    CppInt32 count;

    Il2CppCustomAttributeTypeRange() {
        fields = {
            &token, &start, &count
        };

        token = CppUInt32(24.1f);
    }
};

struct Il2CppMetadataUsageList : Il2CppMetadataClass {
    CppUInt32 start;
    CppUInt32 count;

    Il2CppMetadataUsageList() {
        fields = {
            &start, &count
        };
    }
};

struct Il2CppMetadataUsagePair : Il2CppMetadataClass {
    CppUInt32 destinationIndex;
    CppUInt32 encodedSourceIndex;

    Il2CppMetadataUsagePair() {
        fields = {
            &destinationIndex, &encodedSourceIndex
        };
    }
};

struct Il2CppStringLiteral : Il2CppMetadataClass {
    CppUInt32 length;
    CppInt32 dataIndex;

    Il2CppStringLiteral() {
        fields = {
            &length, &dataIndex
        };
    }
};

struct Il2CppParameterDefaultValue : Il2CppMetadataClass {
    CppInt32 parameterIndex;
    CppInt32 typeIndex;
    CppInt32 dataIndex;

    Il2CppParameterDefaultValue() {
        fields = {
            &parameterIndex, &typeIndex, &dataIndex
        };
    }
};

struct Il2CppEventDefinition : Il2CppMetadataClass {
    CppUInt32 nameIndex;
    CppInt32 typeIndex;
    CppInt32 add;
    CppInt32 remove;
    CppInt32 raise;
    CppInt32 customAttributeIndex;
    CppUInt32 token;

    Il2CppEventDefinition() {
        fields = {
            &nameIndex, &typeIndex, &add, &remove, &raise, &customAttributeIndex, &token
        };

		customAttributeIndex = CppInt32(0.0f, 24.0f);
		token = CppUInt32(19.0f);
    }
};

struct Il2CppGenericContainer : Il2CppMetadataClass {
    CppInt32 ownerIndex;
    CppInt32 type_argc;
    CppInt32 is_method;
    CppInt32 genericParameterStart;

    Il2CppGenericContainer() {
        fields = {
            &ownerIndex, &type_argc, &is_method, &genericParameterStart
        };
    }
};

struct Il2CppFieldRef : Il2CppMetadataClass {
    CppInt32 typeIndex;
    CppInt32 fieldIndex;

	Il2CppFieldRef() {
		fields = {
			&typeIndex, &fieldIndex
		};
	}
};

struct Il2CppGenericParameter : Il2CppMetadataClass {
    CppInt32 ownerIndex;
    CppUInt32 nameIndex;
    CppInt16 constraintsStart;
    CppInt16 constraintsCount;
    CppUInt16 num;
    CppUInt16 flags;

	Il2CppGenericParameter() {
		fields = {
			&ownerIndex, &nameIndex, &constraintsStart, &constraintsCount, &num, &flags
		};
	}
};

enum Il2CppRGCTXDataType {
    IL2CPP_RGCTX_DATA_INVALID,
    IL2CPP_RGCTX_DATA_TYPE,
    IL2CPP_RGCTX_DATA_CLASS,
    IL2CPP_RGCTX_DATA_METHOD,
    IL2CPP_RGCTX_DATA_ARRAY,
    IL2CPP_RGCTX_DATA_CONSTRAINED,
};

struct Il2CppRGCTXDefinitionData {
    CppInt32 rgctxDataDummy;
    CppInt32 MethodIndex() const { return rgctxDataDummy; }
    CppInt32 TypeIndex() const { return rgctxDataDummy; }
};

struct Il2CppRGCTXDefinition : Il2CppMetadataClass {
    Il2CppRGCTXDataType Type() const { return type_pre271.value == 0 ? (Il2CppRGCTXDataType)(type_post290.value) : (Il2CppRGCTXDataType)(type_pre271.value); }
    CppInt32 type_pre271 = CppInt32(0.0f, 27.1f);
	CppUInt64 type_post290 = CppUInt64(29.0f);
    Il2CppRGCTXDefinitionData data_pre271; // Max version 27.1
	CppUInt64 data_post272 = CppUInt64(27.2f);

	Il2CppRGCTXDefinition() {
		fields = {
			&type_pre271, &type_post290, &data_post272
		};
	}
};

enum Il2CppMetadataUsage {
    kIl2CppMetadataUsageInvalid,
    kIl2CppMetadataUsageTypeInfo,
    kIl2CppMetadataUsageIl2CppType,
    kIl2CppMetadataUsageMethodDef,
    kIl2CppMetadataUsageFieldInfo,
    kIl2CppMetadataUsageStringLiteral,
    kIl2CppMetadataUsageMethodRef,
};

struct Il2CppCustomAttributeDataRange : Il2CppMetadataClass {
    CppUInt32 token;
    CppUInt32 startOffset;

    Il2CppCustomAttributeDataRange() {
		fields = {
			&token, &startOffset
		};
    }
};