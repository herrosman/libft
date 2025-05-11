#include "libft.h"
#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;

    if (!s)
        return NULL;

    // Allocate memory for the substring (+1 for null terminator)
    sub = (char *)malloc(len + 1);
    if (!sub)
        return NULL;

    // Copy the substring
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0'; // Null-terminate the substring

    return sub;
}