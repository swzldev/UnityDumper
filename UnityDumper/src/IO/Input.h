#pragma once

#include <string>

class Input
{
public:
	static std::string ReadLine();
	static std::string ReadLine(const char* message);
};