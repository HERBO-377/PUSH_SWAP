#include "push_swap.h"

static int	search_flag(char *arg)
{
	if (!arg)
		return (0);
	if (arg[0] != '-' || arg[1] != '-')
		return (0);
	if (ft_strcmp(arg, "--simple"))
		return (1);
	if (ft_strcmp(arg, "--medium"))
		return (1);
	if (ft_strcmp(arg, "--complex"))
		return (1);
	if (ft_strcmp(arg, "--adaptative"))
		return (1);
	return (0);
}


