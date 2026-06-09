#include "push_swap.h"

// --- DEBUG: print array
static void print_array(int *arr, int size)
{
    int i = 0;

    ft_printf("ARRAY:\n");
    while (i < size)
    {
        ft_printf("[%d] ", arr[i]);
        i++;
    }
    ft_printf("\n\n");
}

// --- DEBUG: print stack
static void print_stack(t_node *stack)
{
    ft_printf("STACK:\n");
    while (stack)
    {
        ft_printf("content = %d | index = %d\n",
            stack->content, stack->index);
        stack = stack->next;
    }
    ft_printf("\n");
}

// --- SIMPLE build for test (puedes usar el tuyo si quieres)
static void build_test_stack(t_node **stack, char **nums)
{
    int i = 0;
    long n;

    while (nums[i])
    {
        n = ft_atol(nums[i]);
        node_addback(stack, node_new((int)n));
        i++;
    }
}

int main(void)
{
    t_node *stack = NULL;
    int *arr;
    int size;

    // ===============================
    // INPUT TEST CASE
    // ===============================
    char *input[] = {"5", "1", "4", "2", "3", NULL};

    ft_printf("=== BUILD STACK ===\n");
    build_test_stack(&stack, input);
    print_stack(stack);

    // ===============================
    // SIZE TEST
    // ===============================
    size = stack_size(stack);
    ft_printf("SIZE: %d\n\n", size);

    // ===============================
    // COPY TEST
    // ===============================
    arr = stack_to_arr(stack);
    ft_printf("=== COPY ARRAY ===\n");
    print_array(arr, size);

    // ===============================
    // SORT TEST
    // ===============================
    sort_arr(arr, size);
    ft_printf("=== SORTED ARRAY ===\n");
    print_array(arr, size);

    // ===============================
    // INDEX TEST
    // ===============================
    assign_index(arr, stack, size);
    ft_printf("=== STACK WITH INDEX ===\n");
    print_stack(stack);

    free(arr);
    node_clear(&stack);

    return (0);
}
