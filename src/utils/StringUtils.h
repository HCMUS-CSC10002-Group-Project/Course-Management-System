#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <string>
#include "../data_structures/DynamicArray.h"

DynamicArray<string> split(const std::string &str, const char delimiter);

std::string join(const DynamicArray<string> &parts, const char delimiter);

#endif
