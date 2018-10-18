/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:41:24 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/17 16:51:59 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_width(t_flags *f, char *str)
{
	char	*tmp;
	int		len;

	if (f->width > (int)ft_strlen(str))
	{
		len = f->width - ft_strlen(str);
		tmp = ft_strnew(len);
		tmp = ft_memset((void*)tmp, (f->zero &&
					!f->minus) ? '0' : ' ', len);
		if (f->minus)
			str = ft_strjoinfree(str, tmp);
		else
			str = ft_strjoinfree(tmp, str);
	}
	ft_putstr(str);
	return (str);
}

static char	*handle_precision(t_flags *f, char *str)
{
	char	*tmp;

	if ((f->format[f->i] == 'S' || f->size == 3) && f->precision > -1)
	{
		while ((str[f->precision] & 0xC0) == 0x80)
			f->precision--;
		ft_strclr(str + f->precision);
	}
	else if (f->precision > 0 && (f->precision < (int)ft_strlen(str)))
	{
		tmp = str;
		str = ft_strsub(str, 0, f->precision);
		free(tmp);
	}
	return (str);
}

int			converter_s(t_flags *f, va_list *ap)
{
	wchar_t	*str;
	char	*store;
	int		count;
	int		len;

	count = 0;
	len = 0;
	store = NULL;
	if (f->format[f->i] == 'S' || f->size == 3)
	{
		if ((str = va_arg(*ap, wchar_t*)))
			store = ft_strdup("");
		while (store && str[count])
			store = ft_strjoinfree(store, ft_unicode(str[count++]));
	}
	else
		store = ft_strdup(va_arg(*ap, char*));
	if (!store)
		store = ft_strdup("(null)");
	store = handle_precision(f, store);
	store = handle_width(f, store);
	len = ft_strlen(store);
	free(store);
	return (len);
}
