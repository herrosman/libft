/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:57 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 17:28:04 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
   int val, std;
   char *str; 
   str = "-150sdfg";
   val = ft_atoi(str); 
   std = atoi(str);
   printf("ft response : %d, atoi : %d\n", val, std);
}