/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:12:36 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/13 12:22:00 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	last = node_last(*stack);
	*stack = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (1);
}

void	ra(t_node **a, t_bench *bench)
{
	if (rotate(a))
	{
		ft_printf("ra\n");
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_node **b, t_bench *bench)
{
	if (rotate(b))
	{
		ft_printf("rb\n");
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_node **a, t_node **b, t_bench *bench)
{
	int	result_a;
	int	result_b;

	result_a = rotate(a);
	result_b = rotate(b);
	if (result_a || result_b)
	{
		ft_printf("rr\n");
		bench->rr++;
		bench->total++;
	}
}
