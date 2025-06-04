/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:46:23 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 17:27:57 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				res;
	int				neg;

	res = 0;
	neg = 1;
	if ((*nptr < '0' || *nptr > '9') && *nptr != '-')
		return (res);
	if (*nptr == '-')
	{
		neg *= -1;
		nptr++;
	}
	i = 0;
	while (i < ft_strlen(nptr))
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}
