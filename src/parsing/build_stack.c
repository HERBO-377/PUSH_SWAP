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

static int	check_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			error(1);
		stack = stack->next;
	}
	return (0);
}

static int	check_num(char *arg)
{
	long	n;

	valid_num(arg);
	n = ft_atol(arg);
	check_range(n);
	return ((int)n);
}

t_node	*build_stack(char **argv)
{
	int	i;
	int	j;
	long	n;
	t_node	*stack;
	char	**tmp;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		tmp = check_split(argv[i]);
		if (!tmp)
			error(1);
		j = 0;
		while(tmp[j])
		{
			n = check_num(tmp[j]);
			check_duplicate(stack, n);
			node_addback(&stack, node_new(n));
			j++;
		}
		free_split(tmp);
		i++;
	}
	return (stack);
}



















