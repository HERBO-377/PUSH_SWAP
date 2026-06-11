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
	int		i;
	t_node	*stack;
	char	**tmp;
	t_flags	flags;

	i = 1;
	stack = NULL;
	if (argc < 2)
		return (0);
	flags = check_flag(argv);
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		tmp = check_split(argv[i]);
		if (!tmp)
			return (1);
		build_stack(&stack, tmp);
		i++;
	}
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
