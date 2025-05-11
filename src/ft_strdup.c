#include "libft.h"

char *ft_strdup(const char *s)
{
    char *dup;
    int len = 0;
    int i = 0;

    // Calculate the length of the input string
    while (s[len])
        len++;

    // Allocate memory for the duplicate string
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);

    // Copy the characters from the input string to the duplicate
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';

    return (dup);
}