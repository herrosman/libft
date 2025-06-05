/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:57 by aosman            #+#    #+#             */
/*   Updated: 2025/06/05 19:43:08 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main() {

    FILE *fptr;
    fptr = fopen("example.txt", "w");
    
    if (fptr == NULL) {
        printf("Error!");
        return 1;
    }
    
    ft_putchar_fd('C', (int)fptr);
    
    fclose(fptr);
    
    return 0;
}

/*
void	test_ft_calloc(size_t nmemb, size_t size)
{
    size_t	i;
    int		pass = 1, std_pass = 1;
    unsigned char *ft_ptr = (unsigned char *)ft_calloc(nmemb, size);
    unsigned char *std_ptr = (unsigned char *)calloc(nmemb, size);

    // Check allocation result
    if (!ft_ptr && !std_ptr)
    {
        printf("ft_calloc(%zu, %zu): NULL | calloc: NULL (allocation failed)\n", nmemb, size);
        return;
    }
    if ((!ft_ptr && std_ptr) || (ft_ptr && !std_ptr))
    {
        printf("ft_calloc(%zu, %zu): %s | calloc: %s (MISMATCH in allocation)\n",
            nmemb, size,
            ft_ptr ? "NOT NULL" : "NULL",
            std_ptr ? "NOT NULL" : "NULL");
        if (ft_ptr) free(ft_ptr);
        if (std_ptr) free(std_ptr);
        return;
    }

    // Compare memory contents
    for (i = 0; i < nmemb * size; i++)
    {
        if (ft_ptr[i] != 0)
            pass = 0;
        if (std_ptr[i] != 0)
            std_pass = 0;
        if (ft_ptr[i] != std_ptr[i])
        {
            pass = 0;
            std_pass = 0;
            break;
        }
    }
    if (pass && std_pass)
        printf("ft_calloc(%zu, %zu): PASS (matches calloc, all bytes zero)\n", nmemb, size);
    else if (!pass && std_pass)
        printf("ft_calloc(%zu, %zu): FAIL (ft_calloc non-zero byte at %zu)\n", nmemb, size, i);
    else if (pass && !std_pass)
        printf("ft_calloc(%zu, %zu): FAIL (calloc non-zero byte at %zu)\n", nmemb, size, i);
    else
        printf("ft_calloc(%zu, %zu): FAIL (memory mismatch at %zu)\n", nmemb, size, i);

    free(ft_ptr);
    free(std_ptr);
}

int	main(void)
{
    // Normal allocations
    test_ft_calloc(10, sizeof(int));
    test_ft_calloc(100, 1);
    test_ft_calloc(1, 100);

    // Zero allocations
    test_ft_calloc(0, 10);
    test_ft_calloc(10, 0);
    test_ft_calloc(0, 0);

    // Large allocation (may fail depending on system)
    test_ft_calloc(1024 * 1024, 100);

    // Overflow test (should fail and return NULL)
    test_ft_calloc(SIZE_MAX, 2);

    return 0;
}

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