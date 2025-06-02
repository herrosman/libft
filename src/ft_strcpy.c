#include "libft.h"
/*
int main() {
  
  char str1[20] = "C programming";
  char str2[20];

  ft_strcpy(str2, str1);

  puts(str2); 

  return 0;
}
*/
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