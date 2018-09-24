/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:24:26 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/12 11:24:28 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long long		convert_size_o(va_list ap, const t_flags *f)
{
	if (f->size == 4)
		return ((unsigned long long)va_arg(ap, long long));
	if (f->size == 3) /*|| f->converter == 'U' ||
			f->converter == 'O')*/
		return ((unsigned long)va_arg(ap, long));
	if (f->size == 2)
		return ((unsigned char)va_arg(ap, int));
	if (f->size == 1)
		return ((unsigned short)va_arg(ap, int));
	if (f->size == 5)
		return ((uintmax_t)va_arg(ap, uintmax_t));
	if (f->size == 6)
		return ((size_t)va_arg(ap, size_t));
	return ((unsigned int)va_arg(ap, int));
}
	
int     converter_o(t_flags *f, va_list *ap)
{
    long long num;
	char	*str;
	(void)f;
	
	num = convert_size_o(*ap, f);
	//printf("\n NUM = %lld\n", num);
	str = ft_itoabase(num, 8);
	//printf("\n str = %s\n", str);
	ft_putstr(str);
	return (0);
}