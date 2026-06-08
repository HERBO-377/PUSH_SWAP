/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:33:35 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 09:57:51 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			error(1);
		stack = stack->next;
	}
	return (0);
}

void	build_stack(t_node **stack, char **nums)
{
	long	n;
	int		i;

	i = 0;
	while (nums[i])
	{
		valid_num(nums[i]);
		n = ft_atol(nums[i]);
		check_range(n);
		check_duplicate(*stack, (int)n);
		node_addback(stack, node_new((int)n));
		i++;
	}
}
