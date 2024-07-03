#include <iostream>
#include <string>
#include <vector>
#include "assert.h"

std::string strip(const std::string &str)
{
    if (!str.empty())
    {
        size_t i = 0;
        size_t j = str.size() - 1;
        while (i <= j && std::isspace(str.at(i)))
        {
            i++;
        }
        while (j >= i && std::isspace(str.at(j)))
        {
            j--;
        }
        return str.substr(i, j - i + 1);
    }
    return "";
}

std::string join(const std::string &sep, const std::vector<std::string> &strings)
{
    size_t len = strings.size();
    if (len)
    {
        std::string str = strings.at(0);
        for (size_t i = 1; i < len; i++)
        {
            str += sep;
            str += strings.at(i);
        }
        return str;
    }
    return "";
}

std::vector<std::string> split(const std::string &str, const std::string &sep)
{
    if (!str.empty())
    {
        std::vector<std::string> strings;
        size_t strlen = str.size();
        size_t seplen = sep.size();
        size_t flag1, flag2;
        flag2 = str.find(sep);
        flag1 = 0;
        while (flag2 < strlen)
        {
            strings.push_back(str.substr(flag1, flag2 - flag1));
            flag1 = flag2 + seplen;
            flag2 = str.find(sep, flag1);
        }
        strings.push_back(str.substr(flag1));
        return strings;
    }
    return {""};
}

std::string swapcase(std::string str)
{
    for (char &c : str)
    {
        if (islower(c))
        {
            c = toupper(c);
        }
        else if (isupper(c))
        {
            c = tolower(c);
        }
    }
    return str;
}