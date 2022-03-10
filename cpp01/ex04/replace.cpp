#include "replace.hpp"

void    replace(std::string &str, const std::string to_find, const std::string to_replace)
{
    size_t found = 0;
    while (found != std::string::npos)
    {
        found = str.find(to_find, found + 1);
        if (found != std::string::npos)
        {
            str.erase(found, to_find.length());
            str.insert(found, to_replace);
        }
    }
}