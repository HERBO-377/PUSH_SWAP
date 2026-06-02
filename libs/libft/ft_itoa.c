/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:57:34 by daherman          #+#    #+#             */
/*   Updated: 2026/04/30 09:10:36 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int		len;
	long	num;

	num = n;
	len = 0;
	if (num <= 0)
	{
		len++;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	num_to_str(char *s, int n, int len)
{
	long	num;
	int		i;

	num = n;
	i = len - 1;
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	if (num == 0)
	{
		s[0] = '0';
		return ;
	}
	while (num > 0)
	{
		s[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = num_len(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	num_to_str(s, n, len);
	s[len] = '\0';
	return (s);
}
