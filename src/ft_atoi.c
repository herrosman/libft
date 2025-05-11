#include "libft.h"

int ft_atoi(const char *str) {
    int result = 0;
    int sign = 1;

    // Skip whitespace
    while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')) {
        str++;
    }

    // Check for sign
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    // Convert digits to integer
    while (*str && *str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}