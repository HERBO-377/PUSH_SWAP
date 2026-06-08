/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:37:01 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 10:41:08 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_node *lst)
{
	ft_printf("STACK:\n");
	while (lst)
	{
		ft_printf("content = %d | index = %d\n", lst->content, lst->index);
		lst = lst->next;
	}
	ft_printf("NULL\n\n");
}

int	main(void)
{
	t_node	*stack;
	t_node	*node;
	t_node	*last;

	stack = NULL;
	ft_printf("=== TEST node_new + addback ===\n");
	node = node_new(10);
	node_addback(&stack, node);
	node = node_new(20);
	node_addback(&stack, node);
	node = node_new(30);
	node_addback(&stack, node);
	ft_print_list(stack);
	ft_printf("=== TEST addfront ===\n");
	node = node_new(5);
	node_addfront(&stack, node);
	ft_print_list(stack);
	ft_printf("=== TEST node_last ===\n");
	last = node_last(stack);
	if (last)
		ft_printf("LAST NODE: %d\n\n", last->content);
	ft_printf("=== TEST clear ===\n");
	node_clear(&stack);
	if (!stack)
		ft_printf("STACK CLEARED SUCCESSFULLY\n");
	return (0);
}
