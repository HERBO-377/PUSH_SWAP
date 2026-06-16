/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:10:42 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/11 15:46:18 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sort_3_cases(t_node **a, t_node *first,
		t_node *second, t_node *third, t_bench *bench)
{
	if (first->content < second->content
		&& second->content > third->content
		&& first->content < third->content)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first->content > second->content
		&& first->content < third->content)
		sa(a, bench);
	else if (first->content < second->content
		&& first->content > third->content)
		rra(a, bench);
	else if (first->content > second->content
		&& second->content < third->content
		&& first->content > third->content)
		ra(a, bench);
	else if (first->content > second->content
		&& second->content > third->content)
	{
		sa(a, bench);
		rra(a, bench);
	}
}

void	sort_3(t_node **a, t_bench *bench)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (check_order(*a))
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	sort_3_cases(a, first, second, third, bench);
}
