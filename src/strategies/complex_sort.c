/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:01:16 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/11 17:05:14 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *stack)
{
	int	max_index;
	int	max_bits;

	max_index = 0;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	complex_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			j++;
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}
