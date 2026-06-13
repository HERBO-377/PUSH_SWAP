/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:17:11 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/13 12:19:01 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// --- Get size of STACK_A
int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// --- Copy STACK_A into an array
int	*stack_to_arr(t_node *stack)
{
	int	*nums;
	int	stack_len;
	int	i;

	i = 0;
	stack_len = stack_size(stack);
	nums = malloc(stack_len * sizeof(int));
	if (!nums)
		return (0);
	while (stack)
	{
		nums[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (nums);
}

// --- Sort array from lower to higher
void	sort_arr(int *nums, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

// --- Look for ordered index in array
int	find_index(int *nums, int size, int content)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nums[i] == content)
			return (i);
		i++;
	}
	return (-1);
}
