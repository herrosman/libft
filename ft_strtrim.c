/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:54:51 by aosman            #+#    #+#             */
/*   Updated: 2025/06/05 17:18:57 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_first_index(char const *s1, char const *set)
{
	int	res;

	if (!set)
		return (0);
	res = 0;
	while (s1[res] && set[res])
	{
		if (s1[res] != set[res])
			return (0);
		res++;
	}
	return (res);
}

static int	get_last_index(char const *s1, char const *set)
{
	unsigned int	s1_len;
	unsigned int	set_len;

	if (!set)
		return (0);
	s1_len = ft_strlen(s1) -1;
	set_len = ft_strlen(set) -1;
	while (set[set_len] && s1[s1_len])
	{
		if (s1[s1_len] != set[set_len])
			return (ft_strlen(s1));
		if (s1_len == 0)
			break ;
		s1_len--;
		if (set_len == 0)
			break ;
		set_len--;
	}
	return (s1_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*res;
	int		length;
	int		i;

	first = get_first_index(s1, set);
	last = get_last_index(s1, set);
	length = last - first;
	res = (char *)malloc(length * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (first <= last)
	{
		res[i++] = s1[first++];
	}
	res[i] = '\0';
	return (res);
}
