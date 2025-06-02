#include "libft.h"

int main(void)
{
    printf("%d\n", ft_isascii(65));  // Should print 1 (A)
    printf("%d\n", ft_isascii(128)); // Should print 0 (not ASCII)
}
int ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}