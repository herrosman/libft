#include "libft.h"

char *ft_strcpy(char *dest, const char *src)
{
    int i = 0;

    // Copy each character from src to dest
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }

    // Add null terminator to the destination string
    dest[i] = '\0';

    return dest;
}