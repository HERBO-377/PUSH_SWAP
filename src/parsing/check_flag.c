/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandino <hfandino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:23:43 by hfandino          #+#    #+#             */
/*   Updated: 2026/06/13 12:24:23 by hfandino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_flags	init_flags(void)
{
	t_flags	f;

	f.simple = 0;
	f.medium = 0;
	f.complex = 0;
	f.adaptive = 0;
	return (f);
}

static int	is_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	else if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	else if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	else if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

static void	apply_flag(char *arg, t_flags *f)
{
	if (ft_strcmp(arg, "--simple") == 0)
		f->simple = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		f->medium = 1;
	else if (ft_strcmp(arg, "--complex") == 0)
		f->complex = 1;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		f->adaptive = 1;
	else
		error(1);
}

int	skip_flag(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] && is_flag(argv[i]))
		i++;
	return (i);
}

t_flags	check_flag(char **argv)
{
	t_flags	flags;
	int		i;
	int		count_flags;

	i = 1;
	count_flags = 0;
	flags = init_flags();
	while (argv[i] && is_flag(argv[i]))
	{
		apply_flag(argv[i], &flags);
		count_flags++;
		i++;
	}
	if (count_flags > 1)
		error(1);
	return (flags);
}
