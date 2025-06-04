/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:37:56 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 12:24:25 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (!haystack)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (len < needle_len || !*haystack)
		return (NULL);
	while (*haystack && len >= needle_len)
	{
		i = 0;
		while (i < needle_len && haystack[i] == needle[i])
			i++;
		if (i == needle_len)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
