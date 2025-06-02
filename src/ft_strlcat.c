<<<<<<< HEAD
#include "libft.h"
size_t ref_strlcat(char *dst, const char *src, size_t size) {
    size_t dlen = strlen(dst);
    size_t slen = strlen(src);
    size_t i;

    if (size <= dlen)
        return size + slen;
    for (i = 0; src[i] && dlen + i < size - 1; i++)
        dst[dlen + i] = src[i];
    if (dlen < size)
        dst[dlen + i] = '\0';
    return dlen + slen;
}

void print_result(const char *test, const char *dst, size_t ret, const char *expected_dst, size_t expected_ret) {
    printf("%s\n", test);
    printf("Result:   \"%s\" (ret = %zu)\n", dst, ret);
    printf("Expected: \"%s\" (ret = %zu)\n", expected_dst, expected_ret);
    printf("%s\n\n", (strcmp(dst, expected_dst) == 0 && ret == expected_ret) ? "PASS" : "FAIL");
}

int main(void) {
    char buf[20], buf2[20];
    size_t ret, expected;

    // Test 1: Normal concatenation
    strcpy(buf, "Hello");
    strcpy(buf2, "Hello");
    ret = ft_strlcat(buf, " World", sizeof(buf));
    expected = ref_strlcat(buf2, " World", sizeof(buf2));
    print_result("Test 1: Normal concatenation", buf, ret, buf2, expected);

    // Test 2: No space to concatenate
    strcpy(buf, "Hello");
    strcpy(buf2, "Hello");
    ret = ft_strlcat(buf, " World", 6);
    expected = ref_strlcat(buf2, " World", 6);
    print_result("Test 2: No space to concatenate", buf, ret, buf2, expected);

    // Test 3: Zero size
    strcpy(buf, "Hello");
    strcpy(buf2, "Hello");
    ret = ft_strlcat(buf, " World", 0);
    expected = ref_strlcat(buf2, " World", 0);
    print_result("Test 3: Zero size", buf, ret, buf2, expected);

    // Test 4: Empty src
    strcpy(buf, "Hello");
    strcpy(buf2, "Hello");
    ret = ft_strlcat(buf, "", sizeof(buf));
    expected = ref_strlcat(buf2, "", sizeof(buf2));
    print_result("Test 4: Empty src", buf, ret, buf2, expected);

    // Test 5: Empty dst
    buf[0] = '\0';
    buf2[0] = '\0';
    ret = ft_strlcat(buf, "World", sizeof(buf));
    expected = ref_strlcat(buf2, "World", sizeof(buf2));
    print_result("Test 5: Empty dst", buf, ret, buf2, expected);

    // Test 6: dst buffer size is 1
    strcpy(buf, "A");
    strcpy(buf2, "A");
    ret = ft_strlcat(buf, "BC", 1);
    expected = ref_strlcat(buf2, "BC", 1);
    print_result("Test 6: dst buffer size is 1", buf, ret, buf2, expected);

    // Test 7: dst buffer size is less than dst length
    strcpy(buf, "Hello");
    strcpy(buf2, "Hello");
    ret = ft_strlcat(buf, "World", 3);
    expected = ref_strlcat(buf2, "World", 3);
    print_result("Test 7: dst buffer size < dst length", buf, ret, buf2, expected);

    return 0;
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  dst_len;
    size_t  src_len;
    size_t  i;

    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    
    if (size <= dst_len)
        return (dst_len + src_len);

    i = 0;
    while (src[i] && (dst_len + i < size - 1))
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    
    dst[dst_len + i] = '\0';
    
    return (dst_len + src_len);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:47 by aosman            #+#    #+#             */
/*   Updated: 2025/06/02 16:54:09 by aosman           ###   ########.fr       */
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
	size_t	src_len;
	size_t	dest_len;

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
>>>>>>> 48ddb8441c309675ff5ccdcc7ef275d05cb97fe2
