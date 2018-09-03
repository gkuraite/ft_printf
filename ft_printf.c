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

static size_t		ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}


static void	ft_putchar(char c)
{
	write(1, &c, 1);	
}

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

void	is_there_a_flag(t_flags *flags, va_list *ap)
{
	zero(flags);
	flags->i++;
//	printf("format = %c\n", flags->format[flags->i]);
	while (flags->format[flags->i] != '\0' && ft_strchr("-+0 #0123456789.hljz", flags->format[flags->i]))
	{
		ft_check_flags(flags);
		ft_check_width(flags);
		flags->i++;
	}
	if (flags->format[flags->i] == 'd')
		flag_d(flags, ap);
	printf("\n is there a width ?\t%d\n", flags->width);
	flags->i++;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_flags			flags;
	
	va_start(ap, format);
	flags.i = 0;
	flags.format = format;
	printf("What's in format? \n%s\n", flags.format);
	if (!flags.format)
	{
		printf("ERROR 1\n");
		return (1);
	}
	while (flags.format[flags.i])
	{
		if (flags.format[flags.i] == '%')
		{
			is_there_a_flag(&flags, &ap);
		}
		if (flags.format[flags.i] == '\0')
			return (0);
		else
			ft_putchar((char)flags.format[flags.i]);
		//else if (++ret && flags.format)
		//	ft_putchar((char)flags.format);
	//	printf(" format = %c\n", flags.format[i]);
		flags.i++;
		
	}
	return(0);
}
