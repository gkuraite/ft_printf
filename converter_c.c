/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:24:37 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:39:47 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inthandle_zero(char *str)
{
	if (ft_strlen(str))
		ft_putstr(str);
	else
		ft_putchar(0);
	return (0);
}

static int	handle_width(t_flags *f, char *str)
{
	int		i;

	i = (ft_strlen(str) != 0 ? ft_strlen(str) : 1);
	if (f->minus)
		handle_zero(str);
	while (f->width > i)
	{
		if (f->minus)
			ft_putchar(' ');
		else if (f->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	if (!f->minus)
		handle_zero(str);
	return (i);
}

int			converter_c(t_flags *f, va_list *ap)
{
	wchar_t	c;
	char	*store;
	int		i;

	if (f->format[f->i] == 'C' || f->size == 3)
	{
		c = va_arg(*ap, wchar_t);
		store = ft_unicode(c);
	}
	else
	{
		c = va_arg(*ap, int);
		store = ft_unicode(c);
	}
	if (!store)
		return (-1);
	i = handle_width(f, store);
	free(store);
	return (i);
}
