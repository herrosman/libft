#include "libft.h"

void ft_putendl(char const *s)
{
    if (!s)
        return;

    while (*s)
    {
        ft_putchar(*s); // Output each character of the string
        s++;
    }
    ft_putchar('\n'); // Output a newline character
}