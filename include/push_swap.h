/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:52:04 by daherman          #+#    #+#             */
/*   Updated: 2026/06/03 12:33:58 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

int	main(int arcg, char **argv);
char	**check_split(char *s);
long	ft_atol(char *s);

typedef struct s_node
{
	int		content;
	struct s_node 	*next;
	struct s_node 	*prev;
}	t_node;

#endif
