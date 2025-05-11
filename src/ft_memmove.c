#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    size_t i;
    if (!dest && !src)
        return NULL;

    if (d < s)
    {
        // Copy forward
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        // Copy backward to handle overlap
        i = n;
        while (i > 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }

    }
    return dest;
}