#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    const char *last_occurrence = NULL;

    while (*s)
    {
        if (*s == (char)c)
            last_occurrence = s;
        s++;
    }

    if (c == '\0') // Check for null terminator
        return (char *)s;

    return (char *)last_occurrence;
}