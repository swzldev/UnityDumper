#include <filesystem>

#include <UnityBackend.h>
#include <IO/Input.h>
#include <IO/Output.h>
#include <IL2CPP/Il2Cpp.h>
#include <Mono/Mono.h>

int main() {
	// Initialization
	Output::Init();

	// Get game backend
	std::string gamePath;
	while (true) {
		gamePath = Input::ReadLine("Enter game path: ");
		if (std::filesystem::exists(gamePath)) {
			break;
		}
		else {
			Output::Warn("Invalid path \"%s\"", gamePath.c_str());
		}
	}
	UnityBackend backend = GetUnityBackend(gamePath.c_str());
	if (backend == UNITY_BACKEND_UNKNOWN) {
		Output::Warn("Failed to detect game backend.");
		backend = GetUnityBackendManual();
	}
	else {
		Output::Log("Detected game backend: %s", backend == UNITY_BACKEND_MONO ? "Mono" : "Il2Cpp");
	}

	// Analyze game based on backend
	switch (backend) {
	case UNITY_BACKEND_MONO:
		// TODO: Implement Mono analysis
		//AnalyzeMono(gamePath);
		break;
	case UNITY_BACKEND_IL2CPP:
		AnalyzeIl2Cpp(gamePath);
		break;
	}
}