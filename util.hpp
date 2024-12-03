
#include <iostream>
#include <sstream>
#include <string>

std::string indent_output(const std::string &prefix, const std::function<void()> &print_func);
std::string to_lower(const std::string &str);