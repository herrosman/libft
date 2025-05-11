#include "libft.h"

int ft_strequ(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return 0; // Return 0 if either string is NULL

    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return 0; // Return 0 if characters differ
        s1++;
        s2++;
    }

    return (*s1 == '\0' && *s2 == '\0'); // Return 1 if both strings end at the same time
}