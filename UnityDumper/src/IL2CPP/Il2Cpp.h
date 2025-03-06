#pragma once

#include <string>

bool GetGameAssemblyPath(const std::string& gamePath, std::string& assemblyPath);
std::string GetGameAssemblyPathManual();
bool GetMetadataPath(const std::string& gamePath, std::string& metadataPath);
std::string GetMetadataPathManual();

bool IsMetadataSupported(float version);

void AnalyzeIl2Cpp(std::string gamePath);