/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:57 by aosman            #+#    #+#             */
/*   Updated: 2025/06/04 18:55:13 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


int main() {
   int *pointer = (int *)ft_calloc(0, 0);
   int *pointer1 = (int *)calloc(0, 0);
   if (pointer == NULL) {
      printf("ft_calloc : Null pointer \n");
   }
   else if (pointer1 == NULL)
   {
		printf("calloc : Null pointer \n");
   } 
   else {
      printf("Address = %p\n", (void*)pointer);
	  printf("Address = %p\n", (void*)pointer1);
   }
   free(pointer);
   return 0;
}

/*
int main() {
   int n = 0;
   int *array;
   int *array1;
   // use calloc function to allocate the memory
   array = (int*)ft_calloc(n, 0);
   array1 = (int*)calloc(n, 0);
   if (array == NULL) {
      fprintf(stderr, "Memory allocation failed : FT_CALLOC!\n");
      return 1;
   }
   if (array1 == NULL) {
      fprintf(stderr, "Memory allocation failed : CALLOC!\n");
      return 1;
   }
   //Display the array value
   printf("Array elements after FT calloc: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
   printf("Array elements after calloc: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array1[i]);
   }
   printf("\n");
   
   //free the allocated memory
   free(array);
   free(array1);
   return 0;
}*/