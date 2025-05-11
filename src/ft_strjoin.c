#include "libft.h"
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    char *joined_str;
    size_t len1;
    size_t len2;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return NULL;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    // Allocate memory for the concatenated string (+1 for null terminator)
    joined_str = (char *)malloc(len1 + len2 + 1);
    if (!joined_str)
        return NULL;

    // Copy s1 into the new string
    i = 0;
    while (i < len1)
    {
        joined_str[i] = s1[i];
        i++;
    }

    // Copy s2 into the new string
    j = 0;

    while (j < len2)
    {
        joined_str[i] = s2[j];
        i++;
        j++;
    }
    
    joined_str[i] = '\0'; // Null-terminate the string

    return joined_str;
}