/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:04:57 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/13 12:23:05 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*stack = second;
	return (1);
}

void	sa(t_node **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_node **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	int	result_a;
	int	result_b;

	result_a = swap(a);
	result_b = swap(b);
	if (result_a || result_b)
		ft_printf("ss\n");
}
