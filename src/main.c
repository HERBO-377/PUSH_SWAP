/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:21:07 by daherman          #+#    #+#             */
/*   Updated: 2026/06/04 09:41:57 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	char	**tmp;

	i = 1;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tmp = check_split(argv[i]);
		if (!tmp)
			return (1);
		j = 0;
		while (tmp[j])
		{
			valid_num(tmp[j]);
			num = ft_atol(tmp[j]);
			check_range(num);
			j++;
		}
		j = 0;
		while (tmp[j])
		{
			ft_printf("[%i]\n", num);
			j++;
		}
	}
	if (argc > 2)
		return (0);
	return (0);
}
