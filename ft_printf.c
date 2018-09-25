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

static int	print_converter(t_flags *f, va_list *ap)
{
	if (f->format[f->i] == 'd' || f->format[f->i] == 'i' || f->format[f->i] == 'D')
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

static void	checking_printf(t_flags *f, va_list *ap)
{
	zero(f);
	f->i++;
	//printf("format = %c\n", f->format[f->i]);
	if (f->format[f->i] != '\0' && 
			ft_strchr(SUB_SPECIFIERS, f->format[f->i]))
	{
		check_flags(f);
		check_width(f);
		//printf("\nWhat is the width ?\t%d\n", f->width);
		check_precision(f);
		check_size(f);
	}
	if (ft_strchr(SPECIFIERS, f->format[f->i]))
		print_converter(f, ap);
	//printf("\nis there a plus ?\t%d\n", f->plus);
	//printf("\nis there a minus ?\t%d\n", f->minus);
	//printf("\nis there a space ?\t%d\n", f->space);
	//printf("\nis there a zero ?\t%d\n", f->zero);
	//printf("\nis there a hash ?\t%d\n", f->hash);
	//printf("\nWhat is the width ?\t%d\n", f->width);
	
	//printf("\nWhat is the size ?\t%d\n", f->size);
	f->i++;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_flags			flags;
	
	va_start(ap, format);
	flags.i = 0;
	flags.format = format;
	//printf("\nWhat's in format? \n%s\n", flags.format);
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
