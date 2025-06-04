/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:09:05 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 19:11:41 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int check_overflow(int i, int j)
{
	const int INT_MAX = 2147483647;
	if (i >= 0 && j >=0 && (i > INT_MAX - j))
		return (0);	

}
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;	
	int	*res;
	
	res = NULL;
	if (check_overflow(nmemb, size))
		return (NULL);
	if (!nmemb && !size)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		return (res);
	}
		
	//allocate memmory nmeb=5, size = 4(bytes)
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}