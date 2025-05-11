#include "libft.h"
#include <stdlib.h>

void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (!alst || !*alst || !del)
        return;

    // Use the provided del function to free the content
    del((*alst)->content, (*alst)->content_size);

    // Free the memory of the link itself
    free(*alst);

    // Set the pointer to NULL
    *alst = NULL;
}