/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:28:28 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 17:04:37 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		zero(t_flags *flags)
{
	flags->is_flag = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->size = 0;
}

static int		print_converter(t_flags *f, va_list *ap)
{
	if (f->format[f->i] == 'd' || f->format[f->i] == 'i'
		|| f->format[f->i] == 'D')
		return (converter_d(f, ap));
	if (f->format[f->i] == 'o' || f->format[f->i] == 'O')
		return (converter_o(f, ap));
	if (f->format[f->i] == 'u' || f->format[f->i] == 'U')
		return (converter_u(f, ap));
	if (f->format[f->i] == 'x' || f->format[f->i] == 'X')
		return (converter_x(f, ap));
	if (f->format[f->i] == 'c' || f->format[f->i] == 'C')
		return (converter_c(f, ap));
	if (f->format[f->i] == '%')
		return (converter_perc(f));
	if (f->format[f->i] == 's' || f->format[f->i] == 'S')
		return (converter_s(f, ap));
	if (f->format[f->i] == 'p')
		return (converter_p(f, ap));
	return (0);
}

static int		checking_printf(t_flags *f, va_list *ap)
{
	zero(f);
	f->i++;
	if (f->format[f->i] != '\0' &&
			ft_strchr(SUB_SPECIFIERS, f->format[f->i]))
	{
		check_flags(f);
		check_width(f);
		check_precision(f);
		check_size(f);
	}
	if (ft_strchr(SPECIFIERS, f->format[f->i]))
		return (print_converter(f, ap));
	return (0);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_flags			f;
	int				count;

	count = 0;
	va_start(ap, format);
	f.i = 0;
	f.format = format;
	if (!f.format)
		return (1);
	while (f.format[f.i])
	{
		if (f.format[f.i] == '%')
			count += checking_printf(&f, &ap);
		else if (f.format[f.i] == '\0')
			return (0);
		else
		{
			ft_putchar((char)f.format[f.i]);
			count++;
		}
		f.i++;
	}
	return (count);
}
