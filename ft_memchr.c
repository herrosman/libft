/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:35:29 by aosman            #+#    #+#             */
/*   Updated: 2025/06/09 12:56:28 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	ptr = (char *)str;
	while (i < n)
	{
		if (*ptr == (char)c)
			return (ptr);
		i++;
		ptr++;
	}
	return (NULL);
}
