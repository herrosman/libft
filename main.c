/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:57 by aosman            #+#    #+#             */
/*   Updated: 2025/06/05 22:05:04 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    // Test 1: Positive number to stdout
    printf("Test 1 (stdout, positive): ");
    ft_putnbr_fd(12345, 1);
    printf(" <- should see 12345\n");

    // Test 2: Negative number to stdout
    printf("Test 2 (stdout, negative): ");
    ft_putnbr_fd(-6789, 1);
    printf(" <- should see -6789\n");

    // Test 3: Zero
    printf("Test 3 (stdout, zero): ");
    ft_putnbr_fd(0, 1);
    printf(" <- should see 0\n");

    // Test 4: INT_MAX
    printf("Test 4 (stdout, INT_MAX): ");
    ft_putnbr_fd(2147483647, 1);
    printf(" <- should see 2147483647\n");

    // Test 5: INT_MIN
    printf("Test 5 (stdout, INT_MIN): ");
    ft_putnbr_fd(-2147483648, 1);
    printf(" <- should see -2147483648\n");

    // Test 6: Write to file using FILE* and fileno
    FILE *fptr = fopen("putnbr_test.txt", "w");
    if (fptr == NULL)
    {
        perror("fopen");
        return 1;
    }
    ft_putnbr_fd(424242, fileno(fptr));
    fclose(fptr);
    printf("Test 6 (file): Check 'putnbr_test.txt' for 424242\n");

    return 0;
}
/* * ft_putendl_fd - Write a string to a file descriptor followed by a newline
 * @s: The string to write
 * @fd: The file descriptor to write to
 *
 * This function writes the string s to the file descriptor fd, followed by a newline.
 
int main(void)
{
   char *str = "Hello, World!";
    // Test 1: Write to stdout
    printf("Test 1 (stdout): ");
    ft_putendl_fd(str, 1);
    printf(" <- should see 'A'\n");

    // Test 2: Write to stderr
    printf("Test 2 (stderr): ");
    ft_putendl_fd(str, 2);
    printf(" <- should see 'B' on stderr\n");

    // Test 3: Write to file using FILE* and fileno
    FILE *fptr = fopen("putchar_test.txt", "w");
    if (fptr == NULL)
    {
        perror("fopen");
        return 1;
    }
    ft_putendl_fd(str, fileno(fptr));
    fclose(fptr);
    printf("Test 3 (file): Check 'putchar_test.txt' for 'C'\n");

    return 0;
}
*/
/* ft_atoi - Convert a string to an integer
 * @nptr: The string to convert
 *
 * Returns the converted integer value.
 
#include "libft.h"

int main(void)
{
   int val, std;
   char *str; 
   str = "-150sdfg";
   val = ft_atoi(str); 
   std = atoi(str);
   printf("ft response : %d, atoi : %d\n", val, std);
}
*/
/* ft_memcmp - Compare two memory blocks
 * @s1: First memory block
 * @s2: Second memory block
 * @n: Number of bytes to compare
 *
 * Returns an integer less than, equal to, or greater than zero if the first n bytes
 * of s1 is found to be less than, equal to, or greater than the first n bytes of s2.
int main () 
{
   char str1[15];
   char str2[15];
   int ret, exp;

   ft_memcpy(str1, "ABZDEF", 6);
   ft_memcpy(str2, "ABZDEZ", 6);

   	ret = ft_memcmp(str1, str2, 6);
	exp =  memcmp(str1, str2, 6);
   
	
	printf("ft buffer : %i, stbuffer : %i\n", ret, exp);
	
	if(ret > 0) {
      printf("str2 is less than str1");
	} 
   else if(ret < 0) {
      printf("str1 is less than str2");
   } 
   else {
      printf("str1 is equal to str2");
   }
   return(0);
}
*/
/* ft_memchr - Locate a character in a memory block
 * @str: The memory block to search
 * @c: The character to find
 * @n: Number of bytes to search
 *
 * Returns a pointer to the first occurrence of c in the first n bytes of str, or NULL if not found.
int main(){
	const char str[] = "Tutorialspoint";
	const char str1[] = "Tutorialspoint";
   const char ch = 't';
   char *ret, *exp;
   ret = ft_memchr(str, ch, strlen(str));
   exp = ft_memchr(str1, ch, strlen(str1));
   printf("ft_memchr after |%c| is - |%s|\n", ch, ret);
   printf("memchr after |%c| is - |%s|\n", ch, exp);
   return(0);
}
*/
/*ft_memcpy - Copy memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Returns a pointer to the destination memory area dest.
int main(){
	char str[100] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string :%s\n ", str);
    
    // when overlap happens then it just ignore it
    memcpy(first + 8, first, 10);
    printf("memcpy overlap : %s\n ", str);

    // when overlap it start from first position
    memmove(second + 8, first, 10);
    printf("memmove overlap : %s\n ", str);

    return 0;
}*/
/* ft_memcopy - Copy memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Returns a pointer to the destination memory area dest.
 
void print_buffer(const char *label, unsigned char *buf, size_t n) {
    printf("%s: ", label);
    for (size_t i = 0; i < n; i++)
        printf("%02x ", buf[i]);
    printf("\n");
}

int main(void) {
    unsigned char src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned char dst1[10];
    unsigned char dst2[10];

    // Full copy
    ft_memcpy(dst1, src, 10);
    memcpy(dst2, src, 10);
    print_buffer("ft_memcpy", dst1, 10);
    print_buffer("memcpy", dst2, 10);
    if (memcmp(dst1, dst2, 10) == 0)
        printf("PASS: Full copy\n");
    else
        printf("FAIL: Full copy\n");

    // Partial copy
    for (int i = 0; i < 10; i++) dst1[i] = dst2[i] = 0xFF;
    ft_memcpy(dst1, src, 5);
    memcpy(dst2, src, 5);
    print_buffer("ft_memcpy (partial)", dst1, 10);
    print_buffer("memcpy (partial)", dst2, 10);
    if (memcmp(dst1, dst2, 10) == 0)
        printf("PASS: Partial copy\n");
    else
        printf("FAIL: Partial copy\n");

    // Zero length
    for (int i = 0; i < 10; i++) dst1[i] = dst2[i] = 0xAA;
    ft_memcpy(dst1, src, 0);
    memcpy(dst2, src, 0);
    if (memcmp(dst1, dst2, 10) == 0)
        printf("PASS: Zero length\n");
    else
        printf("FAIL: Zero length\n");

    // Self copy
    for (int i = 0; i < 10; i++) dst1[i] = i;
    ft_memcpy(dst1, dst1, 10);
    print_buffer("ft_memcpy (self)", dst1, 10);
    printf("PASS: Self copy (should be unchanged)\n");

    return 0;
}
*/
/* * ft_bzero - Set a block of memory to zero
 * @s: Pointer to the memory block
 * @n: Number of bytes to set to zero
 *
 * This function sets the first n bytes of the memory area pointed to by s to zero.

void print_buffer(const char *label, unsigned char *buf, size_t n) {
    printf("%s: ", label);
    for (size_t i = 0; i < n; i++)
        printf("%02x ", buf[i]);
    printf("\n");
}

int main(void) {
    unsigned char buf1[10];
    unsigned char buf2[10];

    // Fill buffers with non-zero values
    for (int i = 0; i < 10; i++) {
        buf1[i] = (unsigned char)(i + 1);
        buf2[i] = (unsigned char)(i + 1);
    }

    // Use ft_bzero and standard bzero
    ft_bzero(buf1, 10);
    memset(buf2, 0, 10);

    print_buffer("ft_bzero", buf1, 10);
    print_buffer("memset", buf2, 10);

    // Check if both buffers are zeroed
    if (memcmp(buf1, buf2, 10) == 0)
        printf("PASS: Buffers are zeroed correctly\n");
    else
        printf("FAIL: Buffers differ\n");

    // Partial zeroing
    for (int i = 0; i < 10; i++)
        buf1[i] = buf2[i] = (unsigned char)(i + 1);

    ft_bzero(buf1, 5);
    memset(buf2, 0, 5);

    print_buffer("ft_bzero (partial)", buf1, 10);
    print_buffer("memset (partial)", buf2, 10);

    if (memcmp(buf1, buf2, 10) == 0)
        printf("PASS: Partial zeroing works\n");
    else
        printf("FAIL: Partial zeroing failed\n");

    // Zero length
    for (int i = 0; i < 10; i++)
        buf1[i] = buf2[i] = (unsigned char)(i + 1);

    ft_bzero(buf1, 0);
    memset(buf2, 0, 0);

    if (memcmp(buf1, buf2, 10) == 0)
        printf("PASS: Zero length does nothing\n");
    else
        printf("FAIL: Zero length failed\n");

    return 0;
}
*/
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
    if (ft_strncmp(mybuf, stdbuf, n) == 0)
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
}*/
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
/*ft_putchar_fd.c
int main(void)
{
    // Test 1: Write to stdout
    printf("Test 1 (stdout): ");
    ft_putchar_fd('A', 1);
    printf(" <- should see 'A'\n");

    // Test 2: Write to stderr
    printf("Test 2 (stderr): ");
    ft_putchar_fd('B', 2);
    printf(" <- should see 'B' on stderr\n");

    // Test 3: Write to file using FILE* and fileno
    FILE *fptr = fopen("putchar_test.txt", "w");
    if (fptr == NULL)
    {
        perror("fopen");
        return 1;
    }
    ft_putchar_fd('C', fileno(fptr));
    fclose(fptr);
    printf("Test 3 (file): Check 'putchar_test.txt' for 'C'\n");

    return 0;
}*/
/*ft_calloc.c
void	test_ft_calloc(size_t nmemb, size_t size)
{
    size_t	i;
    int		pass = 1, std_pass = 1;
    unsigned char *ft_ptr = (unsigned char *)ft_calloc(nmemb, size);
    unsigned char *std_ptr = (unsigned char *)calloc(nmemb, size);

    // Check allocation result
    if (!ft_ptr && !std_ptr)
    {
        printf("ft_calloc(%zu, %zu): NULL | calloc: NULL (allocation failed)\n", nmemb, size);
        return;
    }
    if ((!ft_ptr && std_ptr) || (ft_ptr && !std_ptr))
    {
        printf("ft_calloc(%zu, %zu): %s | calloc: %s (MISMATCH in allocation)\n",
            nmemb, size,
            ft_ptr ? "NOT NULL" : "NULL",
            std_ptr ? "NOT NULL" : "NULL");
        if (ft_ptr) free(ft_ptr);
        if (std_ptr) free(std_ptr);
        return;
    }

    // Compare memory contents
    for (i = 0; i < nmemb * size; i++)
    {
        if (ft_ptr[i] != 0)
            pass = 0;
        if (std_ptr[i] != 0)
            std_pass = 0;
        if (ft_ptr[i] != std_ptr[i])
        {
            pass = 0;
            std_pass = 0;
            break;
        }
    }
    if (pass && std_pass)
        printf("ft_calloc(%zu, %zu): PASS (matches calloc, all bytes zero)\n", nmemb, size);
    else if (!pass && std_pass)
        printf("ft_calloc(%zu, %zu): FAIL (ft_calloc non-zero byte at %zu)\n", nmemb, size, i);
    else if (pass && !std_pass)
        printf("ft_calloc(%zu, %zu): FAIL (calloc non-zero byte at %zu)\n", nmemb, size, i);
    else
        printf("ft_calloc(%zu, %zu): FAIL (memory mismatch at %zu)\n", nmemb, size, i);

    free(ft_ptr);
    free(std_ptr);
}
*/
