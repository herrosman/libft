#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s)
{
    size_t start;
    size_t end;
    char *trimmed_str;

    if (!s)
        return NULL;

    // Find the start index (skip leading whitespaces)
    start = 0;
    while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
        start++;

    // If the string is entirely whitespace, return an empty string
    if (s[start] == '\0')
        return ft_strdup("");

    // Find the end index (skip trailing whitespaces)
    end = ft_strlen(s) - 1;
    while (end > start && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
        end--;

    // Allocate memory for the trimmed string
    trimmed_str = ft_strsub(s, start, end - start + 1);
    return trimmed_str;
}