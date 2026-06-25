/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 08:56:57 by daherman          #+#    #+#             */
/*   Updated: 2026/06/23 13:05:18 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_bench *b)
{
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd(b->disorder / 100, 2);
	ft_putchar_fd('.', 2);
	if (b->disorder % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(b->disorder % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	print_strat(t_bench *b)
{
	if (b->is_adaptive)
	{
		ft_putstr_fd("[bench] Strategy: Adaptive / ", 2);
		if (b->strat == STRAT_SIMPLE)
			ft_putendl_fd("O(n²)", 2);
		else if (b->strat == STRAT_MEDIUM)
			ft_putendl_fd("O(n√n)", 2);
		else
			ft_putendl_fd("O(n log n)", 2);
	}
	else if (b->strat == STRAT_SIMPLE)
		ft_putendl_fd("[bench] Strategy: Simple / O(n²)", 2);
	else if (b->strat == STRAT_MEDIUM)
		ft_putendl_fd("[bench] Strategy: Medium / O(n√n)", 2);
	else
		ft_putendl_fd("[bench] Strategy: Complex / O(n log n)", 2);
}

static void	print_ops1(t_bench *b)
{
	ft_putstr_fd("[bench] Total_ops: ", 2);
	ft_putnbr_fd(b->total, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_ops2(t_bench *b)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(b->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_bench *b)
{
	ft_putendl_fd("     [BENCH MODE]", 2);
	print_disorder(b);
	print_strat(b);
	print_ops1(b);
	print_ops2(b);
}
