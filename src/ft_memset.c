#include "libft.h"



int main(void)
{
    char str[50];

    ft_strcpy(str, "Welcome to Tutorialspoint");
    puts(str);

    ft_memset(str, '#', 7);
    puts(str);
    return (0);
}

void *ft_memset(void *str, int c, size_t n)
{
    size_t i;
    unsigned char   *res;
    
    res = (unsigned char*)str;
    i = 0;
    while (i < n)
    {
        res[i] = (unsigned char)c;
        i++;
    }
    return str;
}