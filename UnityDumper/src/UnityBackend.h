#pragma once

enum UnityBackend {
	UNITY_BACKEND_UNKNOWN,
	UNITY_BACKEND_MONO,
	UNITY_BACKEND_IL2CPP
};

UnityBackend GetUnityBackend(const char* gamePath);
UnityBackend GetUnityBackendManual();