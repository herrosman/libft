#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648) // Handle the edge case for INT_MIN
    {
        ft_putstr_fd("-2147483648", fd);
        return;
    }

    if (n < 0) // Handle negative numbers
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }

    if (n >= 10) // Recursively print digits
        ft_putnbr_fd(n / 10, fd);

    ft_putchar_fd((n % 10) + '0', fd); // Print the last digit
}