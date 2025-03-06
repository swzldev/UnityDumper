#include "Il2Cpp.h"

#include <filesystem>

#include <IO/Input.h>
#include <IO/Output.h>
#include <IL2CPP/Metadata/MetadataFile.h>

bool GetGameAssemblyPath(const std::string& gamePath, std::string& assemblyPath) {
	std::filesystem::path path(gamePath);
	path /= "GameAssembly.dll";
	if (!std::filesystem::exists(path)) {
		return false;
	}
	assemblyPath = path.string();
	return true;
}
std::string GetGameAssemblyPathManual() {
	while (true) {
		std::string input = Input::ReadLine("Enter path to GameAssembly.dll: ");
		if (std::filesystem::exists(input)) {
			return input;
		}
		else {
			Output::Warn("Invalid path \"%s\"", input.c_str());
		}
	}
}
bool GetMetadataPath(const std::string& gamePath, std::string& metadataPath) {
	std::filesystem::path dataFolder;
	for (const auto& entry : std::filesystem::directory_iterator(gamePath)) {
		if (entry.is_directory() && entry.path().filename().string().ends_with("_Data")) {
			dataFolder = entry.path();
			break;
		}
	}
	if (dataFolder.empty()) {
		return false;
	}
	std::filesystem::path path(dataFolder);
	path /= "il2cpp_data\\Metadata\\global-metadata.dat";
	if (!std::filesystem::exists(path)) {
		return false;
	}
	metadataPath = path.string();
	return true;
}
std::string GetMetadataPathManual() {
	while (true) {
		std::string input = Input::ReadLine("Enter path to global-metadata.dat: ");
		if (std::filesystem::exists(input)) {
			return input;
		}
		else {
			Output::Warn("Invalid path \"%s\"", input.c_str());
		}
	}
}

bool IsMetadataSupported(int32_t version) {
	if (version < UDUMPER_MIN_METADATA_VERSION || version > UDUMPER_MAX_METADATA_VERSION) {
		return false;
	}
	return true;
}

void AnalyzeIl2Cpp(std::string gamePath) {
	// Find GameAssembly.dll
	std::string assemblyPath;
	if (!GetGameAssemblyPath(gamePath, assemblyPath)) {
		Output::Error("Failed to find GameAssembly.dll.");
		assemblyPath = GetGameAssemblyPathManual();
	}
	// Find global-metadata.dat
	std::string metadataPath;
	if (!GetMetadataPath(gamePath, metadataPath)) {
		Output::Error("Failed to find global-metadata.dat.");
		metadataPath = GetMetadataPathManual();
	}

	// Load metadata file
	MetadataFile globalMetadata;
	if (!globalMetadata.Load(metadataPath)) {
		Output::Fatal("Failed to load metadata file.", ERROR_FAIL_LOAD_METADATA);
	}
	int32_t version = globalMetadata.GetHeader().version.value;
	if (!IsMetadataSupported(version)) {
		Output::Fatal("Unsupported metadata version: %d", version, ERROR_UNSUPPORTED_METADATA);
	}
	Output::Log("Metadata loaded. Version: %d", version);
}
