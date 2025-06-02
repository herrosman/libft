/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:39:48 by aosman            #+#    #+#             */
/*   Updated: 2025/06/02 15:28:22 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	main(void)
{
	char	*str;

	str = "Hello, 42Wolfsburg";
	printf("String : %s\n", str);
	printf("Length : %li\n", ft_strlen(str));
}
*/
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
