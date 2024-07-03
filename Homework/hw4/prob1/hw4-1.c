#include <stdio.h>

int hw4_islower(int ch)
{
    return ch >= 'a' && ch <= 'z';
}

int hw4_isupper(int ch)
{
    return ch >= 'A' && ch <= 'Z';
}

int hw4_isalpha(int ch)
{
    return hw4_islower(ch) || hw4_isupper(ch);
}

int hw4_isdigit(int ch)
{
    return ch >= '0' && ch <= '9';
}

int hw4_tolower(int ch)
{
    if (hw4_isupper(ch))
    {
        return ch - 'A' + 'a';
    }
    return ch;
}

int hw4_toupper(int ch)
{
    if (hw4_islower(ch))
    {
        return ch - 'a' + 'A';
    }
    return ch;
}

size_t hw4_strlen(const char *str)
{
    size_t count = 0;
    while (*str)
    {
        str++;
        count++;
    }
    return count;
}

char *hw4_strchr(const char *str, int ch)
{
    while (*str)
    {
        if (*str == ch)
        {
            return (char *)str;
        }
        str++;
    }
    if (!ch)
    {
        return (char *)str;
    }
    return NULL;
}

char *hw4_strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return tmp;
}

char *hw4_strcat(char *dest, const char *src)
{
    char *tmp = dest;
    while (*dest)
    {
        dest++;
    }
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return tmp;
}

int hw4_strcmp(const char *lhs, const char *rhs)
{
    while ((*lhs) && (*lhs == *rhs))
    {
        lhs++;
        rhs++;
    }

    if ((unsigned char)*lhs > (unsigned char)*rhs)
    {
        return 1;
    }
    else if ((unsigned char)*lhs < (unsigned char)*rhs)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}