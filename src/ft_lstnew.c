#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void const *content, size_t content_size)
{
    t_list *new_node;

    // Allocate memory for the new node
    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;

    // Initialize the content
    if (content)
    {
        new_node->content = malloc(content_size);
        if (!new_node->content)
        {
            free(new_node);
            return NULL;
        }
        ft_memcpy(new_node->content, content, content_size);
        new_node->content_size = content_size;
    }
    else
    {
        new_node->content = NULL;
        new_node->content_size = 0;
    }

    // Initialize the next pointer
    new_node->next = NULL;

    return new_node;
}