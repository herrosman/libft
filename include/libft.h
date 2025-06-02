#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

<<<<<<< HEAD

void    *ft_memset(void *str, int c, size_t n);
char    *ft_strcpy(char *dest, const char *src);
size_t  ft_strlen(const char *str);
char    *ft_strncpy(char *dest, const char *src, size_t n);
char    *ft_strdup( const char *str1 );
char    *strcat(char *dest_str, const char *src_str);
char    *ft_strncat(char *dest, const char *src, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size); 
char    *ft_strchr(const char *str, int search_str);

=======
void    *ft_memset(void *str, int c, size_t n);
char    *ft_strcpy(char *dest, const char *src);
int     ft_isalpha(int c);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dest, const char *src, size_t size); 
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int ft_isdigit(int c);
int	ft_isalnum(int c);
int ft_isascii(int c);
>>>>>>> 48ddb8441c309675ff5ccdcc7ef275d05cb97fe2

#endif