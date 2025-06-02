/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:47 by aosman            #+#    #+#             */
/*   Updated: 2025/06/02 16:50:05 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int main(void)
{
    char buf1[30] = "Hello";
    char buf2[10] = "Hi";
    char buf3[10] = "Hi";
    char buf4[10] = "";
    char buf5[5] = "1234";
    char buf6[10] = "abc";
    size_t ret;

    // Test 1: Normal concatenation, enough space
    ret = ft_strlcat(buf1, ", world!", sizeof(buf1));
    printf("Test 1: '%s' (ret=%zu)\n", buf1, ret);

    // Test 2: Truncation, not enough space
    ret = ft_strlcat(buf2, " there!", sizeof(buf2));
    printf("Test 2: '%s' (ret=%zu)\n", buf2, ret);

    // Test 3: Size = 0, should not write, just return
    ret = ft_strlcat(buf3, " there!", 0);
    printf("Test 3: '%s' (ret=%zu)\n", buf3, ret);

    // Test 4: Empty dest, normal src
    ret = ft_strlcat(buf4, "abc", sizeof(buf4));
    printf("Test 4: '%s' (ret=%zu)\n", buf4, ret);

    // Test 5: Empty src
    ret = ft_strlcat(buf5, "", sizeof(buf5));
    printf("Test 5: '%s' (ret=%zu)\n", buf5, ret);

    // Test 6: dest_len >= size (should not write)
    ret = ft_strlcat(buf6, "defghijkl", 3);
    printf("Test 6: '%s' (ret=%zu)\n", buf6, ret);

    // Test 7: Both src and dest empty
    char buf7[5] = "";
    ret = ft_strlcat(buf7, "", sizeof(buf7));
    printf("Test 7: '%s' (ret=%zu)\n", buf7, ret);

    // Test 8: size == dest_len + 1 (should copy one char + null)
    char buf8[6] = "abc";
    ret = ft_strlcat(buf8, "de", 4);
    printf("Test 8: '%s' (ret=%zu)\n", buf8, ret);

    return 0;
}
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t src_len;
	size_t dest_len;
	
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (src_len + size);
	if (size > dest_len + 1)
		ft_strlcpy(dest + dest_len, src, size - dest_len);
	else
		ft_strlcpy(dest + dest_len, src, size - 1);
	return (src_len + dest_len);
}
