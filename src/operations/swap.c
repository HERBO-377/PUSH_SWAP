/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:04:57 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/05 20:35:32 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	
	if (!stack || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = (*stack)->next->next;
	
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*stack = second; 

}


