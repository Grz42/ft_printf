/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:50:57 by egrazina          #+#    #+#             */
/*   Updated: 2021/06/01 21:46:48 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(int n, char c)
{
	int count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(c);
	return (count);
}

int	ft_printf_c(t_flags *flags, va_list args)
{
	int		count;
	char	c;

	ft_printf_star(flags, args);
	c = va_arg(args, int);
	count = 0;
	if (flags->minus == 1)
		count = ft_putchar(c) + padding(flags->width - 1, ' ');
	else
		count = padding(flags->width - 1, ' ') + ft_putchar(c);
	return (count);
}
