/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:32:41 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/18 15:43:38 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*handle_position(t_flags *f, char *str)
{
	if ((f->hash || f->zero) && ft_strstr(str, "x") > ft_strstr(str, "0") + 1)
	{
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "x"))] = '0';
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "0")) + 1] = 'x';
	}
	if (f->format[f->i] == 'X')
		ft_toupperstr(&str);
	ft_putstr(str);
	return (str);
}

static char			*handle_width(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	if (f->width > (i = ft_strlen(str)))
	{
		while (i < f->width)
		{
			tmp = str;
			if (f->minus)
				str = ft_strjoin(str, " ");
			else if (f->zero)
				str = ft_strjoin("0", str);
			else
				str = ft_strjoin(" ", str);
			free(tmp);
			i++;
		}
	}
	return (str);
}

static char			*handle_hash_precision(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	if (f->hash && (tmp = str) && str[0] && str[0] != '0')
	{
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	else
		f->hash = 0;
	if (!f->precision && str && str[0] == '0' && !f->hash)
		str = NULL;
	if (!str)
		str = ft_strdup("");
	if (f->precision != -1 && f->precision > (i = ft_strlen(str) -
				2 * f->hash))
	{
		while (i++ < f->precision)
		{
			tmp = str;
			str = ft_strjoin("0", str);
			free(tmp);
		}
	}
	return (str);
}

static long long	convert_size_oxu(va_list ap, const t_flags *f)
{
	if (f->size == 4)
		return ((unsigned long long)va_arg(ap, long long));
	if (f->size == 3)
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

int					converter_x(t_flags *f, va_list *ap)
{
	long long	num;
	char		*str;
	int			len;

	num = convert_size_oxu(*ap, f);
	str = ft_itoabase(num, 16);
	str = handle_hash_precision(f, str);
	str = handle_width(f, str);
	str = handle_position(f, str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
