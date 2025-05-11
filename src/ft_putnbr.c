#include "libft.h"

void ft_putnbr(int n)
{
    if (n == -2147483648) // Handle the edge case for INT_MIN
    {
        ft_putstr("-2147483648");
        return;
    }

    if (n < 0) // Handle negative numbers
    {
        ft_putchar('-');
        n = -n;
    }

    if (n >= 10) // Recursively print digits
        ft_putnbr(n / 10);

    ft_putchar((n % 10) + '0'); // Print the last digit
}