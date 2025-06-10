/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:57 by aosman            #+#    #+#             */
/*   Updated: 2025/06/09 22:23:20 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**/
static char *my_strnstr(const char *haystack, const char *needle, size_t len) {
    size_t i, j;
    if (!*needle)
        return (char *)haystack;
    for (i = 0; haystack[i] && i < len; i++) {
        for (j = 0; needle[j] && (i + j) < len && haystack[i + j] == needle[j]; j++);
        if (!needle[j])
            return (char *)(haystack + i);
    }
    return NULL;
}

void print_strnstr_result(const char *desc, const char *haystack, const char *needle, size_t n, char *ft_ret, char *std_ret) {
    printf("%s\n", desc);
    printf("ft_strnstr(\"%s\", \"%s\", %zu) = %s\n", haystack, needle, n, ft_ret ? ft_ret : "NULL");
    printf("my_strnstr (\"%s\", \"%s\", %zu) = %s\n", haystack, needle, n, std_ret ? std_ret : "NULL");
    if ((ft_ret == NULL && std_ret == NULL) ||
        (ft_ret && std_ret && (ft_strncmp(ft_ret, std_ret, ft_strlen(std_ret)) == 0 && (ft_ret - haystack) == (std_ret - haystack))))
        printf("PASS\n\n");
    else
        printf("FAIL\n\n");
}

void test_ft_strnstr() {
    // Found at start
    print_strnstr_result("Test 1: Found at start", "abcdef", "abc", 6, ft_strnstr("abcdef", "abc", 6), my_strnstr("abcdef", "abc", 6));
    // Found in middle
    print_strnstr_result("Test 2: Found in middle", "abcdef", "cd", 6, ft_strnstr("abcdef", "cd", 6), my_strnstr("abcdef", "cd", 6));
    // Found at end
    print_strnstr_result("Test 3: Found at end", "abcdef", "ef", 6, ft_strnstr("abcdef", "ef", 6), my_strnstr("abcdef", "ef", 6));
    // Not found
    print_strnstr_result("Test 4: Not found", "abcdef", "gh", 6, ft_strnstr("abcdef", "gh", 6), my_strnstr("abcdef", "gh", 6));
    // Empty needle
    print_strnstr_result("Test 5: Empty needle", "abcdef", "", 6, ft_strnstr("abcdef", "", 6), my_strnstr("abcdef", "", 6));
    // Empty haystack
    print_strnstr_result("Test 6: Empty haystack", "", "a", 1, ft_strnstr("", "a", 1), my_strnstr("", "a", 1));
    // n = 0
    print_strnstr_result("Test 7: n = 0", "abcdef", "abc", 0, ft_strnstr("abcdef", "abc", 0), my_strnstr("abcdef", "abc", 0));
    // n < haystack length, match after n
    print_strnstr_result("Test 8: n < haystack, match after n", "abcdef", "ef", 4, ft_strnstr("abcdef", "ef", 4), my_strnstr("abcdef", "ef", 4));
    // n == haystack length
    print_strnstr_result("Test 9: n == haystack", "abcdef", "def", 6, ft_strnstr("abcdef", "def", 6), my_strnstr("abcdef", "def", 6));
    // n > haystack length
    print_strnstr_result("Test 10: n > haystack", "abcdef", "def", 10, ft_strnstr("abcdef", "def", 10), my_strnstr("abcdef", "def", 10));
    // Needle longer than haystack
    print_strnstr_result("Test 11: Needle longer than haystack", "abc", "abcdef", 6, ft_strnstr("abc", "abcdef", 6), my_strnstr("abc", "abcdef", 6));
    // Needle partially matches at end
    print_strnstr_result("Test 12: Partial match at end", "abcdef", "efg", 6, ft_strnstr("abcdef", "efg", 6), my_strnstr("abcdef", "efg", 6));
    // Embedded nulls
    char h1[] = {'a', 'b', '\0', 'c', 'd', 0};
    char n1[] = {'\0', 'c', 0};
    print_strnstr_result("Test 13: Embedded nulls", h1, n1, 5, ft_strnstr(h1, n1, 5), my_strnstr(h1, n1, 5));
}

