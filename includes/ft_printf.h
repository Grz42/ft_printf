/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:27:07 by egrazina          #+#    #+#             */
/*   Updated: 2021/06/01 21:33:03 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_flags
{
	int minus;
	int zero;
	int star;
	int dot;
	int width;
	int len;
	char type;
 } 				t_flags;

int				padding (int n, char c);
int				ft_isnum(int c);
int				ft_putnbr(int n);
int				ft_numlen(int num);
int				ft_strlen(char *s);
int				ft_putchar(char c);
void			init_flags(t_flags *flags);
int				ft_putflags(int condition, char c);
void			checkflag(const char f, t_flags *flags);
int				readflag(t_flags *flags, const char *str);
int				ft_isconversion(t_flags *flags, va_list args);
char			*ft_itoa_base(unsigned long int n, char type);
int				ft_printf_d(t_flags *flags, va_list args);
int				ft_printf_c(t_flags *flags, va_list args);
int				ft_printf_s(t_flags *flags, va_list args);
int				ft_printf_x(t_flags *flags, va_list args);
int				ft_printf_u(t_flags *flags, va_list args);
int				ft_printf_p(t_flags *flags, va_list args);
int				ft_printf_pct(t_flags *flags, va_list args);
int				ft_printf(const char *str, ...);
void			ft_printf_star(t_flags *flags, va_list args);

 # endif