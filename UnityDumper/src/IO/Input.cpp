#include "Input.h"

#include <iostream>

#include <IO/Output.h>

std::string Input::ReadLine() {
	std::string line;
    std::getline(std::cin, line);
	return line;
}
std::string Input::ReadLine(const char* message) {
	Output::Write(FG_WHITE, message);
	return ReadLine();
}
