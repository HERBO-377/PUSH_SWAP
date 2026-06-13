/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:58:50 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/13 12:06:41 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_STRUCT_H
# define NODE_STRUCT_H

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

#endif
