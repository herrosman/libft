#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
    if (!alst || !new)
        return;

    new->next = *alst; // Point the new node's next to the current head
    *alst = new;       // Update the head to the new node
}