#include "push_swap.h"

// --- Check if the stack need to be sorted before call any sort function
int	check_order(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
