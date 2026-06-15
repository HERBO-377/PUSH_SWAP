/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:10:16 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/15 12:53:25 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_STRUCT_H
# define FLAG_STRUCT_H

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

#endif
