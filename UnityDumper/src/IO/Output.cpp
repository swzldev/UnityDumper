#include "Output.h"

#ifdef _WIN32
# include <Windows.h>
#endif
#include <cstdarg>
#include <cstdio>

bool Output::Init() {
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		return false;
	}
	DWORD dwMode = 0;
	if (!GetConsoleMode(hConsole, &dwMode)) {
		return false;
	}
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hConsole, dwMode)) {
		return false;
	}
#endif
	return true;
}

void Output::Write(const char* color, const char* fmt, ...) {
	printf(color);
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf(RESET);
}
void Output::Log(const char* fmt, ...) {
	printf(FG_WHITE);
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf("\n");
	printf(RESET);
}
void Output::Warn(const char* fmt, ...) {
	printf(FG_YELLOW);
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf("\n");
	printf(RESET);
}
void Output::Error(const char* fmt, ...) {
	printf(FG_RED);
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf("\n");
	printf(RESET);
}
void Output::Fatal(const char* fmt, int exitCode, ...) {
	printf(FG_RED);
	printf("[FATAL ERROR]");
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf(RESET);
	printf("\nPress any key to exit...");
	int c = getchar();
	exit(exitCode);
}