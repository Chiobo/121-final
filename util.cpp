#pragma once

#include <iostream>
#include <sstream>
#include <string>

// Utility function to indent following lines for std (useful when logging multiple objects or contextualizi8ng)
std::string indent_output(const std::string &prefix, const std::function<void()> &print_func)
{
	// Capture the output; we store std::cout in a buffer
	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
	print_func();
	std::cout.rdbuf(old);

	// Add indentation to each line
	std::stringstream result;
	std::string line;
	while (std::getline(buffer, line))
	{
		// Iterate over the buffer adding prefix to the start of the line
		result << prefix << line << std::endl;
	}

	return result.str();
}

// Utility function to convert a string to lowercase
std::string to_lower(const std::string &str)
{
	// Copy string
	std::string lower_str = str;
	// Apply the <string> tolower function to each character in the string
	std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
	return lower_str;
}