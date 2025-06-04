/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:09:05 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 21:13:51 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			length;
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	length = nmemb * size;
	if (nmemb != 0 && size != 0 && length / size != nmemb)
		return (NULL);
	ptr = malloc(length);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < length)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
