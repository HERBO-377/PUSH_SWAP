/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:19:03 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/08 13:36:30 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf.h"

static int	reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = node_last(*stack);
	before_last = last->prev;
	*stack = last;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	before_last->next = NULL;
	return (1);
}

void	rra(t_node **a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	int	result_a;
	int	result_b;

	result_a = reverse_rotate(a);
	result_b = reverse_rotate(b);
	if (result_a || result_b)
		ft_printf("rrr\n");
}
