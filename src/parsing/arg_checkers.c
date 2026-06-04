/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:23:01 by daherman          #+#    #+#             */
/*   Updated: 2026/06/04 12:36:50 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// --- Printing Error\n in case of error
void	error(int n)
{
	ft_printf("Error\n");
	exit (n);
}

// ---  Check argument to remove spaces
char	**check_split(char *s)
{
	char	**arr;

	arr = ft_split(s, ' ');
	if (!arr || !arr[0])
		error(1);
	return (arr);
}

// --- Validation of number only accepts 1 sign(+/-) before num
int	valid_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (error(1));
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (error(1));
		i++;
	}
	return (1);
}

// --- Make the string number from the argument to real number (long)
long	ft_atol(char *s)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * sign);
}

// --- Check if the number is between INT_MAX and INT_MIN
int	check_range(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (error(1));
	return (1);
}
