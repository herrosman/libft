/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:47:29 by aosman            #+#    #+#             */
/*   Updated: 2025/06/03 12:06:54 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);

void    *ft_memset(void *str, int c, size_t n);
char    *ft_strcpy(char *dest, const char *src);
size_t   ft_strlen(const char *str);
char    *ft_strncpy(char *dest, const char *src, size_t n);
char    *ft_strdup( const char *str1 );
char    *strcat(char *dest_str, const char *src_str);
char    *ft_strncat(char *dest, const char *src, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size); 
char    *ft_strchr(const char *str, int search_str);
char    *ft_strrchr(const char *str, int search_str);
void    *ft_memset(void *str, int c, size_t n);
char    *ft_strcpy(char *dest, const char *src);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dest, const char *src, size_t size); 
size_t	ft_strlcat(char *dest, const char *src, size_t size);


#endif