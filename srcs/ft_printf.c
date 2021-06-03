/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:35:55 by egrazina          #+#    #+#             */
/*   Updated: 2021/06/02 16:47:24 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			init_flags(&flags);
			str++;
			readflag(&flags, str);
			count += ft_isconversion(&flags, args);
			str = str + flags.len;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
