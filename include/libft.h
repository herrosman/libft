#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void    *ft_memset(void *str, int c, size_t n);
char    *ft_strcpy(char *dest, const char *src);
size_t  ft_strlen(const char *str);
char    *ft_strncpy(char *dest, const char *src, size_t n);
char    *ft_strdup( const char *str1 );
char    *strcat(char *dest_str, const char *src_str);
char    *ft_strncat(char *dest, const char *src, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size); 
char    *ft_strchr(const char *str, int search_str);


#endif