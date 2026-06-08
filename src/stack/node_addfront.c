/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_addfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:32:57 by daherman          #+#    #+#             */
/*   Updated: 2026/06/08 10:32:59 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_addfront(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	new->prev = NULL;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
