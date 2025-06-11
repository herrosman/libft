/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosman <aosman@42wolfsburg.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:56:24 by aosman            #+#    #+#             */
/*   Updated: 2025/06/10 19:56:55 by aosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int main(void)
{
	t_list *head = ft_lstnew("Node 1");
	ft_lstadd_front(&head, ft_lstnew("Node 2"));
	ft_lstadd_front(&head, ft_lstnew("Node 3"));

	int size = ft_lstsize(head);
	printf("List size: %d\n", size); // Should print 3

	// Free the list
	t_list *current = head;
	t_list *next_node;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	return 0;
}