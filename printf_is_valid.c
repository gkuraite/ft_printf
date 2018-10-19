/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:54:09 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/19 17:13:35 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_is_valid(t_flags *f)
{
	if (f->plus)
		f->space = 0;
	if (f->minus || (f->precision != -1 && f->format[f->i] != '%'))
		f->zero = 0;
	if (f->format[f->i] == 'd' || f->format[f->i] == 'D' ||
		f->format[f->i] == 'i' || f->format[f->i] == 'o' ||
		f->format[f->i] == 'O' || f->format[f->i] == 'u' ||
		f->format[f->i] == 'U' || f->format[f->i] == 'x' ||
		f->format[f->i] == 'X' || f->format[f->i] == 'c' ||
		f->format[f->i] == 'C' || f->format[f->i] == '%' ||
		f->format[f->i] == 's' || f->format[f->i] == 'S' ||
		f->format[f->i] == 'p')
		return (1);
	return (0);
}
