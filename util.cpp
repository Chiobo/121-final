#pragma once

#include <iostream>
#include <sstream>
#include <string>

std::string indent_output(const std::string &prefix, const std::function<void()> &print_func)
{
	// Capture the output
	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
	print_func();
	std::cout.rdbuf(old);

	// Add indentation to each line
	std::stringstream result;
	std::string line;
	while (std::getline(buffer, line))
	{
		result << prefix << line << std::endl;
	}
	return result.str();
}