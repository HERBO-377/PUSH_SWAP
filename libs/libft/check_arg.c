/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:51:59 by daherman          #+#    #+#             */
/*   Updated: 2026/05/18 08:57:17 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(void *ptr)
{
	int				i;
	unsigned long	n;

	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (unsigned long)ptr;
	write(1, "0x", 2);
	i += 2;
	i += ft_pointernbr_pf(n);
	return (i);
}

int	check_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned_pf(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_lowhexnbr_pf(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_uphexnbr_pf(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
