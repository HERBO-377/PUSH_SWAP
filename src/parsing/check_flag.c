#include "push_swap.h"

// --- Declaration of values for flag-structure
// 	all = 0 || all = off
static t_flags	init_flags(void)
{
	t_flags	f;

	f.simple = 0;
	f.medium = 0;
	f.complex = 0;
	f.adaptive = 0;
	return (f);
}

// --- Detect if a flag was given as argument
// 	0 = off (no) || 1 = on (yes)
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

// --- Detect specific flag in the argument and activate it
// 	0 = off || 1 = on
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

// --- Validates if flags are correctly written, located and no duplicated 
t_flags	check_flag(char **argv)
{
	t_flags	flags;
	int	i;
	int	count_flags;
	int	data_start;

	i = 1;
	count_flags = 0;
	data_start = 0;
	flags = init_flags();
	while (argv[i])
	{
		if (is_flag(argv[i]))
		{
			if(data_start)
				error(1);
			apply_flag(argv[i], &flags);
			count_flags++;
		}
		else
			data_start = 1;
		i++;
	}
	if (count_flags > 1)
		error(1);
	return (flags);
}
