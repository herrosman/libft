#include "libft.h"

int main() {
   char dest_str[50] = "C ";
   const char src_str[] = "JAVA";

   // Concatenate src_str to dest_str
   strcat(dest_str, src_str);

   // The result store in destination string
   printf("Result :%s\n", dest_str); 
   return 0;
}


char *strcat(char *dest, const char *src)
{
    char *ptr = dest;

    
    while (*ptr != '\0') {
        ptr++;
    }

   
    while (*src != '\0') {
        *ptr++ = *src++;
        //ptr++;
        //src++;
    }

    // Null-terminate the concatenated string
    *ptr = '\0';

    return dest;
}