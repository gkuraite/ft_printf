/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:17:00 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:47:41 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(t_flags *f)
{
	while (f->format && (f->format[f->i] == '+' ||
			f->format[f->i] == '-' || f->format[f->i] == '0' ||
			f->format[f->i] == ' ' || f->format[f->i] == '#'))
	{
		if (f->format[f->i] == '+')
			f->plus = 1;
		if (f->format[f->i] == '-')
			f->minus = 1;
		if (f->format[f->i] == '0')
			f->zero = 1;
		if (f->format[f->i] == ' ')
			f->space = 1;
		if (f->format[f->i] == '#')
			f->hash = 1;
		f->i++;
	}
}
