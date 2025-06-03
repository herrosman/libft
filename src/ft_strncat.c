/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:39 by aosman            #+#    #+#             */
/*   Updated: 2025/06/03 15:59:26 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	while (dest[d])
		d++;
	while (src[i] && i < n)
		dest[d++] = src[i++];
	dest[d] = '\0';
	return (dest);
}
