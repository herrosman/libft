/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:06:21 by aosman            #+#    #+#             */
/*   Updated: 2025/06/02 17:09:53 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
    // Test cases for ft_isdigit
    char test1 = '5';
    char test2 = '=';
    char test3 = 'A';
    char test4 = '9';
    char test5 = ' ';

    printf("ft_isalnum('%c') = %d\n", test1, ft_isalnum(test1)); // Expected: 1
    printf("ft_isalnum('%c') = %d\n", test2, ft_isalnum(test2)); // Expected: 0
    printf("ft_isalnum('%c') = %d\n", test3, ft_isalnum(test3)); // Expected: 1
    printf("ft_isalnum('%c') = %d\n", test4, ft_isalnum(test4)); // Expected: 1
    printf("ft_isalnum('%c') = %d\n", test5, ft_isalnum(test5)); // Expected: 0

    return 0;
}


int	ft_isalnum(int c)
{
    if (ft_isalpha(c) || ft_isdigit(c))
        return (1);
    return (0);
}