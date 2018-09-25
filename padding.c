/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:48:17 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/25 15:48:31 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *handle_width(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	//if (f->width > (i = ft_strlen(str)))
	//{
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
	//}
	return (str);
}

static char *handle_sign(t_flags *f, char *str)
{
	char	*temp;

	if ((f->plus || f->space) && !ft_strstr(str, "-") &&
			!ft_strstr(str, "+"))
	{
		temp = str;
		if (f->plus)
			str = ft_strjoin("+", str);
		else
			str = ft_strjoin(" ", str);
		free(temp);
	}
	return (str);
}

static char	*handle_precision(t_flags *f, char *str)
{
	char	*tmp;
	int		i;

	if (!f->precision && str && str[0] == '0')
	{
		tmp = str;
		str = ft_strdup("");
		free(tmp);
	}
	//if (f->precision && f->precision > (i = ft_strlen(str)))
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

char		*padding(char *str, t_flags *f)
{
	if (!str)
		return (NULL);
	if (f->precision > 0 && f->precision > (int)ft_strlen(str))
        str = handle_precision(str, f);
    if (f->plus || f->minus)
		str = handle_sign(str, f);
	if (f->width > 0 && f->width > (int)ft_strlen(str))
		str = handle_width(str, f);
	if (f->precision > 0 && f->width > 0 &&
			f->width > f->precision &&
			(int)ft_strlen(str) > f->width && f->minus)
	str[(int)ft_strlen(str) - 1] = '\0';
	return (str);
}