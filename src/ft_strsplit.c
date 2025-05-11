#include "libft.h"
#include <stdlib.h>

// Helper function to count the number of words in the string
static size_t count_words(char const *s, char c)
{
    size_t count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
        {
            in_word = 0;
        }
        s++;
    }
    return count;
}

// Helper function to allocate and copy a word
static char *copy_word(char const *s, size_t start, size_t len)
{
    char *word = (char *)malloc(len + 1);
    if (!word)
        return NULL;
    ft_strncpy(word, s + start, len);
    word[len] = '\0';
    return word;
}

char **ft_strsplit(char const *s, char c)
{
    char **result;
    size_t i = 0, j = 0, start = 0;
    size_t word_count;

    if (!s)
        return NULL;

    word_count = count_words(s, c);
    result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return NULL;

    while (s[i])
    {
        if (s[i] != c)
        {
            if (j == 0 || s[i - 1] == c)
                start = i;
            if (s[i + 1] == '\0' || s[i + 1] == c)
                result[j++] = copy_word(s, start, i - start + 1);
        }
        i++;
    }
    result[j] = NULL; // Null-terminate the array
    return result;
}