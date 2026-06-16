/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:30:17 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/12 18:30:30 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dispatch_small(t_node **a, t_node **b, t_bench *bench)
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

static int	is_small(t_node *a)
{
	return (stack_size(a) <= 5);
}

static int	dispatch_flag(t_node **a, t_node **b, t_flags flags, t_bench *bench)
{
	if (flags.simple)
		simple_sort(a, b, bench);
	else if (flags.medium)
		medium_sort(a, b, bench);
	else if (flags.complex)
		complex_sort(a, b, bench);
	else if (flags.adaptive)
		adaptive_sort(a, b, bench);
	else
		return (0);
	return (1);
}

void	dispatch(t_node **a, t_node **b, t_flags flags, t_bench *bench)
{
	if (!a || !*a || check_order(*a))
		return ;
	if (is_small(*a))
	{
		dispatch_small(a, b, bench);
		return ;
	}
	if (dispatch_flag(a, b, flags, bench))
		return ;
	adaptive_sort(a, b, bench);
}
