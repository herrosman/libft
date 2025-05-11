#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    if (!lst || !f)
        return;

    while (lst)
    {
        f(lst); // Apply the function to the current node
        lst = lst->next; // Move to the next node
    }
}