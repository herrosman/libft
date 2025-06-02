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