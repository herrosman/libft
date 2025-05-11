#include "libft.h"
#include <stdlib.h>

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list *current;
    t_list *next;

    if (!alst || !*alst || !del)
        return;

    current = *alst;
    while (current)
    {
        next = current->next; // Save the next node
        ft_lstdelone(&current, del); // Delete the current node
        current = next; // Move to the next node
    }

    *alst = NULL; // Set the pointer to the list to NULL
}