/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:21:07 by daherman          #+#    #+#             */
/*   Updated: 2026/06/12 18:39:20 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_flags	flags;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	flags = check_flag(argv);
	a = build_stack(argv);
	if (!a)
		return (1);
	index_stack(a);
	dispatch(&a, &b, flags);
	node_clear(&a);
	node_clear(&b);
	return (0);
}
