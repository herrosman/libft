#include "libft.h"

void run_test(const char *haystack, const char *needle)
{
    char *std_result = strstr(haystack, needle);
    char *ft_result = ft_strstr(haystack, needle);

    printf("Haystack: \"%s\"\n", haystack);
    printf("Needle  : \"%s\"\n", needle);
    printf("strstr  : %s\n", std_result ? std_result : "(null)");
    printf("ft_strstr: %s\n", ft_result ? ft_result : "(null)");
    printf("Match?   : %s\n\n", (std_result == ft_result || (std_result && ft_result && strcmp(std_result, ft_result) == 0)) ? "YES" : "NO");
}

int main(void)
{
    // Basic match
    run_test("abcdef", "cd");

    // Needle at start
    run_test("abcdef", "ab");

    // Needle at end
    run_test("abcdef", "ef");

    // Needle not found
    run_test("abcdef", "gh");

    // Empty needle
    run_test("abcdef", "");

    // Empty haystack
    run_test("", "a");

    // Both empty
    run_test("", "");

    // Needle longer than haystack
    run_test("abc", "abcd");

    // Repeated characters
    run_test("aaaaaa", "aaa");

    // Needle is entire haystack
    run_test("abc", "abc");

    // Special characters
    run_test("a!@#b$%^c", "!@#");

    // Overlapping matches
    run_test("ababababa", "aba");

    return 0;
}

