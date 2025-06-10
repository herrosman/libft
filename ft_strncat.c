/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:39 by aosman            #+#    #+#             */
/*   Updated: 2025/06/09 21:46:38 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	d_len;

	i = 0;
	d_len = ft_strlen(dest);
	while (src[i] && i < n)
		dest[d_len++] = src[i++];
	dest[d_len] = '\0';
	return (dest);
}
