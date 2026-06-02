/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:54:24 by daherman          #+#    #+#             */
/*   Updated: 2026/05/18 09:02:11 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int		i;
	char	c;
	long	num;

	num = n;
	i = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		i++;
	}
	if (num >= 10)
		i += ft_putnbr_pf(num / 10);
	c = (num % 10) + '0';
	write (1, &c, 1);
	i++;
	return (i);
}

int	ft_putunsigned_pf(unsigned int n)
{
	int		i;
	char	c;

	i = 0;
	if (n >= 10)
		i += ft_putunsigned_pf(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_lowhexnbr_pf(unsigned int n)
{
	int		i;
	char	c;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		i += ft_lowhexnbr_pf(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_uphexnbr_pf(unsigned int n)
{
	int		i;
	char	c;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_uphexnbr_pf(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_pointernbr_pf(unsigned long n)
{
	int		i;
	char	c;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		i += ft_pointernbr_pf(n / 16);
	c = base[n % 16];
	write (1, &c, 1);
	i++;
	return (i);
}
