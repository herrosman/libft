#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    if (!s1 || !s2)
        return 0; // Return 0 if either string is NULL

    while (n > 0 && *s1 && *s2)
    {
        if (*s1 != *s2)
            return 0; // Return 0 if characters differ
        s1++;
        s2++;
        n--;
    }

    if (n == 0)
        return 1; // Return 1 if n characters are identical
    return (*s1 == '\0' && *s2 == '\0'); // Return 1 if both strings end at the same time
}