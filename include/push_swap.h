/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:52:04 by daherman          #+#    #+#             */
/*   Updated: 2026/06/10 11:51:38 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "node_struct.h"
# include "flag_struct.h"
# include "parse_struct.h"

//-------PARSING FUNCTIONS
char	**check_split(char *s);
long	ft_atol(char *s);
int		error(int n);
int		valid_num(char *s);
int		check_range(long n);
t_node	*build_stack(char **argv);
t_flags	check_flag(char **argv);
//-------STACK FUNCTIONS
void	node_addback(t_node **lst, t_node *new);
void	node_addfront(t_node **lst, t_node *new);
void	node_clear(t_node **lst);
t_node	*node_last(t_node *node);
t_node	*node_new(int content);
//-------ANALYSIS FUNCTIONS
int	compute_disorder(t_node *stack);
int	stack_size(t_node *stack);
int	*stack_to_arr(t_node *stack);
void	sort_arr(int *nums, int size);
int	find_index(int *nums, int size, int content);
void    assign_index(int *nums, t_node *stack, int size);
void    index_stack(t_node *stack);
//-------OPERATIONS FUNCTIONS
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
//-------SORT FUNTIONS
void	sort_2(t_node **a);

# include "libft.h"

#endif
