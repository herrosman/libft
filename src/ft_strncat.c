#include "libft.h"

int main()
{
  
   // Take any two strings
   char src[50] = "efghijkl";
   char dest[50]= "abcd";
 
   // Appends 5 character from src to dest
   strncat(dest, src, 5);
    
   // Prints the string
   printf("Source string : %s\n", src);
   printf("Destination string : %s\n", dest);
   
   return 0;
}

char *ft_strncat(char *dest, const char *src, size_t n)
{
    char    *ptr;
    size_t    i;

    ptr = dest;
    while (*ptr)
        ptr++;

    while (*src && i < n)
    {
        *ptr++ = *src++;
        i++;
    }
    *ptr = '\0';
    return dest;
}