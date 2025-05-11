#include "libft.h"

char *ft_strnew(size_t size)
{
    char *str;

    str = (char *)malloc(size + 1); // Allocate memory for the string + null terminator
    if (!str)
        return NULL;

    // Initialize all characters to '\0'
    ft_bzero(str, size + 1);

    return str;
}