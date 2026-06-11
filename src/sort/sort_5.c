/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:46:36 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/11 16:11:50 by hfandino         ###   ########.fr       */
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

static void	move_min_to_top(t_node **a)
{
	int	pos;
	int	size;

	pos = get_min_position(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a);
			pos++;
		}
	}
}

void	sort_5(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
