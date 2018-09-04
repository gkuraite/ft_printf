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
#include <stdio.h>

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
	flags->type = 0;
}

static void	checking_printf(t_flags *flags, va_list *ap)
{
	zero(flags);
	flags->i++;
//	printf("format = %c\n", flags->format[flags->i]);
	while (flags->format[flags->i] != '\0' && ft_strchr("-+0 #0123456789.hljz", flags->format[flags->i]))
	{
		check_flags(flags);
		check_width(flags);
		check_precision(flags);
		check_size(flags);
	}
	if (flags->format[flags->i] == 'd')
		flag_d(flags, ap);
	//printf("\nis there a zero ?\t%d\n", flags->zero);
	//printf("\nWhat is the width ?\t%d\n", flags->width);
	// printf("\nWhat is the precision ?\t%d\n", flags->precision);
	printf("\nWhat is the size ?\t%d\n", flags->size);
	flags->i++;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_flags			flags;
	
	va_start(ap, format);
	flags.i = 0;
	flags.format = format;
	printf("\nWhat's in format? \n%s\n", flags.format);
	if (!flags.format)
	{
		printf("ERROR 1\n");
		return (1);
	}
	while (flags.format[flags.i])
	{
		if (flags.format[flags.i] == '%')
		{
			checking_printf(&flags, &ap);
		}
		if (flags.format[flags.i] == '\0')
			return (0);
		else
			ft_putchar((char)flags.format[flags.i]);
		//else if (++ret && flags.format)
		//	ft_putchar((char)flags.format);
		flags.i++;
		
	}
	return(0);
}
