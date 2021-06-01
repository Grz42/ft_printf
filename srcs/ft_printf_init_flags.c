/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:09:57 by egrazina          #+#    #+#             */
/*   Updated: 2021/06/01 21:34:16 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->dot = -1;
	flags->width = 0;
	flags->len = 0;
	flags->type = '\0';
}

void	checkflag(const char f, t_flags *flags)
{
	if (f == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	if (f == '0' && flags->minus != 1 && flags->width == 0)
		flags->zero = 1;
	if (f == '.')
	{
		flags->dot = (flags->dot == -1) ? 0 : -2;
	}
	if (f == '*')
	{
		if (flags->dot == -1)
			flags->star = 1;
		else
			flags->star = (flags->star == 0) ? 2 : 3;
	}
}

int		readflag(t_flags *flags, const char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isnum(str[i]))
	{
		checkflag(str[i], flags);
		if (ft_isnum(str[i]))
			while (ft_isnum(str[i]))
			{
				if (flags->dot == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if (flags->dot >= 0)
					flags->dot = (flags->dot * 10) + (str[i] - '0');
				i++;
			}
		else
			i++;
	}
	flags->type = str[i];
	flags->len = i;
	return (i);
}
