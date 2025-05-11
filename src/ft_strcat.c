#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
    char *d = dest;

    // Move the pointer to the end of the destination string
    while (*d)
        d++;

    // Append the source string to the destination string
    while (*src)
        *d++ = *src++;

    // Null-terminate the resulting string
    *d = '\0';

    return dest;
}