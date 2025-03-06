#include "UnityBackend.h"

#include <filesystem>

#include <IO/Input.h>
#include <IO/Output.h>

UnityBackend GetUnityBackend(const char* gamePath) {
	std::filesystem::path path = gamePath;
	path /= "MonoBleedingEdge";
	if (std::filesystem::exists(path)) {
		return UNITY_BACKEND_MONO;
	}
	path = gamePath;
	path /= "GameAssembly.dll";
	if (std::filesystem::exists(path)) {
		return UNITY_BACKEND_IL2CPP;
	}
	return UNITY_BACKEND_UNKNOWN;
}
UnityBackend GetUnityBackendManual() {
	while (true) {
		std::string input = Input::ReadLine("Enter game backend (mono/il2cpp): ");
		if (input == "mono") {
			return UNITY_BACKEND_MONO;
		}
		else if (input == "il2cpp") {
			return UNITY_BACKEND_IL2CPP;
		}
		else {
			Output::Warn("Invalid backend \"%s\" (accepted: mono, il2cpp)", input.c_str());
		}
	}
}