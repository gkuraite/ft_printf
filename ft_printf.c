/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:28:28 by gkuraite          #+#    #+#             */
/*   Updated: 2018/07/18 11:38:24 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		zero(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->size = 0;
	flags->type = 0;
}

//static t_flags fill_the_flags(const char **restirct format, va)

static t_flags	is_there_a_flag(const char **restrict format)
{
	t_flags		flags;

	zero(&flags);
	if (**format == '%')
	{
		(*format)++;
		while (*format && (**format == '+' || **format == '-' || **format == ' '
					|| **format == '#' || **format == '0'))
		{
			if (**format == '+')
				flags.plus = 1;
			if (**format == '-')
				flags.minus = 1;
			if (**format == '0')
				flags.zero = 1;
			if (**format == ' ')
				flags.space = 1;
			format++;
		}
	}
		return (flags);
}

int				ft_printf(const char * format, ...)
{
	t_flags			flags;
	va_list			ap;
	unsigned int	ret;

	va_start(ap, format);
	ret = 0;
	if (!format)
		return (1);
	while (*format)
	{
		if (*format == '%')
		{
			flags = is_there_a_flag(&format);
		}
		else if (++ret && *format)
			ft_putchar(*format);
		format++;
	}
	return(ret);
}
