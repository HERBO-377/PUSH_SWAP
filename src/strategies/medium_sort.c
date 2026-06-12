/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:21:29 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/12 18:23:35 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static int	get_max_position(t_node *stack)
{
	int	pos;
	int	max_pos;
	int	max_index;

	pos = 0;
	max_pos = 0;
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	move_max_to_top(t_node **b)
{
	int	pos;
	int	size;

	pos = get_max_position(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		while (pos++ < size)
			rrb(b);
	}
}

static void	push_chunks_to_b(t_node **a, t_node **b, int size)
{
	int	chunk_size;
	int	limit;
	int	pushed;

	chunk_size = ft_sqrt(size);
	limit = chunk_size;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b);
			pushed++;
			if (*b && (*b)->index < limit - (chunk_size / 2))
				rb(b);
			if (pushed == limit && limit < size)
				limit += chunk_size;
			if (limit > size)
				limit = size;
		}
		else
			ra(a);
	}
}

void	medium_sort(t_node **a, t_node **b)
{
	int	size;

	if (!a || !b || !*a || check_order(*a))
		return ;
	size = stack_size(*a);
	if (size <= 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
	{
		push_chunks_to_b(a, b, size);
		while (*b)
		{
			move_max_to_top(b);
			pa(a, b);
		}
	}
}
