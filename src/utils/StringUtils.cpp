#include "StringUtils.h"

DynamicArray<string> split(const std::string &str, const char delimiter)
{
    DynamicArray<string> parts;
    if (str == "")
    {
        return parts;
    }
    std::string part;

    for (char c : str)
    {
        if (c == delimiter)
        {
            parts.Add(part);
            part = "";
        }
        else
        {
            part += c;
        }
    }

    parts.Add(part);

    return parts;
}

std::string join(const DynamicArray<string> &parts, const char delimiter)
{
    std::string joined = "";
    for (int i = 0; i < parts.Size(); i++)
    {
        joined += parts.Get(i);
        if (i < parts.Size() - 1)
        {
            joined += delimiter;
        }
    }

    return joined;
}
