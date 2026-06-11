#include "push_swap.h"

// --- Declaration of values for flag-structure
static t_flags	init_flags(void)
{
	t_flags	f;

	f.simple = 0;
	f.medium = 0;
	f.complex = 0;
	f.adaptive = 0;
	return (f);
}

// --- Detect wich flag is in the argument activate them as boolean
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

	i = 1;
	count_flags = 0;
	flags = init_flags();
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			apply_flag(argv[i], &flags);
			count_flags++;
		}
		i++;
	}
	if (count_flags > 1)
		error(1);
	return (flags);
}
