#include "push_swap.h"
#include "libft.h"

int	arr_len(char **arr)
{
	int	i;
	
	while (arr[i])
		i++;
	return (i);
}

// Check if arg only have number and remove spaces
char	**arg_check_split(char *s)
{
	int	i;
	char	**arr;

	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == '\0')
			break;
		if (!ft_isdigit(s[i]))
			return (ft_printf("Error\n"), NULL);
		i++;
	}
	arr = ft_split(s, ' ');
	return (arr);
}

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
		full_list = arg_check_split(argv[i]);
		if (!full_list)
			return (1);
	// Debugging 1 arg
		j = 0;
		while (full_list[j])
		{
			ft_printf("[%s]\n", full_list[j]);
			j++;
		}
	}
	if (argc > 2)
	{
		while (argv[i])
		{
			j = 0;
			tmp = arg_check_split(argv[i]);
			if (!tmp)
				return (1);

			
			i++;
		}
		
	}

	return (0);
}
