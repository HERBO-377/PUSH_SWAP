/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:33:35 by daherman          #+#    #+#             */
/*   Updated: 2026/06/15 12:02:48 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	check_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	check_num(char *arg, t_node **stack, char **tmp)
{
	long	n;

	if (!valid_num(arg))
	{
		free_split(tmp);
		node_clear(stack);
		error (1);
	}
	n = ft_atol(arg);
	if (!check_range(n))
	{
		free_split(tmp);
		node_clear(stack);
		error(1);
	}
	return ((int)n);
}

static void	process_nums(char **tmp, t_node **stack)
{
	int	i;
	int	n;

	i = 0;
	while (tmp[i])
	{
		n = check_num(tmp[i], stack, tmp);
		if (!check_duplicate(*stack, n))
		{
			free_split(tmp);
			node_clear(stack);
			error(1);
		}
		node_addback(stack, node_new(n));
		i++;
	}
}

t_node	*build_stack(char **argv)
{
	int		i;
	t_node	*stack;
	char	**tmp;

	i = skip_flag(argv);
	stack = NULL;
	while (argv[i])
	{
		tmp = check_split(argv[i]);
		if (!tmp || !tmp[0])
		{
			free_split(tmp);
			node_clear(&stack);
			error(1);
		}
		process_nums(tmp, &stack);
		free_split(tmp);
		i++;
	}
	if (!stack)
		error(1);
	return (stack);
}
