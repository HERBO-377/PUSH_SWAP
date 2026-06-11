/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:21:07 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 13:13:16 by daherman         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_node	*stack;
	t_flags	flags;

	stack = NULL;
	if (argc < 2)
		return (0);
	flags = check_flag(argv);
	stack = build_stack(argv);
	index_stack(stack);
	ft_printf("MISTAKE INDEX:\n[%d%%]\n\n", compute_disorder(stack));
	print_list(stack);
	ft_printf("\n");
	if (flags.simple)
		ft_printf("\n-SIMPLE MODE-\n");
	else if (flags.medium)
                ft_printf("\n-MEDIUM MODE-\n");
	else if (flags.complex)
                ft_printf("\n-COMPLEX MODE-\n");
	else if (flags.adaptive)
                ft_printf("\n-ADAPTIVE MODE-\n");

	return (0);
}
