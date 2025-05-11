#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *new_list = NULL;
    t_list *current = NULL;
    t_list *new_node;

    if (!lst || !f)
        return NULL;

    while (lst)
    {
        // Apply the function to the current node
        new_node = f(lst);
        if (!new_node)
        {
            // Free all previously allocated nodes in the new list
            while (new_list)
            {
                current = new_list->next;
                free(new_list->content);
                free(new_list);
                new_list = current;
            }
            return NULL;
        }

        // Add the new node to the new list
        if (!new_list)
        {
            new_list = new_node; // Initialize the new list with the first node
            current = new_list;
        }
        else
        {
            current->next = new_node; // Append the new node to the list
            current = current->next;
        }

        lst = lst->next; // Move to the next node in the original list
    }

    return new_list;
}