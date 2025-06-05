/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:20:53 by aosman            #+#    #+#             */
/*   Updated: 2025/06/05 19:11:13 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static	char	*get_string(char const *s, int start, int end)
// {
// 	int i;
	
// 	i = 0;
// 	while(start < end)
// 	{

// 		start++;
// 	}
// 	return (i);
// } 

static int	get_num_strings(char const *s, char c)
{
	static int	sum;

	sum = 1;
	while(*s)
	{
		if (*s == c)
			sum++;
		s++;
	}
	return (sum);
}
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;
	int		sub_len;		
	int		num_str;
	char	*str;
	//int		index;
	
	if(!s)
		return (NULL);
	len = ft_strlen(s);
	num_str = get_num_strings(s, c);
	printf("num of strings: %d\n", num_str);
	res = (char **)malloc((num_str + 1) * sizeof(char **));
	if (!res)
		return (NULL);
	
	i = 0;
	// index = 0;
	while(i < num_str)
	{
		//length of string is len - sub_len
		 str = ft_strchr(s, c);
		 sub_len = ft_strlen(str);
		 printf("Size of string :%i\n", len - sub_len);
		//get string and allocate new string to copy
		i++;
	}	
	// str = get_string()

	return (NULL);
}