int main(void) {
    test_ft_strnstr();
    return 0;
}
/* * ft_strncmp - Compare two strings up to n characters
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 *
 * Returns an integer less than, equal to, or greater than zero if the first n
 * characters of s1 is found to be less than, equal to, or greater than the first n
 * characters of s2.
 
void print_strncmp_result(const char *desc, const char *s1, const char *s2, size_t n, int ft_ret, int std_ret) {
	printf("%s\n", desc);
	printf("ft_strncmp(\"%s\", \"%s\", %zu) = %d\n", s1, s2, n, ft_ret);
	printf("strncmp   (\"%s\", \"%s\", %zu) = %d\n", s1, s2, n, std_ret);
	if ((ft_ret == 0 && std_ret == 0) || (ft_ret < 0 && std_ret < 0) || (ft_ret > 0 && std_ret > 0))
		printf("PASS\n\n");
	else
		printf("FAIL\n\n");
}

void test_ft_strncmp() {
	// Identical strings, n < strlen
	print_strncmp_result("Test 1: Identical, n < strlen", "abcdef", "abcdef", 3, ft_strncmp("abcdef", "abcdef", 3), strncmp("abcdef", "abcdef", 3));
	// Identical strings, n == strlen
	print_strncmp_result("Test 2: Identical, n == strlen", "abcdef", "abcdef", 6, ft_strncmp("abcdef", "abcdef", 6), strncmp("abcdef", "abcdef", 6));
	// Identical strings, n > strlen
	print_strncmp_result("Test 3: Identical, n > strlen", "abc", "abc", 10, ft_strncmp("abc", "abc", 10), strncmp("abc", "abc", 10));
	// Differ at start
	print_strncmp_result("Test 4: Differ at start", "xbcdef", "abcdef", 6, ft_strncmp("xbcdef", "abcdef", 6), strncmp("xbcdef", "abcdef", 6));
	// Differ in middle
	print_strncmp_result("Test 5: Differ in middle", "abxdef", "abcdef", 6, ft_strncmp("abxdef", "abcdef", 6), strncmp("abxdef", "abcdef", 6));
	// Differ at end
	print_strncmp_result("Test 6: Differ at end", "abcdez", "abcdef", 6, ft_strncmp("abcdez", "abcdef", 6), strncmp("abcdez", "abcdef", 6));
	// n = 0
	print_strncmp_result("Test 7: n = 0", "abc", "xyz", 0, ft_strncmp("abc", "xyz", 0), strncmp("abc", "xyz", 0));
	// One empty, one not
	print_strncmp_result("Test 8: One empty", "", "abc", 3, ft_strncmp("", "abc", 3), strncmp("", "abc", 3));
	print_strncmp_result("Test 9: One empty", "abc", "", 3, ft_strncmp("abc", "", 3), strncmp("abc", "", 3));
	// Both empty
	print_strncmp_result("Test 10: Both empty", "", "", 3, ft_strncmp("", "", 3), strncmp("", "", 3));
	// Embedded nulls
	print_strncmp_result("Test 11: Embedded nulls", "ab\0cd", "ab\0ef", 5, ft_strncmp("ab\0cd", "ab\0ef", 5), strncmp("ab\0cd", "ab\0ef", 5));
	print_strncmp_result("Test 12: Embedded nulls identical", "ab\0cd", "ab\0cd", 5, ft_strncmp("ab\0cd", "ab\0cd", 5), strncmp("ab\0cd", "ab\0cd", 5));
	// Non-ASCII
	char s1[] = {'a', (char)0x80, 'c', 0};
	char s2[] = {'a', (char)0x81, 'c', 0};
	print_strncmp_result("Test 13: Non-ASCII", s1, s2, 3, ft_strncmp(s1, s2, 3), strncmp(s1, s2, 3));
	// n > length of one string
	print_strncmp_result("Test 14: n > strlen(s1)", "abc", "abcdef", 6, ft_strncmp("abc", "abcdef", 6), strncmp("abc", "abcdef", 6));
	print_strncmp_result("Test 15: n > strlen(s2)", "abcdef", "abc", 6, ft_strncmp("abcdef", "abc", 6), strncmp("abcdef", "abc", 6));
}

int main(void) {
	test_ft_strncmp();
	return 0;
}
*/
/* * ft_atoi - Convert a string to an integer
 * @str: The string to convert
 *
 * Returns the converted integer.
 * If the string is NULL, returns 0.
 * Handles leading/trailing whitespace, signs, and non-digit characters.
 
#include <limits.h>

void test_ft_atoi(const char *str)
{
	//printf("Testing ft_atoi with input: \"%s\"\n", str ? str : "NULL");
    int ft = ft_atoi(str);
    int std = atoi(str);
    int pass = (ft == std);
    printf("ft_atoi(\"%s\") = %d | atoi = %d | %s\n",
        str ? str : "NULL", ft, std, pass ? "PASS" : "FAIL");
}

int main(void)
{
    // Basic numbers
    test_ft_atoi("0");
    test_ft_atoi("42");
    test_ft_atoi("-42");
    test_ft_atoi("+42");
    test_ft_atoi("2147483647"); // INT_MAX
    test_ft_atoi("-2147483648"); // INT_MIN

    // Leading/trailing spaces
    test_ft_atoi("   123");
    test_ft_atoi("\t\n\v\f\r 456");
    test_ft_atoi("789   ");
    test_ft_atoi("   -987   ");

    // Leading zeros
    test_ft_atoi("0000123");
    test_ft_atoi("-0000123");

    // Only sign
    test_ft_atoi("+");
    test_ft_atoi("-");

    // Empty string
    test_ft_atoi("");
    test_ft_atoi("   ");

    // Non-digit after number
    test_ft_atoi("123abc");
    test_ft_atoi("-42xyz");
    test_ft_atoi("  +7seven");

    // Multiple signs
    test_ft_atoi("--42");
    test_ft_atoi("++42");
    test_ft_atoi("+-42");
    test_ft_atoi("-+42");

    // No digits
    test_ft_atoi("abc");
    test_ft_atoi("   abc");
    test_ft_atoi("++--");

    // Embedded nulls
    test_ft_atoi("12\034");
    test_ft_atoi("  56\0 78");

    // Overflow/underflow
    test_ft_atoi("2147483648");
    test_ft_atoi("-2147483649");
    test_ft_atoi("999999999999999999999");
    test_ft_atoi("-999999999999999999999");

    // Edge: NULL pointer (if your ft_atoi handles it)
    // test_ft_atoi(NULL);

    return 0;
}
*/
/* ft_striteri - Apply a function to each character of a string with index
 * @s: The string to iterate
 * @f: The function to apply
 *
 * This function applies the function f to each character of the string s,
 * passing the index of the character as the first argument and a pointer to
 * the character as the second argument.
 
void to_upper_even_i(unsigned int i, char *c) {
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void add_index_i(unsigned int i, char *c) {
    *c = *c + i;
}

void nullify_all(unsigned int i, char *c) {
    (void)i;
    *c = '\0';
}

void test_ft_striteri(char *input, void (*f)(unsigned int, char*), const char *expected, const char *desc) {
    char buf[128];
    if (input)
        strncpy(buf, input, sizeof(buf));
    else
        buf[0] = '\0';
    buf[sizeof(buf) - 1] = '\0';

    ft_striteri(input ? buf : NULL, f);
    int pass = (expected == NULL && (input == NULL || buf[0] == '\0')) ||
               (expected && strcmp(buf, expected) == 0);
    printf("ft_striteri(%s): \"%s\" | expected: \"%s\" | %s (%s)\n",
           input ? input : "NULL", buf, expected ? expected : "NULL",
           pass ? "PASS" : "FAIL", desc);
}

int main(void)
{
    test_ft_striteri("abcdef", to_upper_even_i, "AbCdEf", "Uppercase even indices");
    test_ft_striteri("abc", add_index_i, "ace", "Add index to char");
    test_ft_striteri("", to_upper_even_i, "", "Empty string");
    test_ft_striteri(NULL, to_upper_even_i, NULL, "NULL input");
    test_ft_striteri("xyz", NULL, "xyz", "NULL function pointer (should do nothing)");
    test_ft_striteri("test", nullify_all, "", "Nullify all chars");
    test_ft_striteri("A", to_upper_even_i, "A", "Single char");
    test_ft_striteri("a", to_upper_even_i, "A", "Single lowercase char");
    test_ft_striteri("123", add_index_i, "135", "Digits with index");
    return 0;
}
*/
/*  * ft_strmapi - Apply a function to each character of a string
 * @s: The string to map
 * @f: The function to apply
 *
 * Returns a newly allocated string with the results of applying f to each character of s.
 * The caller is responsible for freeing the returned string.
 * 
char to_upper_even(unsigned int i, char c) {
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char add_index(unsigned int i, char c) {
    return c + i;
}

void test_ft_strmapi(const char *input, char (*f)(unsigned int, char), const char *expected, const char *desc) {
    printf("Testing ft_strmapi with input: \"%s\", function: %p, expected: \"%s\"\n",
           input ? input : "NULL", (void *)f, expected ? expected : "NULL");
    char *result = ft_strmapi(input, f);
    printf("Result: \"%s\"\n", result ? result : "NULL");
    //int pass = (result && expected && strcmp(result, expected) == 0) ||
               //(!result && !expected);
    //(void)pass; // Avoid unused variable warning
    (void)desc; // Avoid unused variable warning
    free(result);
}

int main(void)
{
    printf("Testing ft_strmapi:\n");
    test_ft_strmapi("abcdef", to_upper_even, "AbCdEf", "Uppercase even indices");
    test_ft_strmapi("ABC", add_index, "ACE", "Add index to char");
    test_ft_strmapi("", to_upper_even, "", "Empty string");
    test_ft_strmapi(NULL, to_upper_even, NULL, "NULL input");
    test_ft_strmapi("xyz", NULL, NULL, "NULL function pointer");
    return 0;
}
*/
/* * ft_split - Split a string into an array of strings based on a delimiter
 * @s: The string to split
 * @c: The delimiter character
 *
 * Returns an array of strings (NULL-terminated) or NULL if allocation fails.
 
// Helper to free the result of ft_split
void	free_split(char **arr)
{
    if (!arr)
        return;
    for (size_t i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

// Helper to compare ft_split result with expected array
void	test_ft_split(const char *s, char c, const char **expected)
{
    char	**res = ft_split(s, c);
    int		pass = 1;
    size_t	i = 0;

    printf("ft_split(\"%s\", '%c'):\n", s ? s : "NULL", c);
    if (!res && !expected)
    {
        printf("  PASS (both NULL)\n");
        return;
    }
    if (!res || !expected)
    {
        printf("  FAIL (one NULL)\n");
        free_split(res);
        return;
    }
    while (res[i] && expected[i])
    {
        if (strcmp(res[i], expected[i]) != 0)
            pass = 0;
        printf("  [%zu]: \"%s\" | expected: \"%s\"%s\n", i, res[i], expected[i], (strcmp(res[i], expected[i]) == 0) ? " (OK)" : " (FAIL)");
        i++;
    }
    if (res[i] || expected[i])
    {
        pass = 0;
        printf("  Length mismatch: result %s, expected %s\n", res[i] ? "longer" : "shorter", expected[i] ? "longer" : "shorter");
    }
    printf("  %s\n", pass ? "PASS" : "FAIL");
    free_split(res);
}

int main(void)
{
    // Basic split
    const char *exp1[] = {"hello", "world", NULL};
    test_ft_split("hello world", ' ', exp1);
    
    // Multiple delimiters
    const char *exp2[] = {"a", "b", "c", NULL};
    test_ft_split("a,,b,,,c", ',', exp2);

    // Leading/trailing delimiters
    const char *exp3[] = {"a", "b", "c", NULL};
    test_ft_split(",a,b,c,", ',', exp3);

    // Only delimiters
    const char *exp4[] = {NULL};
    test_ft_split(",,,", ',', exp4);

    // Empty string
    const char *exp5[] = {NULL};
    test_ft_split("", ',', exp5);

    // Delimiter not present
    const char *exp6[] = {"abc", NULL};
    test_ft_split("abc", ',', exp6);

    // Delimiter is '\0'
    const char *exp7[] = {"abc", NULL};
    test_ft_split("abc", '\0', exp7);

    // String with only one word
    const char *exp8[] = {"word", NULL};
    test_ft_split("word", ' ', exp8);

    // String with empty substrings between delimiters
    const char *exp9[] = {"a", "b", NULL};
    test_ft_split("a,,b", ',', exp9);

    // NULL input
    test_ft_split(NULL, ',', NULL);

    // Long input, special chars
    const char *exp10[] = {"foo", "bar", "baz", NULL};
    test_ft_split("foo\tbar\tbaz", '\t', exp10);
    
    return 0;
}
*/
/* * ft_strtrim - Trim characters from the start and end of a string
 * @s1: The string to trim
 * @set: The set of characters to trim
 *
 * Returns a newly allocated string with the characters in set removed from both ends.
 * The caller is responsible for freeing the returned string.

void test_ft_strtrim(const char *s1, const char *set, const char *expected)
{
    char *res = ft_strtrim(s1, set);
    int pass = (res && expected && strcmp(res, expected) == 0) ||
               (!res && !expected);
    printf("ft_strtrim(\"%s\", \"%s\") = \"%s\" | expected: \"%s\" | %s\n",
           s1 ? s1 : "NULL", set ? set : "NULL", res ? res : "NULL", expected ? expected : "NULL", pass ? "PASS" : "FAIL");
    free(res);
}

int main(void)
{
    // Basic trims
    test_ft_strtrim("  hello  ", " ", "hello");
    test_ft_strtrim("xxhelloxx", "x", "hello");
    test_ft_strtrim("abcXYZabc", "abc", "XYZ");
    test_ft_strtrim("42hello42", "42", "hello");

    // No trim needed
    test_ft_strtrim("hello", " ", "hello");
    test_ft_strtrim("hello", "x", "hello");

    // All trimmed
    test_ft_strtrim("xxxx", "x", "");
    test_ft_strtrim("   ", " ", "");

    // Empty string
    test_ft_strtrim("", " ", "");
    test_ft_strtrim("", "", "");

    // Empty set
    test_ft_strtrim("hello", "", "hello");

    // Set with multiple chars
    test_ft_strtrim("abchelloabc", "abc", "hello");
    test_ft_strtrim("cabac", "abc", "");

    // Only leading or trailing
    test_ft_strtrim("  hello", " ", "hello");
    test_ft_strtrim("hello  ", " ", "hello");

    // Set with special chars
    test_ft_strtrim("\n\t hello \t\n", " \n\t", "hello");

    // Edge: NULL input
    test_ft_strtrim(NULL, " ", NULL);
    test_ft_strtrim("hello", NULL, NULL);

    // Edge: set contains all possible chars
    char all_ascii[128];
    for (int i = 0; i < 127; i++) all_ascii[i] = (char)i;
    all_ascii[127] = '\0';
    test_ft_strtrim("hello", all_ascii, "");

    // Edge: string with only set chars
    test_ft_strtrim("aaa", "a", "");

    // Edge: string with set chars in the middle
    test_ft_strtrim("ahelloa", "a", "hello");
    test_ft_strtrim("abhelloab", "ab", "hello");

    return 0;
}
*/
/* ft_itoa - Convert an integer to a string
 * @n: The integer to convert
 *
 * Returns a pointer to the newly allocated string representing the integer.
 * The caller is responsible for freeing the returned string.
 * 
 void test_ft_itoa(int n, const char *expected)
{
    char *res = ft_itoa(n);
    if (!res)
    {
        printf("ft_itoa(%d): NULL (allocation failed)\n", n);
        return;
    }
    size_t len = strlen(res);
    int pass = (strcmp(res, expected) == 0);
    printf("ft_itoa(%d) = \"%s\" (len=%zu) | expected: \"%s\" | %s\n",
           n, res, len, expected, pass ? "PASS" : "FAIL");
    free(res);
}

int main(void)
{
    // Edge cases
    test_ft_itoa(0, "0");
    test_ft_itoa(1, "1");
    test_ft_itoa(-1, "-1");
    test_ft_itoa(2147483647, "2147483647");      // INT_MAX
    test_ft_itoa(-2147483648, "-2147483648");    // INT_MIN

    // Typical numbers
    test_ft_itoa(42, "42");
    test_ft_itoa(-42, "-42");
    test_ft_itoa(100000, "100000");
    test_ft_itoa(-100000, "-100000");

    // Numbers with trailing zeros
    test_ft_itoa(1000, "1000");
    test_ft_itoa(-1000, "-1000");

    // Large negative, not INT_MIN
    test_ft_itoa(-2147483647, "-2147483647");

    // Single digit
    for (int i = -9; i <= 9; i++)
        test_ft_itoa(i, (i < 0) ? (char[3]){'-', (char)('0' - i), '\0'} : (char[2]){(char)('0' + i), '\0'});

    // Random values
    test_ft_itoa(123456789, "123456789");
    test_ft_itoa(-987654321, "-987654321");

    return 0;
}
*/
/* ft_putnbr_fd - Write an integer to a file descriptor
 * @n: The integer to write
 * @fd: The file descriptor to write to
 *
 * This function writes the integer n to the file descriptor fd.
 * Handles negative numbers and special case for INT_MIN.
 * 
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
}*/
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
}*/
/* ft_memcmp - Compare two memory blocks
 * @s1: First memory block
 * @s2: Second memory block
 * @n: Number of bytes to compare
 *
 * Returns an integer less than, equal to, or greater than zero if the first n bytes
 * of s1 is found to be less than, equal to, or greater than the first n bytes of s2.

void test_ft_memcmp(const void *s1, const void *s2, size_t n, const char *desc)
{
	int ft = ft_memcmp(s1, s2, n);
	int std = memcmp(s1, s2, n);
	int pass = ((ft == 0 && std == 0) || (ft < 0 && std < 0) || (ft > 0 && std > 0));
	printf("ft_memcmp(\"%s\", \"%s\", %zu) = %d | memcmp = %d | %s (%s)\n",
		s1 ? (const char*)s1 : "NULL",
		s2 ? (const char*)s2 : "NULL",
		n, ft, std, pass ? "PASS" : "FAIL", desc);
}

int main(void)
{
	// Identical buffers
	test_ft_memcmp("abcdef", "abcdef", 6, "identical");
	test_ft_memcmp("abcdef", "abcdef", 0, "identical, n=0");

	// Differ at start
	test_ft_memcmp("xbcdef", "abcdef", 6, "diff at start");

	// Differ in middle
	test_ft_memcmp("abxdef", "abcdef", 6, "diff in middle");

	// Differ at end
	test_ft_memcmp("abcdey", "abcdef", 6, "diff at end");

	// n < length, difference after n
	test_ft_memcmp("abcxef", "abcdef", 3, "diff after n");

	// n > length
	test_ft_memcmp("abc", "abc", 10, "n > strlen, identical");

	// Empty buffers
	test_ft_memcmp("", "", 1, "empty buffers");

	// Embedded nulls
	test_ft_memcmp("ab\0cd", "ab\0ef", 5, "embedded nulls, diff after null");
	test_ft_memcmp("ab\0cd", "ab\0cd", 5, "embedded nulls, identical");

	// Non-ASCII bytes
	char s1[] = {'a', (char)0x80, 'c', 0};
	char s2[] = {'a', (char)0x81, 'c', 0};
	test_ft_memcmp(s1, s2, 3, "non-ASCII diff");

	// n = 0
	test_ft_memcmp("abc", "xyz", 0, "n = 0");

	// NULL pointers (if your ft_memcmp handles NULL)
	// test_ft_memcmp(NULL, NULL, 1, "both NULL");
	// test_ft_memcmp(NULL, "abc", 1, "first NULL");
	// test_ft_memcmp("abc", NULL, 1, "second NULL");

	return 0;
}
*/
/* ft_memchr - Locate a character in a memory block
 * @str: The memory block to search
 * @c: The character to find
 * @n: Number of bytes to search
 * Returns a pointer to the first occurrence of c in the first n bytes of str, or NULL if not found.

void test_ft_memchr(const void *s, int c, size_t n, const char *desc)
{
	void *ft = ft_memchr(s, c, n);
	void *std = memchr(s, c, n);
	int pass = (ft == std);
	printf("ft_memchr(\"%s\", 0x%02x, %zu): %s | memchr: %s | %s (%s)\n",
		s ? (const char*)s : "NULL",
		c, n,
		ft ? (char*)ft : "NULL",
		std ? (char*)std : "NULL",
		pass ? "PASS" : "FAIL",
		desc);
}

int main(void)
{
	// Basic cases
	test_ft_memchr("abcdef", 'c', 6, "char in middle");
	test_ft_memchr("abcdef", 'a', 6, "char at start");
	test_ft_memchr("abcdef", 'f', 6, "char at end");
	test_ft_memchr("abcdef", 'z', 6, "char not present");

	// Search for '\0'
	test_ft_memchr("abc\0def", '\0', 7, "search for null terminator");

	// n = 0
	test_ft_memchr("abcdef", 'a', 0, "n = 0");

	// n < strlen
	test_ft_memchr("abcdef", 'd', 3, "n < strlen, char after n");

	// n > strlen
	test_ft_memchr("abc", 'c', 10, "n > strlen, char present");

	// Empty string
	test_ft_memchr("", 'a', 1, "empty string");

	// Non-ASCII char
    char nonascii[] = {'a', 'b', 'c', (char)0x80, 'd', 'e', 'f', '\0'};
    test_ft_memchr(nonascii, 0x80, 7, "non-ASCII char");

	// Multiple occurrences, should return first
	test_ft_memchr("abacad", 'a', 6, "multiple occurrences");

	// NULL pointer (if your ft_memchr handles NULL)
	// test_ft_memchr(NULL, 'a', 1, "NULL pointer");

	return 0;
}
*/
/*ft_memcpy - Copy memory area
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

void test_ft_memcpy() {
	unsigned char src[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	unsigned char dst1[13];
	unsigned char dst2[13];

	// Full copy
	ft_memcpy(dst1, src, 13);
	memcpy(dst2, src, 13);
	print_buffer("ft_memcpy", dst1, 13);
	print_buffer("memcpy", dst2, 13);
	printf("%s: Full copy\n", ft_memcmp(dst1, dst2, 13) == 0 ? "PASS" : "FAIL");

	// Partial copy
	for (int i = 0; i < 10; i++) dst1[i] = dst2[i] = 0xFF;
	ft_memcpy(dst1, src, 5);
	memcpy(dst2, src, 5);
	print_buffer("ft_memcpy (partial)", dst1, 13);
	print_buffer("memcpy (partial)", dst2, 13);
	printf("%s: Partial copy\n", ft_memcmp(dst1, dst2, 13) == 0 ? "PASS" : "FAIL");

	// Zero length
	for (int i = 0; i < 13; i++) dst1[i] = dst2[i] = 0xAA;
	ft_memcpy(dst1, src, 0);
	memcpy(dst2, src, 0);
	printf("%s: Zero length\n", ft_memcmp(dst1, dst2, 13) == 0 ? "PASS" : "FAIL");

	// Self copy
	for (int i = 0; i < 13; i++) dst1[i] = i;
	ft_memcpy(dst1, dst1, 13);
	print_buffer("ft_memcpy (self)", dst1, 13);
	printf("PASS: Self copy (should be unchanged)\n");
}

int main(void) {
	test_ft_memcpy();
	return 0;
}*/
/* ft_memmove - Move memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to move
 *
 * Returns a pointer to the destination memory area dest.
 * Handles overlapping regions correctly.

void print_buffer(const char *label, unsigned char *buf, size_t n) {
	printf("%s: ", label);
	for (size_t i = 0; i < n; i++)
		printf("%02x ", buf[i]);
	printf("\n");
}

void test_ft_memmove() {
	unsigned char src[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	unsigned char buf1[16], buf2[16];

	// Non-overlapping copy
	ft_memcpy(buf1, src, 16);
	ft_memcpy(buf2, src, 16);
	ft_memmove(buf1, src, 16);
	memmove(buf2, src, 16);
	printf("Non-overlapping copy:\n");
	print_buffer("ft_memmove", buf1, 16);
	print_buffer("memmove", buf2, 16);
	printf("%s\n\n", ft_memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Overlapping copy: dest > src
	for (int i = 0; i < 16; i++) buf1[i] = buf2[i] = i;
	ft_memmove(buf1 + 2, buf1, 10);
	memmove(buf2 + 2, buf2, 10);
	printf("Overlapping copy (dest > src):\n");
	print_buffer("ft_memmove", buf1, 16);
	print_buffer("memmove", buf2, 16);
	printf("%s\n\n", ft_memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Overlapping copy: src > dest
	for (int i = 0; i < 16; i++) buf1[i] = buf2[i] = i;
	ft_memmove(buf1, buf1 + 2, 10);
	memmove(buf2, buf2 + 2, 10);
	printf("Overlapping copy (src > dest):\n");
	print_buffer("ft_memmove", buf1, 16);
	print_buffer("memmove", buf2, 16);
	printf("%s\n\n", ft_memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Zero-length copy
	for (int i = 0; i < 16; i++) buf1[i] = buf2[i] = 0xAA;
	ft_memmove(buf1, src, 0);
	memmove(buf2, src, 0);
	printf("Zero-length copy:\n");
	print_buffer("ft_memmove", buf1, 16);
	print_buffer("memmove", buf2, 16);
	printf("%s\n\n", ft_memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Self copy
	for (int i = 0; i < 16; i++) buf1[i] = i;
	ft_memmove(buf1, buf1, 16);
	printf("Self copy:\n");
	print_buffer("ft_memmove", buf1, 16);
	printf("PASS (should be unchanged)\n\n");

	// Embedded nulls
	unsigned char src_nulls[8] = {'a', 0, 'b', 0, 'c', 0, 'd', 0};
	for (int i = 0; i < 8; i++) buf1[i] = buf2[i] = 0xFF;
	ft_memmove(buf1, src_nulls, 8);
	memmove(buf2, src_nulls, 8);
	printf("Embedded nulls:\n");
	print_buffer("ft_memmove", buf1, 8);
	print_buffer("memmove", buf2, 8);
	printf("%s\n\n", memcmp(buf1, buf2, 8) == 0 ? "PASS" : "FAIL");

	// n > length (should copy up to n, may read past end if not careful)
	for (int i = 0; i < 8; i++) buf1[i] = buf2[i] = i;
	ft_memmove(buf1, buf2, 12); // Only safe if enough space
	memmove(buf2, buf2, 12);
	printf("n > length (self copy, safe):\n");
	print_buffer("ft_memmove", buf1, 12);
	print_buffer("memmove", buf2, 12);
	printf("%s\n\n", memcmp(buf1, buf2, 12) == 0 ? "PASS" : "FAIL");
}

int main(void) {
	test_ft_memmove();
	return 0;
}
*/
/* ft_memset - Fill a memory area with a constant byte
 * @s: Pointer to the memory area
 * @c: The byte to fill with
 * @n: Number of bytes to fill
 *
 * Returns a pointer to the memory area s.
 * This function sets the first n bytes of the memory area pointed to by s to the value c.

 void print_buffer(const char *label, unsigned char *buf, size_t n) {
	printf("%s: ", label);
	for (size_t i = 0; i < n; i++)
		printf("%02x ", buf[i]);
	printf("\n");
}

void test_ft_memset() {
	unsigned char buf1[16], buf2[16];

	// Set all bytes to 0xAA
	memset(buf1, 4, 16);
	memset(buf2, 4, 16);
	ft_memset(buf1, 4, 16);
	memset(buf2, 4, 16);
	print_buffer("ft_memset", buf1, 16);
	print_buffer("memset", buf2, 16);
	printf("%s: Set all bytes\n", memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Set first 8 bytes to 0x55
	memset(buf1, 0x00, 16);
	memset(buf2, 0x00, 16);
	ft_memset(buf1, 0x55, 8);
	memset(buf2, 0x55, 8);
	print_buffer("ft_memset (partial)", buf1, 16);
	print_buffer("memset (partial)", buf2, 16);
	printf("%s: Partial set\n", memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Set zero bytes
	memset(buf1, 0x77, 16);
	memset(buf2, 0x77, 16);
	ft_memset(buf1, 0x99, 0);
	//memset(buf2, 0x99, 0);
	print_buffer("ft_memset (zero)", buf1, 16);
	//print_buffer("memset (zero)", buf2, 16);
	printf("%s: Zero length\n", memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Set all bytes to 0 (zero out)
	memset(buf1, 0xFF, 16);
	memset(buf2, 0xFF, 16);
	ft_memset(buf1, 0, 16);
	memset(buf2, 0, 16);
	print_buffer("ft_memset (zero out)", buf1, 16);
	print_buffer("memset (zero out)", buf2, 16);
	printf("%s: Zero out\n", memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Set with non-ASCII value
	memset(buf1, 0x00, 16);
	memset(buf2, 0x00, 16);
	ft_memset(buf1, 0xC3, 16);
	memset(buf2, 0xC3, 16);
	print_buffer("ft_memset (non-ASCII)", buf1, 16);
	print_buffer("memset (non-ASCII)", buf2, 16);
	printf("%s: Non-ASCII value\n", memcmp(buf1, buf2, 16) == 0 ? "PASS" : "FAIL");

	// Set on empty buffer
	unsigned char empty1[1] = {0xAB};
	//unsigned char empty2[1] = {0xAB};
	ft_memset(empty1, 0x12, 0);
	//memset(empty2, 0x12, 0);
	print_buffer("ft_memset (empty)", empty1, 1);
	//print_buffer("memset (empty)", empty2, 1);
	//printf("%s: Empty buffer, zero length\n", memcmp(empty1, empty2, 1) == 0 ? "PASS" : "FAIL");
}

int main(void) {
	test_ft_memset();
	return 0;
}*/
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
    ft_memset(buf2, 0, 10);

    print_buffer("ft_bzero", buf1, 10);
    print_buffer("memset", buf2, 10);

    // Check if both buffers are zeroed
    if (ft_memcmp(buf1, buf2, 10) == 0)
        printf("PASS: Buffers are zeroed correctly\n");
    else
        printf("FAIL: Buffers differ\n");

    // Partial zeroing
    for (int i = 0; i < 10; i++)
        buf1[i] = buf2[i] = (unsigned char)(i + 1);

    ft_bzero(buf1, 5);
    ft_memset(buf2, 0, 5);

    print_buffer("ft_bzero (partial)", buf1, 10);
    print_buffer("memset (partial)", buf2, 10);

    if (ft_memcmp(buf1, buf2, 10) == 0)
        printf("PASS: Partial zeroing works\n");
    else
        printf("FAIL: Partial zeroing failed\n");

    // Zero length
    for (int i = 0; i < 10; i++)
        buf1[i] = buf2[i] = (unsigned char)(i + 1);

    ft_bzero(buf1, 0);
    ft_memset(buf2, 0, 0);

    if (ft_memcmp(buf1, buf2, 10) == 0)
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
 * 

