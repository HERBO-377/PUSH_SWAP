#include "push_swap.h"
#include <stdio.h>

static void print_list(t_node *lst)
{
    printf("STACK:\n");
    while (lst)
    {
        printf("content = %d | index = %d\n", lst->content, lst->index);
        lst = lst->next;
    }
    printf("NULL\n\n");
}

int main(void)
{
    t_node *stack = NULL;
    t_node *node;

    printf("=== TEST node_new + addback ===\n");
    node = node_new(10);
    node_addback(&stack, node);

    node = node_new(20);
    node_addback(&stack, node);

    node = node_new(30);
    node_addback(&stack, node);

    print_list(stack);

    printf("=== TEST addfront ===\n");
    node = node_new(5);
    node_addfront(&stack, node);

    print_list(stack);

    printf("=== TEST node_last ===\n");
    t_node *last = node_last(stack);
    if (last)
        printf("LAST NODE: %d\n\n", last->content);

    printf("=== TEST clear ===\n");
    node_clear(&stack);

    if (!stack)
        printf("STACK CLEARED SUCCESSFULLY\n");

    return 0;
}
