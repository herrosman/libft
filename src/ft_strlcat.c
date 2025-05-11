#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t dest_len = 0;
    size_t src_len = 0;
    size_t i = 0;

    // Calculate the length of dest and src
    while (dest[dest_len] && dest_len < size)
        dest_len++;
    while (src[src_len])
        src_len++;

    // If size is less than or equal to dest_len, return size + src_len
    if (size <= dest_len)
        return size + src_len;

    // Append src to dest while ensuring null-termination
    i = 0;
    while (src[i] && (dest_len + i) < (size - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';

    return dest_len + src_len;
}