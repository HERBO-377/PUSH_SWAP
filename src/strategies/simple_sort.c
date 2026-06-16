/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:37:56 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/12 18:13:11 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_position(t_node *stack)
{
	int	pos;
	int	min_pos;
	int	min_index;

	pos = 0;
	min_pos = 0;
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_node **a, t_bench *bench)
{
	int	pos;
	int	size;

	pos = get_min_position(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a, bench);
			pos++;
		}
	}
}

void	simple_sort(t_node **a, t_node **b, t_bench *bench)
{
	if (!a || !*a || check_order(*a))
		return ;
	while (*a)
	{
		move_min_to_top(a, bench);
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}
