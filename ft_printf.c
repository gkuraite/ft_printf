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
	flags->width = -1;
	flags->precision = -1;
	flags->size = 0;
	flags->type = 0;
}

static int	print_converter(t_flags *f, va_list *ap)
{
	if (f->type == 'd' || f->type == 'i' || f->type == 'D')
		return (converter_d(f, ap));
	if (f->type == 'o' || f->type == 'O')
		return (converter_o(f, ap));
	if (f->type == 'u' || f->type == 'U')
		return (converter_u(f, ap));
	if (f->type == 'x' || f->type == 'X')
		return (converter_x(f, ap));
	if (f->type == 'c' || f->type == 'C')
		return (converter_c(f, ap));
	//if (f->type == '%')
	//	return (converter_pc(f));
	if (f->type == 's' || f->type == 'S')
		return (converter_s(f, ap));
	if (f->type == 'p')
		return (converter_p(f, ap));
	return (0);
}

static void	checking_printf(t_flags *flags, va_list *ap)
{
	zero(flags);
	flags->i++;
//	printf("format = %c\n", flags->format[flags->i]);
	if (flags->format[flags->i] != '\0' && 
			ft_strchr(SUB_SPECIFIERS, flags->format[flags->i]))
	{
		check_flags(flags);
		check_width(flags);
		check_precision(flags);
		check_size(flags);
		
	}
	if (ft_strchr(SPECIFIERS, flags->format[flags->i]))
	{
		//converter_d(flags, ap);
		//converter_s(flags, ap);
		//converter_u(flags, ap);
		//converter_x(flags, ap);
		//converter_c(flags, ap);
		//converter_o(flags, ap);
		print_converter(flags, ap);

	}
	//printf("\nis there a plus ?\t%d\n", flags->plus);
	//printf("\nis there a minus ?\t%d\n", flags->minus);
	//printf("\nis there a space ?\t%d\n", flags->space);
	//printf("\nis there a zero ?\t%d\n", flags->zero);
	//printf("\nis there a hash ?\t%d\n", flags->hash);
	//printf("\nWhat is the width ?\t%d\n", flags->width);
	//printf("\nWhat is the precision ?\t%d\n", flags->precision);
	//printf("\nWhat is the size ?\t%d\n", flags->size);
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
		flags.i++;
		
	}
	return(0);
}
