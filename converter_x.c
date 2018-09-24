/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:32:41 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/24 13:32:43 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long		convert_size_oxu(va_list ap, const t_flags *f)
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

int     converter_x(t_flags *f, va_list *ap)
{
    size_t num;
    char	*str;
    (void)f;
    
    num = convert_size_oxu(*ap, f);
    printf("\n NUM = %zu\n", num);
    str = ft_itoabase(num, 16);
    ft_putstr(str);
    return (0);
}