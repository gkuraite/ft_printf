/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:19:59 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/28 16:50:00 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_valid(t_flags *f)
{
	if (f->plus)
		f->space = 0;
	if (f->minus || (f->precision != -6 && f->type != '%'))
		f->zero = 0;
	if (f->type == 's' && f->size == 3)
		f->type = 'S';
	if (f->type == 'd' || f->type == 'D' || f->type == 'i' || f->type == 'o' ||
			f->type == 'O' || f->type == 'u' || f->type == 'U' ||
			f->type == 'x' || f->type == 'X' || f->type == 'c' ||
			f->type == 'C' || f->type == '%' || f->type == 's' ||
			f->type == 'S' || f->type == 'p')
		return (1);
	return (0);
}

int		manage_size_flags(const char *restrict *format)
{
	if (**format == 'h')
	{
		if (*(++*format) == 'h' && (*format)++)
			return (1);
		return (2);
	}
	if (**format == 'l')
	{
		if (*(++*format) == 'l' && (*format)++)
			return (4);
		return (3);
	}
	if (**format == 'j' && (*format)++)
		return (5);
	if (**format == 'z' && (*format)++)
		return (6);
	return (0);
}

int		get_string(t_flags *f, va_list ap)
{
	if (f->type == 'd' || f->type == 'i' || f->type == 'D')
		return (dofortypeid(f, ap));
	if (f->type == 'o' || f->type == 'O')
		return (dofortypeo(f, ap));
	if (f->type == 'u' || f->type == 'U')
		return (dofortypeu(f, ap));
	if (f->type == 'x' || f->type == 'X')
		return (dofortypex(f, ap));
	if (f->type == 'c' || f->type == 'C')
		return (dofortypec(f, ap));
	if (f->type == '%')
		return (dofortypepc(f));
	if (f->type == 's' || f->type == 'S')
		return (dofortypes(f, ap));
	if (f->type == 'p')
		return (dofortypep(f, ap));
	return (0);
}
