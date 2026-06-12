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
	t_node	*a;
	t_node	*b;
	t_flags	flags;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	flags = check_flag(argv);
	a = build_stack(argv);
	index_stack(a);
	ft_printf("SOLUTIONS: (program real output)\n\n");
	dispatch(&a, &b, flags);


//------- DEBUGG ---------

	ft_printf("\n\nDEBUGGING: (no disorder expected) \n\n");
	ft_printf("MISTAKE INDEX:\n[%d%%]\n\n", compute_disorder(a));
	print_list(a);
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
