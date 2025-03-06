/* Reflection.cpp -- Implementation of C# style reflection for c++ types */

#include <CppReflection/Reflection.h>

CppObject::CppObject(float minVersion, float maxVersion) : minVersion(minVersion), maxVersion(maxVersion) {}

// 8 bit integer object
CppInt8::CppInt8(float minVersion, float maxVersion, uint8_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppInt8::GetType() {
	static CppType type{ sizeof(int8_t), "Int8" };
	return type;
}

void CppInt8::SetValue(void* value) {
	this->value = *reinterpret_cast<int8_t*>(value);
}

void* CppInt8::GetValue() {
	return &value;
}

// 8 bit unsigned integer object
CppUInt8::CppUInt8(float minVersion, float maxVersion, uint8_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppUInt8::GetType() {
	static CppType type{ sizeof(uint8_t), "UInt8" };
	return type;
}

void CppUInt8::SetValue(void* value) {
	this->value = *reinterpret_cast<uint8_t*>(value);
}

void* CppUInt8::GetValue() {
	return &value;
}

// 16 bit integer object
CppInt16::CppInt16(float minVersion, float maxVersion, int16_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppInt16::GetType() {
	static CppType type{ sizeof(int16_t), "Int16" };
	return type;
}

void CppInt16::SetValue(void* value) {
	this->value = *reinterpret_cast<int16_t*>(value);
}

void* CppInt16::GetValue() {
	return &value;
}

// 16 bit unsigned integer object
CppUInt16::CppUInt16(float minVersion, float maxVersion, uint16_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppUInt16::GetType() {
	static CppType type{ sizeof(uint16_t), "UInt16" };
	return type;
}

void CppUInt16::SetValue(void* value) {
	this->value = *reinterpret_cast<uint16_t*>(value);
}

void* CppUInt16::GetValue() {
	return &value;
}

// 32 bit integer object
CppInt32::CppInt32(float minVersion, float maxVersion, int32_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppInt32::GetType() {
	static CppType type{ sizeof(int32_t), "Int32" };
	return type;
}

void CppInt32::SetValue(void* value) {
	this->value = *reinterpret_cast<int32_t*>(value);
}

void* CppInt32::GetValue() {
	return &value;
}

// 32 bit unsigned integer object
CppUInt32::CppUInt32(float minVersion, float maxVersion, uint32_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppUInt32::GetType() {
	static CppType type{ sizeof(uint32_t), "UInt32" };
	return type;
}

void CppUInt32::SetValue(void* value) {
	this->value = *reinterpret_cast<uint32_t*>(value);
}

void* CppUInt32::GetValue() {
	return &value;
}

// 64 bit integer object
CppInt64::CppInt64(float minVersion, float maxVersion, int64_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppInt64::GetType() {
	static CppType type{ sizeof(int64_t), "Int64" };
	return type;
}

void CppInt64::SetValue(void* value) {
	this->value = *reinterpret_cast<int64_t*>(value);
}

void* CppInt64::GetValue() {
	return &value;
}

// 64 bit unsigned integer object
CppUInt64::CppUInt64(float minVersion, float maxVersion, uint64_t value) : CppObject(minVersion, maxVersion), value(value) {}

const CppType& CppUInt64::GetType() {
	static CppType type{ sizeof(uint64_t), "UInt64" };
	return type;
}

void CppUInt64::SetValue(void* value) {
	this->value = *reinterpret_cast<uint64_t*>(value);
}

void* CppUInt64::GetValue() {
	return &value;
}