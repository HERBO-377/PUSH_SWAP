/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:21:07 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 10:26:17 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_list(t_node *lst)
{
    ft_printf("STACK:\n");
    while (lst)
    {
        ft_printf("content = %d | index = %d\n", lst->content, lst->index);
        lst = lst->next;
    }
    ft_printf("NULL\n\n");
}

static void print_list_reverse(t_node *lst)
{
	ft_printf("REVERSELIST TO CHECK ->prev\nREVERSE STACK:\n");
	while (lst && lst->next)
        lst = lst->next;

	while (lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->prev;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack;
	char	**tmp;

	i = 1;
	stack = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tmp = check_split(argv[i]);
		if (!tmp)
			return (1);
		build_stack(&stack, tmp);
		print_list(stack);
		ft_printf("\n");
		print_list_reverse(stack);
	}
	if (argc > 2)
	{
		while (argv[i])
		{
			tmp = check_split(argv[i]);
			if (!tmp)
				return (1);
			build_stack(&stack, tmp);
			i++;
		}
	}
	print_list(stack);
	ft_printf("\n");
	print_list_reverse(stack);
	return (0);
}
