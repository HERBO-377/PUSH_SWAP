/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daherman <daherman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:53:01 by daherman          #+#    #+#             */
/*   Updated: 2026/05/18 08:53:09 by daherman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putnbr_pf(int n);
int	ft_putunsigned_pf(unsigned int n);
int	ft_lowhexnbr_pf(unsigned int n);
int	ft_uphexnbr_pf(unsigned int n);
int	ft_pointernbr_pf(unsigned long n);
int	ft_putptr_pf(void *ptr);
int	ft_printf(const char *s, ...);
int	check_arg(char c, va_list args);

#endif
