/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:37:24 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/12 18:26:09 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size <= 2)
		sort_2(a, bench);
	else if (size == 3)
		sort_3(a, bench);
	else if (size <= 5)
		sort_5(a, b, bench);
}

void	adaptive_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	disorder;

	if (!a || !b || !*a || check_order(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
	{
		small_sort(a, b, bench);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder / 100 < 20)
		simple_sort(a, b, bench);
	else if (disorder / 100 < 50)
		medium_sort(a, b, bench);
	else
		complex_sort(a, b, bench);
}
