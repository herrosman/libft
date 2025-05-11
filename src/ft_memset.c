#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr = (unsigned char *)b;
    size_t i = 0;

    // Set each byte in the memory block to the specified value
    while (i < len)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }

    return b;
}