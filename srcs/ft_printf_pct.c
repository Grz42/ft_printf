/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:18:20 by egrazina          #+#    #+#             */
/*   Updated: 2021/06/01 21:20:24 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pct(t_flags *flags, va_list args)
{
	int		count;

	ft_printf_star(flags, args);
	count = 0;
	if (flags->minus)
		count += ft_putchar('%');
	count += padding(flags->width - 1, flags->zero ? '0' : ' ');
	if (!flags->minus)
		count += ft_putchar('%');
	return (count);
}
