#include "libft.h"
#include <stdlib.h>

// Helper function to calculate the length of the number
static size_t get_num_length(int n)
{
    size_t length = (n <= 0) ? 1 : 0; // Account for '-' or '0'

    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return length;
}

char *ft_itoa(int n)
{
    char *result;
    size_t length;
    unsigned int num;

    length = get_num_length(n);
    result = (char *)malloc(length + 1); // Allocate memory for the string
    if (!result)
        return NULL;

    result[length] = '\0'; // Null-terminate the string

    if (n < 0)
    {
        result[0] = '-'; // Add the negative sign
        num = -n; // Convert to positive for processing
    }
    else
    {
        num = n;
    }

    // Fill the string from the end
    while (length > 0 && result[length - 1] != '-')
    {
        result[--length] = (num % 10) + '0';
        num /= 10;
    }

    return result;
}