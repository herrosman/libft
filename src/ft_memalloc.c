#include "libft.h"

void *ft_memalloc(size_t size)
{
    void *memory;

    memory = (void *)malloc(size * sizeof(memory));
    if (!memory)
        return NULL;

    // Initialize the allocated memory to 0
    ft_bzero(memory, size);

    return memory;
}