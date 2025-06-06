/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:10:37 by aosman            #+#    #+#             */
/*   Updated: 2025/06/06 16:10:02 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_helper(char *res, int n, int index, int len)
{
	
	if (n == 0)
		res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	if (n > 0)
	{
		index--;
		res[index] = (n % 10) + '0';
		ft_itoa_helper(res, (n / 10), index, len);
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	
	
	len = get_length(n);
	printf("len |%d|\n", len);
	ptr = (char *)malloc(len * sizeof(char *));
	if (!ptr)
		return (NULL);
	
	if (n == -2147483648)
	{
		ptr = "-2147483648";
		return (ptr);
	}		

	return (ft_itoa_helper(ptr, n, len, len));
}
