/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:10:42 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/17 10:25:05 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_cases(t_node **a, t_trio *t, t_bench *bench)
{
	if ((t->first->content) < (t->second->content)
		&& (t->second->content) > (t->third->content)
		&& (t->first->content) < (t->third->content))
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if ((t->first->content) > (t->second->content)
		&& (t->first->content) < (t->third->content))
		sa(a, bench);
	else if ((t->first->content) < (t->second->content)
		&& (t->first->content) > (t->third->content))
		rra(a, bench);
	else if ((t->first->content) > (t->second->content)
		&& (t->second->content) < (t->third->content)
		&& (t->first->content) > (t->third->content))
		ra(a, bench);
	else if ((t->first->content) > (t->second->content)
		&& (t->second->content) > (t->third->content))
	{
		sa(a, bench);
		rra(a, bench);
	}
}

void	sort_3(t_node **a, t_bench *bench)
{
	t_trio	t;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	if (check_order(*a))
		return ;
	t.first = *a;
	t.second = t.first->next;
	t.third = t.second->next;
	sort_3_cases(a, &t, bench);
}