void print_strlcpy_result(const char *desc, char *ft_dst, char *std_dst, size_t ft_ret, size_t std_ret) {
	printf("%s\n", desc);
	printf("ft_strlcpy:   \"%s\" (ret=%zu)\n", ft_dst, ft_ret);
	printf("std strlcpy:  \"%s\" (ret=%zu)\n", std_dst, std_ret);
	if (strcmp(ft_dst, std_dst) == 0 && ft_ret == std_ret)
		printf("PASS\n\n");
	else
		printf("FAIL\n\n");
}

void test_ft_strlcpy() {
	// Test 1: Normal copy, enough space
	char ft1[20], std1[20];
	size_t ft_ret = ft_strlcpy(ft1, "Hello, world!", sizeof(ft1));
	size_t std_ret = strlcpy(std1, "Hello, world!", sizeof(std1));
	print_strlcpy_result("Test 1: Normal, enough space", ft1, std1, ft_ret, std_ret);

	// Test 2: Truncation, not enough space
	char ft2[6], std2[6];
	ft_ret = ft_strlcpy(ft2, "Hello, world!", sizeof(ft2));
	std_ret = strlcpy(std2, "Hello, world!", sizeof(std2));
	print_strlcpy_result("Test 2: Truncation", ft2, std2, ft_ret, std_ret);

	// Test 3: Size = 0
	char ft3[10] = "AAAAA", std3[10] = "AAAAA";
	ft_ret = ft_strlcpy(ft3, "Hello", 0);
	std_ret = strlcpy(std3, "Hello", 0);
	print_strlcpy_result("Test 3: size = 0", ft3, std3, ft_ret, std_ret);

	// Test 4: Empty src
	char ft4[10] = "XXXXXXXXX", std4[10] = "XXXXXXXXX";
	ft_ret = ft_strlcpy(ft4, "", sizeof(ft4));
	std_ret = strlcpy(std4, "", sizeof(std4));
	print_strlcpy_result("Test 4: empty src", ft4, std4, ft_ret, std_ret);

	// Test 5: Empty dest, normal src
	char ft5[1] = "", std5[1] = "";
	ft_ret = ft_strlcpy(ft5, "abc", sizeof(ft5));
	std_ret = strlcpy(std5, "abc", sizeof(std5));
	print_strlcpy_result("Test 5: empty dest, normal src", ft5, std5, ft_ret, std_ret);

	// Test 6: src shorter than size
	char ft6[10], std6[10];
	ft_ret = ft_strlcpy(ft6, "abc", sizeof(ft6));
	std_ret = strlcpy(std6, "abc", sizeof(std6));
	print_strlcpy_result("Test 6: src shorter than size", ft6, std6, ft_ret, std_ret);

	// Test 7: src longer than size
	char ft7[5], std7[5];
	ft_ret = ft_strlcpy(ft7, "abcdefg", sizeof(ft7));
	std_ret = strlcpy(std7, "abcdefg", sizeof(std7));
	print_strlcpy_result("Test 7: src longer than size", ft7, std7, ft_ret, std_ret);

	// Test 8: Non-ASCII characters
	char ft8[20], std8[20];
	ft_ret = ft_strlcpy(ft8, "héllo世界", sizeof(ft8));
	std_ret = strlcpy(std8, "héllo世界", sizeof(std8));
	print_strlcpy_result("Test 8: Non-ASCII", ft8, std8, ft_ret, std_ret);

	// Test 9: Embedded nulls
	char src9[] = {'a', 'b', '\0', 'c', 'd', 0};
	char ft9[10], std9[10];
	ft_ret = ft_strlcpy(ft9, src9, sizeof(ft9));
	std_ret = strlcpy(std9, src9, sizeof(std9));
	print_strlcpy_result("Test 9: Embedded nulls", ft9, std9, ft_ret, std_ret);

	// Test 10: size == 1
	char ft10[10] = "XXXXXXXXX", std10[10] = "XXXXXXXXX";
	ft_ret = ft_strlcpy(ft10, "abcdef", 1);
	std_ret = strlcpy(std10, "abcdef", 1);
	print_strlcpy_result("Test 10: size == 1", ft10, std10, ft_ret, std_ret);

	// Test 11: size == strlen(src) + 1
	char ft11[7], std11[7];
	ft_ret = ft_strlcpy(ft11, "abcdef", 7);
	std_ret = strlcpy(std11, "abcdef", 7);
	print_strlcpy_result("Test 11: size == strlen(src)+1", ft11, std11, ft_ret, std_ret);

	// Test 12: size < strlen(src)
	char ft12[4], std12[4];
	ft_ret = ft_strlcpy(ft12, "abcdef", 4);
	std_ret = strlcpy(std12, "abcdef", 4);
	print_strlcpy_result("Test 12: size < strlen(src)", ft12, std12, ft_ret, std_ret);
}

