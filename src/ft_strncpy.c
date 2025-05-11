#include "libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    // Copy up to n characters from src to dest
    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }

    // Fill the rest of dest with null bytes if src is shorter than n
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return dest;
}