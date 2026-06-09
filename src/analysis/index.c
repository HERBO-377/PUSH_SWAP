#include "push_swap.h"

// --- assign each node an ordered index
void	assign_index(int *nums, t_node *stack, int size)
{
	while (stack)
	{
		stack->index = find_index(nums, size, stack->content);
		stack = stack->next;
	}
}

// --- coordinates all functions for indexing
void	index_stack(t_node *stack)
{
	int	size;
	int	*nums;

	size = stack_size(stack);
	nums = stack_to_arr(stack);
	sort_arr(nums, size);
	assign_index(nums, stack, size);
	free(nums);
}
