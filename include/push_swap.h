/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:52:04 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 13:08:50 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_node
{
	int                             content; // numero original
	int				index; // numero normalizado 
	struct s_node	*next; //sig nodo.
	struct s_node	*prev;
}	t_node;
//PARSING FUNCTIONS
char	**check_split(char *s);
long	ft_atol(char *s);
int		error(int n);
int		valid_num(char *s);
int		check_range(long n);
int		check_duplicate(t_node *stack, int n);
void	build_stack(t_node **stack, char **nums);
//STACK FUNCTIONS
void	node_addback(t_node **lst, t_node *new);
void	node_addfront(t_node **lst, t_node *new);
void	node_clear(t_node **lst);
t_node	*node_last(t_node *node);
t_node	*node_new(int content);
//ANALYSIS FUNCTIONS
int	compute_disorder(t_node *stack);
//OPERATIONS FUNCTIONS
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

# include "libft.h"

#endif
