#include "push_swap.h"

// --- Decides based on the size of stack a
static void	check_size(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
		complex_sort(a, b);
}

static void	dispatch_simple(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else
		sort_5(a, b);
}

static void	dispatch_adaptive(t_node **a, t_node **b)
{
	int	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 20)
		sort_2(a, b);
	else
		complex_sort(a, b);
}

// --- Decides based on the flag given - Boolean to activate
// 	0 = off || 1 = on
//    flag = no || flag = yes
static int	dispatch_flag(t_node **a, t_node **b, t_flags flags)
{
	if (flags.simple)
	{
		dispatch_simple(a, b);
		return (1);
	}
	else if (flags.medium)
	{
		sort_5(a, b);
		return (1);
	}
	else if (flags.complex)
	{
		complex_sort(a, b);
		return (1);
	}
	else if (flags.adaptive)
	{
		dispatch_adaptive(a, b);
		return (1);
	}
	return (0);
}

// Coordinates posible decisions based on priority
void	dispatch(t_node **a, t_node **b, t_flags flags)
{
	if (check_order(*a))
		return ;
	else if (dispatch_flag(a, b, flags) == 1)
		return ;
	check_size(a, b);
}
