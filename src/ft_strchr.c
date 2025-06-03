/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:49:13 by aosman            #+#    #+#             */
/*   Updated: 2025/06/03 12:40:37 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int q)
{
	char	*s;
	char	f;

	s = (char *)str;
	f = (char)q;
	while (*s)
	{
		if (*s == f)
			return (s);
		s++;
	}
	if (f == '\0')
		return (s);
	return (NULL);
}
