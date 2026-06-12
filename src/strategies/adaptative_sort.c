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

static void	small_sort(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
}

void	adaptive_sort(t_node **a, t_node **b)
{
	int	size;
	int	disorder;

	if (!a || !b || !*a || check_order(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
	{
		small_sort(a, b);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 20)
		simple_sort(a, b);
	else if (disorder < 50)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
