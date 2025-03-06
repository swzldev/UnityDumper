#pragma once

// ANSI color codes
constexpr auto BG_BLACK = "\033[40m";
constexpr auto BG_RED = "\033[41m";
constexpr auto BG_GREEN = "\033[42m";
constexpr auto BG_YELLOW = "\033[43m";
constexpr auto BG_BLUE = "\033[44m";
constexpr auto BG_MAGENTA = "\033[45m";
constexpr auto BG_CYAN = "\033[46m";
constexpr auto BG_WHITE = "\033[47m";
constexpr auto FG_BLACK = "\033[30m";
constexpr auto FG_RED = "\033[31m";
constexpr auto FG_GREEN = "\033[32m";
constexpr auto FG_YELLOW = "\033[33m";
constexpr auto FG_BLUE = "\033[34m";
constexpr auto FG_MAGENTA = "\033[35m";
constexpr auto FG_CYAN = "\033[36m";
constexpr auto FG_WHITE = "\033[37m";
constexpr auto RESET = "\033[0m";

// Error codes
constexpr auto ERROR_SUCCESS = 0;
constexpr auto ERROR_FAILURE = 1;
constexpr auto ERROR_FAIL_LOAD_METADATA = 2;
constexpr auto ERROR_UNSUPPORTED_METADATA = 3;
constexpr auto METADATA_CLASS_READ_FAIL = 4;

class Output
{
public:
	static bool Init();

	static void Write(const char* color, const char* fmt, ...);
	static void Log(const char* fmt, ...);
	static void Warn(const char* fmt, ...);
	static void Error(const char* fmt, ...);
	static void Fatal(const char* fmt, int exitCode, ...);
};