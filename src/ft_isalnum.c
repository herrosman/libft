#include "libft.h"

int main(void)
{
    printf("%d", 'C');
    return 0;
}
int ft_isalnum(int c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}