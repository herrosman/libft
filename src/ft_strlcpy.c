/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:47 by aosman            #+#    #+#             */
/*   Updated: 2025/06/02 15:38:38 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int main(void)
{
    char src1[] = "Hello, world!";
    char dest1[20];
    char dest2[5];
    char dest3[1];
    char dest4[20] = "Initial";
    size_t ret;

    // Test 1: Normal copy, dest larger than src
    ret = ft_strlcpy(dest1, src1, sizeof(dest1));
    printf("Test 1: '%s' (ret=%zu)\n", dest1, ret);

    // Test 2: Copy with truncation
    ret = ft_strlcpy(dest2, src1, sizeof(dest2));
    printf("Test 2: '%s' (ret=%zu)\n", dest2, ret);

    // Test 3: Copy with size = 1 (should only null-terminate)
    ret = ft_strlcpy(dest3, src1, sizeof(dest3));
    printf("Test 3: '%s' (ret=%zu)\n", dest3, ret);

    // Test 4: Copy with size = 0 (should not write, just return length)
    ret = ft_strlcpy(dest4, src1, 0);
    printf("Test 4: '%s' (ret=%zu)\n", dest4, ret);

    // Test 5: Empty src
    char src_empty[] = "";
    char dest5[10] = "abc";
    ret = ft_strlcpy(dest5, src_empty, sizeof(dest5));
    printf("Test 5: '%s' (ret=%zu)\n", dest5, ret);

    return 0;
}
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	i = 0;
	while (src[i] && i < (size -1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (s_len);
}