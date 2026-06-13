/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:12:41 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/13 12:12:48 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STRUCT_H
# define PARSE_STRUCT_H

# include "node_struct.h"
# include "flag_struct.h"

typedef struct s_parse
{
	t_node	*stack;
	t_flags	flag;
}	t_parse;

#endif
