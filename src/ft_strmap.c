#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
    char *new_str;
    size_t i;

    if (!s || !f)
        return NULL;

    // Allocate memory for the new string
    new_str = (char *)malloc(ft_strlen(s) + 1);
    if (!new_str)
        return NULL;

    // Apply the function to each character
    i = 0;
    while (s[i])
    {
        new_str[i] = f(s[i]);
        i++;
    }
    new_str[i] = '\0'; // Null-terminate the new string

    return new_str;
}