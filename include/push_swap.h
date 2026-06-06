/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:52:04 by daherman          #+#    #+#             */
/*   Updated: 2026/06/06 14:56:59 by hfandino         ###   ########.fr       */
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

char	**check_split(char *s);
long	ft_atol(char *s);
int		error(int n);
int		valid_num(char *s);
int		check_range(long n);
void	node_addback(t_node **lst, t_node *new);
void	node_addfront(t_node **lst, t_node *new);
void	node_clear(t_node **lst);
t_node	*node_last(t_node *node);
t_node	*node_new(int content);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

# include "libft.h"

#endif
