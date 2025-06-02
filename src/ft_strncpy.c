#include "libft.h"

int main () {
   char source[] = "Hello, Note!";
   
   // Fixed length
   char destination[10]; 
   
   // Copy "Note!"
   ft_strncpy(destination, source + 7, 4); 

   printf("Copied substring: %s\n", destination);

   return(0);
}

char    *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t  i;

    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}