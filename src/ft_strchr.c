#include "libft.h"

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
    res = ft_strchr(s1, 'w');
    exp = strchr(s2, 'w');
    print_result("Test 1: Find 'w'", res, exp);

    // Test 2: Find first character
    res = ft_strchr(s1, 'H');
    exp = strchr(s2, 'H');
    print_result("Test 2: Find 'H'", res, exp);

    // Test 3: Find last character
    res = ft_strchr(s1, '!');
    exp = strchr(s2, '!');
    print_result("Test 3: Find '!'", res, exp);

    // Test 4: Find null terminator
    res = ft_strchr(s1, '\0');
    exp = strchr(s2, '\0');
    print_result("Test 4: Find '\\0'", res, exp);

    // Test 5: Character not present
    res = ft_strchr(s1, 'z');
    exp = strchr(s2, 'z');
    print_result("Test 5: Not present", res, exp);

    // Test 6: Empty string, search for '\0'
    res = ft_strchr(empty, '\0');
    exp = strchr(empty, '\0');
    print_result("Test 6: Empty string, '\\0'", res, exp);

    // Test 7: Empty string, search for 'a'
    res = ft_strchr(empty, 'a');
    exp = strchr(empty, 'a');
    print_result("Test 7: Empty string, 'a'", res, exp);

    // Test 8: Multiple occurrences, should return first
    char s3[] = "banana";
    char s4[] = "banana";
    res = ft_strchr(s3, 'a');
    exp = strchr(s4, 'a');
    print_result("Test 8: Multiple occurrences", res, exp);

    return 0;
}

char    *ft_strchr(const char *str, int q)
{
    char    *s;

    s = (char *)str;
    while (*s)
    {
        if (*s == (char)q)
            return (s);
        s++;
    }
    if ((char)q == '\0')
        return (s);
    return (NULL);
}