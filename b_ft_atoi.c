/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:46:23 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 17:19:53 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	int				res;
	int				neg;

	res = 0;
	neg = 1;
	if ((nptr[0] < '0' || nptr[0] > '9') && nptr[0] != '-')
		return (res);
	if (nptr[0] == '-')
	{
		neg *= -1;
		nptr++;
	}
	i = 0;
	len = ft_strlen(nptr);
	while (i < len)
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
		i++;
	}
	j = 0;
	while (j < i)
	{
		res = res * 10 + (nptr[j] - '0');
		j++;
	}
	return (res * neg);
}
