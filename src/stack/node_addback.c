/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:32:43 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 10:32:47 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_addback(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	last = node_last(*lst);
	last->next = new;
	new->prev = last;
}
