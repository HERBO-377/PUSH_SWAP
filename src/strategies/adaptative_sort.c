/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:37:24 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/23 13:19:06 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_check(t_node **a, t_node **b, t_bench *bench)
{
	int	disorder;

	disorder = compute_disorder(*a);
	bench->disorder = disorder;
	if ((disorder / 100) < 20)
	{
		bench->strat = STRAT_SIMPLE;
		simple_sort(a, b, bench);
	}
	else if ((disorder / 100) < 50)
	{
		bench->strat = STRAT_MEDIUM;
		medium_sort(a, b, bench);
	}
	else
	{
		bench->strat = STRAT_COMPLEX;
		complex_sort(a, b, bench);
	}
}

void	adaptive_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	bench->is_adaptive = 1;
	if (!a || !b || !*a || check_order(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
	{
		dispatch_small(a, b, bench);
		return ;
	}
	adaptive_check(a, b, bench);
}
