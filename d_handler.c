/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:33:42 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 17:03:10 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handle_position_d(t_flags *f, char *str)
{
	int	s;

	s = 0;
	if ((ft_strstr(str, "-") > ft_strstr(str, "0")) && ft_strstr(str, "0"))
	{
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "-"))] = '0';
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "0"))] = '-';
	}
	if (ft_strstr(str, "+") > ft_strstr(str, "0") && ft_strstr(str, "0"))
	{
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "+"))] = '0';
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "0"))] = '+';
	}
	if (ft_strstr(str, " ") > ft_strstr(str, "0") && ft_strstr(str, "0")
			&& f->zero)
	{
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, " "))] = '0';
		str[ft_strlen(str) - ft_strlen(ft_strstr(str, "0"))] = ' ';
	}
	ft_putstr(str + 0 * (s = ft_strlen(str)));
	return (str);
}

char		*handle_width_d(t_flags *f, char *str)
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
	return (str);
}

char		*handle_sign_d(t_flags *f, char *str)
{
	char	*tmp;

	if ((f->plus || f->space) && !ft_strstr(str, "-") &&
			!ft_strstr(str, "+"))
	{
		tmp = str;
		if (f->plus)
			str = ft_strjoin("+", str);
		else
			str = ft_strjoin(" ", str);
		free(tmp);
	}
	return (str);
}

char		*handle_precision_d(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	//if (!f->precision && str && str[0] == '0')
	//{
	//	tmp = str;
	//	str = ft_strdup("");
	//	free(tmp);
	//}
	if (f->precision && f->precision > (i = ft_strlen(str)))
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

intmax_t	convert_size_d(va_list ap, t_flags *f)
{
	intmax_t	nb;

	if (f->size == 2)
		nb = (signed char)(va_arg(ap, int));
	else if (f->size == 1)
		nb = (short)(va_arg(ap, int));
	else if (f->size == 4)
		nb = (long long)(va_arg(ap, long long int));
	else if (f->size == 3)
		nb = (long)(va_arg(ap, long));
	else if (f->size == 5)
		nb = (intmax_t)(va_arg(ap, intmax_t));
	else if (f->size == 6)
		nb = (size_t)(va_arg(ap, size_t));
	else
		nb = (int)(va_arg(ap, int));
	nb = (intmax_t)nb;
	return (nb);
}
