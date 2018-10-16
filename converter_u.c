/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:32:20 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:59:52 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*handle_width(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	if (f->width > (i = ft_strlen(str)))
	{
		while (i++ < f->width)
		{
			tmp = str;
			if (f->minus)
				str = ft_strjoin(str, " ");
			else if (f->zero)
				str = ft_strjoin("0", str);
			else
				str = ft_strjoin(" ", str);
			free(tmp);
		}
	}
	ft_putstr(str);
	return (str);
}

static char			*handle_precision(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	if (!f->precision && str && str[0] == '0')
	{
		tmp = str;
		str = ft_strdup("");
		free(tmp);
	}
	if (f->precision != -1 && f->precision > (i = ft_strlen(str)))
	{
		while (i < f->precision)
		{
			tmp = str;
			str = ft_strjoin("0", str);
			free(tmp);
			i++;
		}
	}
	return (str);
}

static long long	convert_size_oxu(va_list ap, const t_flags *f)
{
	if (f->size == 4)
		return ((unsigned long long)va_arg(ap, long long));
	if ((f->size == 3) || (f->format[f->i] == 'U'))
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

int					converter_u(t_flags *f, va_list *ap)
{
	long long	num;
	char		*str;
	int			len;

	num = convert_size_oxu(*ap, f);
	str = ft_itoabase(num, 10);
	str = handle_precision(f, str);
	str = handle_width(f, str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
