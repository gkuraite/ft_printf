/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:33:42 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/06 10:46:54 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_d(t_flags *f, va_list *ap)
{

	//char *str;

	if (!f->size && f->type != 'D')
			return ((int)va_arg(ap, int)); //%d
			//str = ? 
	else if (f->size == 1 && f->type != 'D')
			return ((long long)(short int)va_arg(ap, int));//%hd
			//str = ? 
	else if (f->size == 2 && f->type != 'D')
			return ((long long)(signed char)va_arg(ap, int));//hhd
			//str = ? 
	else if (f->size == 4 && f->type != 'D')
			return ((long long)va_arg(ap, long long));//%lld
			//str = ? 
	else if (f->size == 5 && f->type != 'D')
			return ((long long)va_arg(ap, size_t));//%zd
			//str = ? 
	else if (f->size == 6 && f->type != 'D')
			return ((long long)va_arg(ap, intmax_t));//%jd
			//str = ? 
	else
		return ((long long)va_arg(ap, long));//%D / %ld
		//str = ? 
	//return (str);
}

int     d_conversion(t_flags *f, va_list *ap)
{
    int num;

	num = (int)va_arg(*ap, int);

	if (flags->type != 'D')
    	ft_putnbr(num);
	return (0);
}



