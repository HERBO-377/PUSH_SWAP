/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:23:21 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/15 12:36:20 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf.h"

static int	push(t_node **dest, t_node **src)
{
	t_node	*src_top;
	t_node	*new_src_top;
	t_node	*dest_top;

	if (!*src)
		return (0);
	src_top = *src;
	new_src_top = src_top->next;
	dest_top = *dest;
	*src = new_src_top;
	if (new_src_top)
		new_src_top->prev = NULL;
	src_top->next = dest_top;
	if (dest_top)
		dest_top->prev = src_top;
	src_top->prev = NULL;
	*dest = src_top;
	return (1);
}

void	pa(t_node **a, t_node **b, t_bench *bench)
{
	if (push(a, b))
	{
		ft_printf("pa\n");
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_node **a, t_node **b, t_bench *bench)
{
	if (push(b, a))
	{
		ft_printf("pb\n");
		bench->pb++;
		bench->total++;
	}
}
