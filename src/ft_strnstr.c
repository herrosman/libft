#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t needle_len;

    if (*needle == '\0') // If needle is empty, return haystack
        return (char *)haystack;

    needle_len = 0;
    while (needle[needle_len])
        needle_len++;

    while (*haystack && len >= needle_len)
    {
        i = 0;
        while (haystack[i] == needle[i] && needle[i])
            i++;
        if (i == needle_len)
            return (char *)haystack;
        haystack++;
        len--;
    }

    return NULL;
}