#include "libft.h"
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *new_str;
    unsigned int i;

    if (!s || !f)
        return NULL;

    // Allocate memory for the new string
    new_str = (char *)malloc(ft_strlen(s) + 1);
    if (!new_str)
        return NULL;

    // Apply the function to each character with its index
    i = 0;
    while (s[i])
    {
        new_str[i] = f(i, s[i]);
        i++;
    }
    new_str[i] = '\0'; // Null-terminate the new string

    return new_str;
}