#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>

void    *ft_memset(void *str, int c, size_t n);
char    *ft_strcpy(char *dest, const char *src);
int     ft_isalpha(int c);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dest, const char *src, size_t size); 
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int ft_isdigit(int c);
int	ft_isalnum(int c);
int ft_isascii(int c);

#endif