/* ft_strncpy - Copy a string with size limit
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to copy from src
 *
 * Returns a pointer to the destination string dest.
 
void print_strncpy_result(const char *test, char *mybuf, char *stdbuf, size_t n) {
    printf("%s (n=%zu)\n", test, n);
    printf("ft_strncpy:   \"%s\"\n", mybuf);
    printf("std strncpy:  \"%s\"\n", stdbuf);
    if (memcmp(mybuf, stdbuf, n) == 0)
        printf("PASS\n\n");
    else
        printf("FAIL\n\n");
}

int main(void) {
    // Test 1: Normal copy, n < src length
    char src1[] = "Hello, world!";
    char mybuf1[20] = {0};
    char stdbuf1[20] = {0};
    ft_strncpy(mybuf1, src1, 5);
    strncpy(stdbuf1, src1, 5);
    print_strncpy_result("Test 1: n < src length", mybuf1, stdbuf1, 5);

    // Test 2: n == src length
    char mybuf2[20] = {0};
    char stdbuf2[20] = {0};
    ft_strncpy(mybuf2, src1, 13);
    strncpy(stdbuf2, src1, 13);
    print_strncpy_result("Test 2: n == src length", mybuf2, stdbuf2, 13);

    // Test 3: n > src length
    char mybuf3[20] = {0};
    char stdbuf3[20] = {0};
    ft_strncpy(mybuf3, src1, 18);
    strncpy(stdbuf3, src1, 18);
    print_strncpy_result("Test 3: n > src length", mybuf3, stdbuf3, 18);

    // Test 4: src is empty
    char src4[] = "";
    char mybuf4[10] = {0};
    char stdbuf4[10] = {0};
    ft_strncpy(mybuf4, src4, 5);
    strncpy(stdbuf4, src4, 5);
    print_strncpy_result("Test 4: src empty", mybuf4, stdbuf4, 5);

    // Test 5: n = 0
    char mybuf5[10] = "abc";
    //char stdbuf5[10] = "abc";
    ft_strncpy(mybuf5, src1, 0);
    //strncpy(stdbuf5, src1, 0);
    //print_strncpy_result("Test 5: n = 0", mybuf5, stdbuf5, 0);

    // Test 6: dest and src overlap (undefined, but test anyway)
    char overlap[20] = "OverlapTest";
    ft_strncpy(overlap + 2, overlap, 5);
    printf("Test 6: overlap (manual check): \"%s\"\n", overlap);

    // Test 7: n = 1
    char mybuf7[10] = {0};
    char stdbuf7[10] = {0};
    ft_strncpy(mybuf7, src1, 1);
    strncpy(stdbuf7, src1, 1);
    print_strncpy_result("Test 7: n = 1", mybuf7, stdbuf7, 1);

    // Test 8: n = buffer size
    char mybuf8[10] = {0};
    char stdbuf8[10] = {0};
    ft_strncpy(mybuf8, "abc", sizeof(mybuf8));
    strncpy(stdbuf8, "abc", sizeof(mybuf8));
    print_strncpy_result("Test 8: n = buffer size", mybuf8, stdbuf8, sizeof(mybuf8));

    return 0;
}
*/
/* ft_strncat - Concatenate two strings with size limit
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to append from src
 *
 * Returns a pointer to the resulting string dest.
// Helper to print test results
void print_strncat_result(const char *test, char *mybuf, char *stdbuf) {
    printf("%s\n", test);
    printf("ft_strncat:   \"%s\"\n", mybuf);
    printf("std strncat:  \"%s\"\n", stdbuf);
    if (strcmp(mybuf, stdbuf) == 0)
        printf("PASS\n\n");
    else
        printf("FAIL\n\n");
}

int main(void)
{
    // Test 1: Normal concatenation
    char mybuf1[20] = "Hello";
    char stdbuf1[20] = "Hello";
    ft_strncat(mybuf1, " world", 5);
    strncat(stdbuf1, " world", 5);
    print_strncat_result("Test 1: Normal", mybuf1, stdbuf1);

    // Test 2: n = 0 (should not change dest)
    char mybuf2[20] = "Hello";
    char stdbuf2[20] = "Hello";
    ft_strncat(mybuf2, " world", 0);
    strncat(stdbuf2, " world", 0);
    print_strncat_result("Test 2: n = 0", mybuf2, stdbuf2);

    // Test 3: dest empty, n < src length
    char mybuf3[20] = "";
    char stdbuf3[20] = "";
    ft_strncat(mybuf3, "abcde", 3);
    strncat(stdbuf3, "abcde", 3);
    print_strncat_result("Test 3: dest empty, n < src", mybuf3, stdbuf3);

    // Test 4: n > src length
    char mybuf4[20] = "abc";
    char stdbuf4[20] = "abc";
    ft_strncat(mybuf4, "xy", 10);
    strncat(stdbuf4, "xy", 10);
    print_strncat_result("Test 4: n > src length", mybuf4, stdbuf4);

    // Test 5: n == src length
    char mybuf5[20] = "abc";
    //char stdbuf5[20] = "abc";
    ft_strncat(mybuf5, "xyz", 3);
    //strncat(stdbuf5, "xyz", 3);
    //print_strncat_result("Test 5: n == src length", mybuf5, stdbuf5);

    // Test 6: n == 1
    char mybuf6[20] = "abc";
    char stdbuf6[20] = "abc";
    ft_strncat(mybuf6, "def", 1);
    strncat(stdbuf6, "def", 1);
    print_strncat_result("Test 6: n == 1", mybuf6, stdbuf6);

    // Test 7: src is empty
    char mybuf7[20] = "abc";
    char stdbuf7[20] = "abc";
    ft_strncat(mybuf7, "", 5);
    strncat(stdbuf7, "", 5);
    print_strncat_result("Test 7: src empty", mybuf7, stdbuf7);

    // Test 8: dest is empty, src is empty
    char mybuf8[20] = "";
    char stdbuf8[20] = "";
    ft_strncat(mybuf8, "", 5);
    strncat(stdbuf8, "", 5);
    print_strncat_result("Test 8: both empty", mybuf8, stdbuf8);

    // Test 9: n = 0, src is empty
    char mybuf9[20] = "abc";
    char stdbuf9[20] = "abc";
    ft_strncat(mybuf9, "", 0);
    strncat(stdbuf9, "", 0);
    print_strncat_result("Test 9: n = 0, src empty", mybuf9, stdbuf9);

    // Test 10: n = 0, dest is empty
    char mybuf10[20] = "";
    char stdbuf10[20] = "";
    ft_strncat(mybuf10, "abc", 0);
    strncat(stdbuf10, "abc", 0);
    print_strncat_result("Test 10: n = 0, dest empty", mybuf10, stdbuf10);

    // Test 11: n = 1, src is empty
    char mybuf11[20] = "abc";
    char stdbuf11[20] = "abc";
    ft_strncat(mybuf11, "", 1);
    strncat(stdbuf11, "", 1);
    print_strncat_result("Test 11: n = 1, src empty", mybuf11, stdbuf11);

    // Test 12: n = 1, dest is empty
    char mybuf12[20] = "";
    //char stdbuf12[20] = "";
    ft_strncat(mybuf12, "a", 1);
    //strncat(stdbuf12, "a", 1);
    //print_strncat_result("Test 12: n = 1, dest empty", mybuf12, stdbuf12);

    // Test 13: n = strlen(src)
    char mybuf13[20] = "abc";
    //char stdbuf13[20] = "abc";
    ft_strncat(mybuf13, "def", strlen("def"));
    //strncat(stdbuf13, "def", strlen("def"));
    //print_strncat_result("Test 13: n = strlen(src)", mybuf13, stdbuf13);

    // Test 14: n > strlen(src)
    char mybuf14[20] = "abc";
    char stdbuf14[20] = "abc";
    ft_strncat(mybuf14, "gh", 10);
    strncat(stdbuf14, "gh", 10);
    print_strncat_result("Test 14: n > strlen(src)", mybuf14, stdbuf14);

    // Test 15: n = 0, both empty
    char mybuf15[20] = "";
    char stdbuf15[20] = "";
    ft_strncat(mybuf15, "", 0);
    strncat(stdbuf15, "", 0);
    print_strncat_result("Test 15: n = 0, both empty", mybuf15, stdbuf15);

    // Test 16: n = 1, both empty
    char mybuf16[20] = "";
    char stdbuf16[20] = "";
    ft_strncat(mybuf16, "", 1);
    strncat(stdbuf16, "", 1);
    print_strncat_result("Test 16: n = 1, both empty", mybuf16, stdbuf16);

    // Test 17: n = strlen(src) + 1
    char mybuf17[20] = "abc";
    char stdbuf17[20] = "abc";
    ft_strncat(mybuf17, "xy", 3);
    strncat(stdbuf17, "xy", 3);
    print_strncat_result("Test 17: n = strlen(src)+1", mybuf17, stdbuf17);

    // Test 18: n = strlen(src) - 1
    char mybuf18[20] = "abc";
    char stdbuf18[20] = "abc";
    ft_strncat(mybuf18, "xy", 1);
    strncat(stdbuf18, "xy", 1);
    print_strncat_result("Test 18: n = strlen(src)-1", mybuf18, stdbuf18);

    // Test 19: n = 100, src is short
    char mybuf19[20] = "abc";
    //char stdbuf19[20] = "abc";
    ft_strncat(mybuf19, "z", 100);
    //strncat(stdbuf19, "z", 100);
    //print_strncat_result("Test 19: n = 100, src short", mybuf19, stdbuf19);

    return 0;
}
*/
/* ft_strlcpy - Copy a string with size limit
 * @dest: Destination string
 * @src: Source string
 * @size: Size of the destination buffer
 *
 * Returns the total length of the string it tried to create.
 * If the size is not enough, it truncates the result.
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
/* ft_strlcat - Concatenate two strings with size limit
 * @dst: Destination string
 * @src: Source string
 * @size: Size of the destination buffer
 *
 * Returns the total length of the string it tried to create.
 * If the size is not enough, it truncates the result.
int main(void)
{
    char buf1[30] = "Hello";
    char buf2[10] = "Hi";
    char buf3[10] = "Hi";
    char buf4[10] = "";
    char buf5[5] = "1234";
    char buf6[10] = "abc";
    size_t ret;
	size_t exp;

    // Test 1: Normal concatenation, enough space
    ret = ft_strlcat(buf1, ", world!", sizeof(buf1));
	exp = ft_strlcat(buf1, ", world!", sizeof(buf1));
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
/* ft_strrchr - Find last occurrence of a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Returns a pointer to the last occurrence of c in s, or NULL if not found.

 void print_result(const char *test, char *result, char *expected) {
    printf("%s\n", test);
    printf("Result:   %s\n", result ? result : "NULL");
    printf("Expected: %s\n", expected ? expected : "NULL");
    printf("%s\n\n", (result == expected) ? "PASS (pointer match)" : 
           ((result && expected && strcmp(result, expected) == 0) ? "PASS (string match)" : "FAIL"));
}

int main(void) {
    char s1[] = "Hello, world!";
    char s2[] = "Hello, world!";
    char empty[] = "";
    char *res, *exp;

    // Test 1: Find existing character
    res = ft_strrchr(s1, 'w');
    exp = strrchr(s2, 'w');
    print_result("Test 1: Find 'w'", res, exp);

    // Test 2: Find first character
    res = ft_strrchr(s1, 'H');
    exp = strrchr(s2, 'H');
    print_result("Test 2: Find 'H'", res, exp);

    // Test 3: Find last character
    res = ft_strrchr(s1, '!');
    exp = strrchr(s2, '!');
    print_result("Test 3: Find '!'", res, exp);

    // Test 4: Find null terminator
    res = ft_strrchr(s1, '\0');
    exp = strrchr(s2, '\0');
    print_result("Test 4: Find '\\0'", res, exp);

    // Test 5: Character not present
    res = ft_strrchr(s1, 'z');
    exp = strrchr(s2, 'z');
    print_result("Test 5: Not present", res, exp);

    // Test 6: Empty string, search for '\0'
    res = ft_strrchr(empty, '\0');
    exp = strrchr(empty, '\0');
    print_result("Test 6: Empty string, '\\0'", res, exp);

    // Test 7: Empty string, search for 'a'
    res = ft_strrchr(empty, 'a');
    exp = strrchr(empty, 'a');
    print_result("Test 7: Empty string, 'a'", res, exp);

    // Test 8: Multiple occurrences, should return first
    char s3[] = "banana";
    char s4[] = "banana";
    res = ft_strrchr(s3, 'a');
    exp = strrchr(s4, 'a');
    print_result("Test 8: Multiple occurrences", res, exp);

    return 0;
}
*/