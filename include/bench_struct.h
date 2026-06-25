/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:58:36 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/23 12:26:55 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_STRUCT_H
# define BENCH_STRUCT_H

# define STRAT_SIMPLE	1
# define STRAT_MEDIUM	2
# define STRAT_COMPLEX	3
# define STRAT_ADAPTIVE	4

typedef struct s_bench
{
	int			enabled;
	int			strat;
	int			is_adaptive;
	long long	disorder;
	int			total;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_bench;

#endif
