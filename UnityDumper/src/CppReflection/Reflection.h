/* Reflection.h -- C# style reflection for c++ types
*  Reflection is needed to override the default behaviour of builtin types
*/

#pragma once

#include <map>
#include <string>
#include <vector>

#include <IO/Output.h>

// Contains useful type information
struct CppType {
	size_t size;
	std::string name;
};

// Base class for all c++ reflection objects
struct CppObject {
	CppObject(float minVersion = 0, float maxVersion = 9999);

	virtual const CppType& GetType() = 0;

	virtual void SetValue(void* value) = 0;
	virtual void* GetValue() = 0;

	float minVersion;
	float maxVersion;
};

// 8 bit integer object
struct CppInt8 : CppObject {
	CppInt8(float minVersion = 0, float maxVersion = 9999, uint8_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	int8_t value;
};

// 8 bit unsigned integer object
struct CppUInt8 : CppObject {
	CppUInt8(float minVersion = 0, float maxVersion = 9999, uint8_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	uint8_t value;
};

// 16 bit integer object
struct CppInt16 : CppObject {
	CppInt16(float minVersion = 0, float maxVersion = 9999, int16_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	int16_t value;
};

// 16 bit unsigned integer object
struct CppUInt16 : CppObject {
	CppUInt16(float minVersion = 0, float maxVersion = 9999, uint16_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	uint16_t value;
};

// 32 bit integer object
struct CppInt32 : CppObject {
	CppInt32(float minVersion = 0, float maxVersion = 9999, int32_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	int32_t value;
};

// 32 bit unsigned integer object
struct CppUInt32 : CppObject {
	CppUInt32(float minVersion = 0, float maxVersion = 9999, uint32_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	uint32_t value;
};

// 64 bit integer object
struct CppInt64 : CppObject {
	CppInt64(float minVersion = 0, float maxVersion = 9999, int64_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	int64_t value;
};

// 64 bit unsigned integer object
struct CppUInt64 : CppObject {
	CppUInt64(float minVersion = 0, float maxVersion = 9999, uint64_t value = 0);

	const CppType& GetType() override;

	void SetValue(void* value) override;
	void* GetValue() override;

	uint64_t value;
};

// Array of elements object
template<typename T>
struct CppArray : CppObject {
	CppArray(size_t length, float minVersion = 0, float maxVersion = 9999) {
		T dummy{};
		if (dynamic_cast<CppObject*>(&dummy) == nullptr) {
			Output::Fatal("Attempted to create array of non reflectable type.", ERROR_FAILURE);
		}
		this->length = length;
		this->minVersion = minVersion;
		this->maxVersion = maxVersion;
	}

	const CppType& GetType() override {
		T dummy{};
		const CppType& elementType = dynamic_cast<CppObject*>(&dummy)->GetType();
		CppType type { elementType.size * length, "Array of " + elementType.name };
		return type;
	}

	void SetValue(void* value) override {
		T* typedValue = reinterpret_cast<T*>(value);
		this->value.assign(typedValue, typedValue + length);
	}

	void* GetValue() override {
		return value.data();
	}

private:
	std::vector<T> value;
	size_t length;
};