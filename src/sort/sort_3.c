/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:10:42 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/10 13:11:27 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_3(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (check_order(*a))
		return ;

	first = *a;
	second = first-next;
	third = second->next;
	if ((first->content > second->content) && (second->content < third->content))
		ra(a);
	
	
	

}
