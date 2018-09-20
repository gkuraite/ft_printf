/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:35:55 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/20 15:36:01 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	handle_size_d(va_list ap, t_flags *f)
{
	intmax_t	nb;

	if (f->size == 2)
		nb = (signed char)(va_arg(ap, int));
	else if (f->size == 1)
		nb = (short)(va_arg(ap, int));
	else if (f->size == 4)
		nb = (long long)(va_arg(ap, long long int));
	else if (f->size == 3)
		nb = (long)(va_arg(ap, long));
	else if (f->size == 5)
		nb = (intmax_t)(va_arg(ap, intmax_t));
	else if (f->size == 6)
		nb = (size_t)(va_arg(ap, size_t));
	else
		nb = (int)(va_arg(ap, int));
	nb = (intmax_t)nb;
	return (nb);
}

long long		convert_len(va_list ap, const t_flags *f)
{
	if (f->isll == 1)
		return ((unsigned long long)va_arg(ap, long long));
	if (f->isl == 1 || f->converter == 'U' ||
			f->converter == 'O')
		return ((unsigned long)va_arg(ap, long));
	if (f->ishh == 1)
		return ((unsigned char)va_arg(ap, int));
	if (f->ish == 1)
		return ((unsigned short)va_arg(ap, int));
	if (f->isj == 1)
		return ((uintmax_t)va_arg(ap, uintmax_t));
	if (f->isz)
		return ((size_t)va_arg(ap, size_t));
	return ((unsigned int)va_arg(ap, int));
}