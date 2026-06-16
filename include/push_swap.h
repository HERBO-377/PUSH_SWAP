/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:52:04 by daherman          #+#    #+#             */
/*   Updated: 2026/06/15 12:59:18 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "flag_struct.h"
# include "libft.h"
# include "node_struct.h"
# include "parse_struct.h"
# include "bench_struct.h"

/* PARSING FUNCTIONS */
char	**check_split(char *s);
long	ft_atol(char *s);
int		error(int n);
int		valid_num(char *s);
int		check_range(long n);
int		skip_flag(char **argv);
t_node	*build_stack(char **argv);
t_flags	check_flag(char **argv);

/* STACK FUNCTIONS */
void	node_addback(t_node **lst, t_node *new);
void	node_addfront(t_node **lst, t_node *new);
void	node_clear(t_node **lst);
t_node	*node_last(t_node *node);
t_node	*node_new(int content);

/* ANALYSIS FUNCTIONS */
int		compute_disorder(t_node *stack);
int		stack_size(t_node *stack);
int		*stack_to_arr(t_node *stack);
void	sort_arr(int *nums, int size);
int		find_index(int *nums, int size, int content);
void	assign_index(int *nums, t_node *stack, int size);
void	index_stack(t_node *stack);
int		check_order(t_node *stack);

/* OPERATIONS FUNCTIONS */
void	sa(t_node **a, t_bench *bench);
void	sb(t_node **b, t_bench *bench);
void	ss(t_node **a, t_node **b, t_bench *bench);
void	pa(t_node **a, t_node **b, t_bench *bench);
void	pb(t_node **a, t_node **b, t_bench *bench);
void	ra(t_node **a, t_bench *bench);
void	rb(t_node **b, t_bench *bench);
void	rr(t_node **a, t_node **b, t_bench *bench);
void	rra(t_node **a, t_bench *bench);
void	rrb(t_node **b, t_bench *bench);
void	rrr(t_node **a, t_node **b, t_bench *bench);

/* SORT FUNCTIONS */
void	sort_2(t_node **a, t_bench *bench);
void	sort_3(t_node **a, t_bench *bench);
void	sort_5(t_node **a, t_node **b, t_bench *bench);
void	complex_sort(t_node **a, t_node **b, t_bench *bench);
void	simple_sort(t_node **a, t_node **b, t_bench *bench);
void	medium_sort(t_node **a, t_node **b, t_bench *bench);
void	adaptive_sort(t_node **a, t_node **b, t_bench *bench);

/* DISPATCH FUNCTIONS */
void	dispatch(t_node **a, t_node **b, t_flags flags, t_bench *bench);

/* BENCH FUNCTIONS */
t_bench	check_bench_strat(t_flags f);
void	print_bench(t_bench *b);

#endif
