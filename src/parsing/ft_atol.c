/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:23:01 by daherman          #+#    #+#             */
/*   Updated: 2026/06/03 10:39:21 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	long	num;
	int	i;
	int	sign;

	num = 0;
	while (s[i])
	{
		while (s[i] == '+' || s[i] == '-')
		{
			if (s[i] == '-')
				sign *= -1;
			i++;
		}
		while (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] -'0');
			i++;
		}
		return (nb * sign);
	}
}
