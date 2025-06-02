/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:47 by aosman            #+#    #+#             */
/*   Updated: 2025/06/02 15:58:46 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int main() {
  
  char str1[20] = "C programming";
  char str2[20];

<<<<<<< HEAD
  ft_strcpy(str2, str1);

  puts(str2); 

  return 0;
}
*/
char    *ft_strcpy(char *dest, const char *src)
=======
char	*ft_strcpy(char *dest, const char *src)
>>>>>>> 48ddb8441c309675ff5ccdcc7ef275d05cb97fe2
{
	int	i;

<<<<<<< HEAD
    //ptr = dest;
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
        //src++;
    }
    dest[i] = '\0'; 
    return dest; 
}
=======
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main() {
  
  char str1[20] = "C programming";
  char str2[20];

  // copying str1 to str2
  ft_strcpy(str2, str1);

  puts(str2); // C programming

  return 0;
}
*/
>>>>>>> 48ddb8441c309675ff5ccdcc7ef275d05cb97fe2
