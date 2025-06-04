/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:04:23 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 14:32:38 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	unsigned char		*temp;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	src_ptr = (const unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*temp = src_ptr[i];
		temp++;
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
