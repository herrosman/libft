#include "libft.h"

char    *ft_strcpy(char *dest, const char *src);

char    *ft_strcpy(char *dest, const char *src)
{
    int i;
    //char    *ptr; = dest;

    //ptr = dest;
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
        //src++;
    }
    dest[i] = '\0'; 
    return dest; 
}

int main() {
  
  char str1[20] = "C programming";
  char str2[20];

  // copying str1 to str2
  ft_strcpy(str2, str1);

  puts(str2); // C programming

  return 0;
}