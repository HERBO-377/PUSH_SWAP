/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:33:35 by daherman          #+#    #+#             */
/*   Updated: 2026/06/13 12:25:15 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	check_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			error(1);
		stack = stack->next;
	}
}

static int	check_num(char *arg)
{
	long	n;

	valid_num(arg);
	n = ft_atol(arg);
	check_range(n);
	return ((int)n);
}

static void	process_nums(char **tmp, t_node **stack)
{
	int	i;
	int	n;

	i = 0;
	while (tmp[i])
	{
		n = check_num(tmp[i]);
		check_duplicate(*stack, n);
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
		if (!tmp)
			error(1);
		process_nums(tmp, &stack);
		free_split(tmp);
		i++;
	}
	if (!stack)
		error(1);
	return (stack);
}