int main(void) {
	test_ft_strlcpy();
	return 0;
}*/
/* ft_strlcat - Concatenate two strings with size limit
 * @dst: Destination string
 * @src: Source string
 * @size: Size of the destination buffer
 *
 * Returns the total length of the string it tried to create.
 * If the size is not enough, it truncates the result.
 * 

void print_strlcat_result(const char *desc, char *ft_dst, char *std_dst, size_t ft_ret, size_t std_ret) {
	printf("%s\n", desc);
	printf("ft_strlcat:   \"%s\" (ret=%zu)\n", ft_dst, ft_ret);
	printf("std strlcat:  \"%s\" (ret=%zu)\n", std_dst, std_ret);
	if (strcmp(ft_dst, std_dst) == 0 && ft_ret == std_ret)
		printf("PASS\n\n");
	else
		printf("FAIL\n\n");
}

void test_ft_strlcat() {
	// Test 1: Normal concatenation, enough space
	char ft1[30] = "Hello";
	char std1[30] = "Hello";
	size_t ft_ret = ft_strlcat(ft1, ", world!", sizeof(ft1));
	size_t std_ret = strlcat(std1, ", world!", sizeof(std1));
	print_strlcat_result("Test 1: Normal, enough space", ft1, std1, ft_ret, std_ret);

	// Test 2: Truncation, not enough space
	char ft2[10] = "Hi";
	char std2[10] = "Hi";
	ft_ret = ft_strlcat(ft2, " there!", sizeof(ft2));
	std_ret = strlcat(std2, " there!", sizeof(std2));
	print_strlcat_result("Test 2: Truncation", ft2, std2, ft_ret, std_ret);

	// Test 3: Size = 0
	char ft3[10] = "Hi";
	char std3[10] = "Hi";
	ft_ret = ft_strlcat(ft3, " there!", 0);
	std_ret = strlcat(std3, " there!", 0);
	print_strlcat_result("Test 3: size = 0", ft3, std3, ft_ret, std_ret);

	// Test 4: Empty dest, normal src
	char ft4[10] = "";
	char std4[10] = "";
	ft_ret = ft_strlcat(ft4, "abc", sizeof(ft4));
	std_ret = strlcat(std4, "abc", sizeof(std4));
	print_strlcat_result("Test 4: empty dest", ft4, std4, ft_ret, std_ret);

	// Test 5: Empty src
	char ft5[5] = "1234";
	char std5[5] = "1234";
	ft_ret = ft_strlcat(ft5, "", sizeof(ft5));
	std_ret = strlcat(std5, "", sizeof(std5));
	print_strlcat_result("Test 5: empty src", ft5, std5, ft_ret, std_ret);

	// Test 6: dest_len >= size
	char ft6[10] = "abc";
	char std6[10] = "abc";
	ft_ret = ft_strlcat(ft6, "defghijkl", 3);
	std_ret = strlcat(std6, "defghijkl", 3);
	print_strlcat_result("Test 6: dest_len >= size", ft6, std6, ft_ret, std_ret);

	// Test 7: Both src and dest empty
	char ft7[5] = "";
	char std7[5] = "";
	ft_ret = ft_strlcat(ft7, "", sizeof(ft7));
	std_ret = strlcat(std7, "", sizeof(std7));
	print_strlcat_result("Test 7: both empty", ft7, std7, ft_ret, std_ret);

	// Test 8: size == dest_len + 1 (problem case)
	char ft8[6] = "abc";
	char std8[6] = "abc";
	ft_ret = ft_strlcat(ft8, "de", 4);
	std_ret = strlcat(std8, "de", 4);
	print_strlcat_result("Test 8: size == dest_len + 1", ft8, std8, ft_ret, std_ret);

	// Test 9: size == 1
	char ft9[10] = "abc";
	char std9[10] = "abc";
	ft_ret = ft_strlcat(ft9, "def", 1);
	std_ret = strlcat(std9, "def", 1);
	print_strlcat_result("Test 9: size == 1", ft9, std9, ft_ret, std_ret);

	// Test 10: size < dest_len
	char ft10[10] = "abcdef";
	char std10[10] = "abcdef";
	ft_ret = ft_strlcat(ft10, "xyz", 3);
	std_ret = strlcat(std10, "xyz", 3);
	print_strlcat_result("Test 10: size < dest_len", ft10, std10, ft_ret, std_ret);

	// Test 11: Non-ASCII characters
	char ft11[20] = "héllo";
	char std11[20] = "héllo";
	ft_ret = ft_strlcat(ft11, "世界", sizeof(ft11));
	std_ret = strlcat(std11, "世界", sizeof(std11));
	print_strlcat_result("Test 11: Non-ASCII", ft11, std11, ft_ret, std_ret);
}

int main(void) {
	test_ft_strlcat();
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
/*ft_calloc - Allocate memory and initialize to zero


 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Returns a pointer to the allocated memory, or NULL if allocation fails.
 
void test_ft_calloc(size_t nmemb, size_t size)
{
    size_t i;
    int pass = 1;
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
        if (ft_ptr[i] != std_ptr[i])
        {
            pass = 0;
            break;
        }
    }
    if (pass)
        printf("ft_calloc(%zu, %zu): PASS (matches calloc, all bytes zero)\n", nmemb, size);
    else
        printf("ft_calloc(%zu, %zu): FAIL (memory mismatch at %zu)\n", nmemb, size, i);

    free(ft_ptr);
    free(std_ptr);
}

int main(void)
{
    test_ft_calloc(10, 4);      // 40 bytes
    test_ft_calloc(0, 10);      // 0 bytes
    test_ft_calloc(10, 0);      // 0 bytes
    test_ft_calloc(1, 1);       // 1 byte
    test_ft_calloc(1000, 1);    // 1000 bytes
    test_ft_calloc(1, 1000);    // 1000 bytes
    test_ft_calloc(100, 100);   // 10,000 bytes
    test_ft_calloc(1024, 1024); // 1MB
    return 0;
}
*/
/* ft_strdup - Duplicate a string

 * @s: The string to duplicate
 *
 * Returns a pointer to the newly allocated string, or NULL if allocation fails.
 
void test_ft_strdup(const char *input) {
	char *ft = ft_strdup(input);
	char *std = input ? strdup(input) : NULL;
	int pass = 0;

	if (!input) {
		if (!ft)
			printf("ft_strdup(NULL): PASS (returns NULL)\n");
		else {
			printf("ft_strdup(NULL): FAIL (should return NULL)\n");
			free(ft);
		}
		return;
	}

	if (!ft || !std) {
		printf("ft_strdup(\"%s\"): FAIL (allocation failed)\n", input);
		free(ft);
		free(std);
		return;
	}

	if (strcmp(ft, std) == 0 && ft != input && std != input)
		pass = 1;

	printf("ft_strdup(\"%s\") = \"%s\" | strdup = \"%s\" | %s\n",
		   input, ft, std, pass ? "PASS" : "FAIL");

	free(ft);
	free(std);
}

int main(void) {
	// Normal string
	test_ft_strdup("Hello, world!");
	// Empty string
	test_ft_strdup("");
	// String with spaces
	test_ft_strdup("   leading and trailing   ");
	// String with embedded nulls (should stop at first null)
	test_ft_strdup("abc\0def");
	// String with non-ASCII characters
	test_ft_strdup("héllo\xC3\xA9");
	// NULL input (if your ft_strdup handles it)
	test_ft_strdup(NULL);

	return 0;
}
*/
/* ft_strjoin - Concatenate two strings into a new string
 * @s1: First string
 * @s2: Second string
 *
 * Returns a new string that is the concatenation of s1 and s2, or NULL if allocation fails.
void test_ft_strjoin(const char *s1, const char *s2, const char *expected, const char *desc) {
	char *result = ft_strjoin(s1, s2);
	int pass = 0;
	if (!expected && !result)
		pass = 1;
	else if (expected && result && strcmp(result, expected) == 0)
		pass = 1;
	printf("ft_strjoin(%s, %s): \"%s\" | expected: \"%s\" | %s (%s)\n",
		s1 ? "\"" : "NULL", s2 ? "\"" : "NULL",
		result ? result : "NULL", expected ? expected : "NULL",
		pass ? "PASS" : "FAIL", desc);
	free(result);
}

int main(void) {
	// Both normal
	test_ft_strjoin("Hello", "World", "HelloWorld", "Both normal");
	// First empty
	test_ft_strjoin("", "World", "World", "First empty");
	// Second empty
	test_ft_strjoin("Hello", "", "Hello", "Second empty");
	// Both empty
	test_ft_strjoin("", "", "", "Both empty");
	// First NULL
	test_ft_strjoin(NULL, "World", NULL, "First NULL");
	// Second NULL
	test_ft_strjoin("Hello", NULL, NULL, "Second NULL");
	// Both NULL
	test_ft_strjoin(NULL, NULL, NULL, "Both NULL");
	// Spaces
	test_ft_strjoin("foo ", " bar", "foo  bar", "Strings with spaces");
	// Special characters
	test_ft_strjoin("héllo", "世界", "héllo世界", "Non-ASCII characters");
	// Long strings
	char long1[1001], long2[1001], long_expected[2002];
	memset(long1, 'A', 1000); long1[1000] = '\0';
	memset(long2, 'B', 1000); long2[1000] = '\0';
	strcpy(long_expected, long1); strcat(long_expected, long2);
	test_ft_strjoin(long1, long2, long_expected, "Long strings");

	return 0;
}
	*/