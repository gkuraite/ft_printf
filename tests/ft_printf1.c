/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:58:56 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/03 16:44:44 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		zero(t_flags *flags)
{
	flags->hash = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->type = 0;
	flags->width = 0;
	flags->precision = -6;
	flags->size = 0;
	flags->contentc = -1;
}

static t_flags	fill_flags2(const char *restrict *form, t_flags f, va_list ap)
{
	if (ft_isdigit(**form))
		f.width = ft_atoiptr(form);
	else if (**form == '*' && *(*form)++)
		f.width = va_arg(ap, int);
	if (**form == '.')
	{
		if (ft_isdigit(*(++*form)))
			f.precision = ft_atoiptr(form);
		else if (**form == '*' && *(*form)++)
			f.precision = va_arg(ap, int);
		else
			f.precision = 0;
	}
	if (**form == 'h' || **form == 'l' || **form == 'j' || **form == 'z')
		f.size = manage_size_flags(form);
	if (*form)
		f.type = **form;
	return (f);
}

static t_flags	fill_flags(const char *restrict *format, va_list ap)
{
	t_flags	flags;

	zero(&flags);
	if (**format == '%')
	{
		(*format)++;
		while (*format && (**format == '#' || **format == '-' || **format == '+'
				|| **format == ' ' || **format == '0'))
		{
			if (**format == '#')
				flags.hash = 1;
			if (**format == '-')
				flags.minus = 1;
			if (**format == '+')
				flags.plus = 1;
			if (**format == ' ')
				flags.space = 1;
			if (*(*format)++ == '0')
				flags.zero = 1;
		}
		return (fill_flags2(format, flags, ap));
	}
	return (flags);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_flags			f;
	unsigned int	ret;

	ret = 0;
	va_start(ap, format);
	if (!format)
		return (1);
	while (*format)
	{
		if (*format == '%')
		{
			f = fill_flags(&format, ap);
			if (is_valid(&f))
				ret += get_string(&f, ap);
		}
		else if (++ret && *format)
			ft_putchar(*format);
		format++;
	}
	return (ret);
}
