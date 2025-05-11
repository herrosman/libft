#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node with modified content
t_list *modify_node(t_list *elem)
{
    if (!elem || !elem->content)
        return NULL;

    char *new_content = ft_strjoin((char *)elem->content, " - mapped");
    if (!new_content)
        return NULL;

    return ft_lstnew(new_content, ft_strlen(new_content) + 1);
}

// Function to print the content of a node
void print_node(t_list *elem)
{
    if (elem && elem->content)
        printf("Node content: %s\n", (char *)elem->content);
}

int main(void)
{
    // Create a linked list with multiple nodes
    char *str1 = ft_strdup("Node 1: Hello, World!");
    char *str2 = ft_strdup("Node 2: This is a test.");
    char *str3 = ft_strdup("Node 3: Another node.");
    char *str4 = ft_strdup("Node 4: Final node.");

    t_list *node1 = ft_lstnew(str1, ft_strlen(str1) + 1);
    t_list *node2 = ft_lstnew(str2, ft_strlen(str2) + 1);
    t_list *node3 = ft_lstnew(str3, ft_strlen(str3) + 1);
    t_list *node4 = ft_lstnew(str4, ft_strlen(str4) + 1);

    // Link the nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Print the original list
    printf("Original list:\n");
    ft_lstiter(node1, print_node);

    // Create a new list using ft_lstmap
    t_list *new_list = ft_lstmap(node1, modify_node);

    // Print the new list
    printf("\nMapped list:\n");
    ft_lstiter(new_list, print_node);

    // Free the original list
    t_list *current = node1;
    t_list *next;
    while (current)
    {
        next = current->next;
        free(current->content);
        free(current);
        current = next;
    }

    // Free the new list
    current = new_list;
    while (current)
    {
        next = current->next;
        free(current->content);
        free(current);
        current = next;
    }

    return 0;
}