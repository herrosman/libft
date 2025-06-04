/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:35:29 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 14:46:03 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (!str)
		return (NULL);
	ptr = (unsigned char *)str;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		i++;
		ptr++; 
	}
	return (NULL);
}