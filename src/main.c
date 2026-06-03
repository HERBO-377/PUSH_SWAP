#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	**tmp;

	i = 1;
	// arg num check
	if (argc < 2)
		return (0);
	// 1st arg check if no-num no party 
	if (argc == 2)
	{
		tmp = check_split(argv[i]);
		if (!tmp)
			return (1);
	// Debugging 1 arg
		j = 0;
		while (tmp[j])
		{
			ft_printf("[%s]\n", tmp[j]);
			j++;
		}
	}
	// if (argc > 2)
	return (0);
}
