/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:09:05 by aosman            #+#    #+#             */
/*   Updated: 2025/06/08 20:55:05 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	length;
	void	*ptr;
	size_t	i;
	char	*p;

	length = nmemb * size;
	if (nmemb != 0 && size != 0 && length / size != nmemb)
		return (NULL);
	ptr = (char *)malloc(length * sizeof(char));
	if (!ptr)
		return (NULL);
	p = (char *)ptr;
	i = 0;
	while (i < length)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
