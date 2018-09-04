/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:44:16 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/03 20:49:58 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_gaps(t_flags *flag, char *str)
{
	int		len;

	if (flag->width == flag->precision)
		return (0);
	if (!str)
	{
		len = (flag->precision > 6 ? 6 : flag->precision);
		if (!(flag->dot))
			len = 6;
	}
	else
	{
		if (flag->dot)
			len = (ft_strlen(str) > (size_t)flag->precision ?
					flag->precision : ft_strlen(str));
		else
			len = ft_strlen(str);
	}
	len = flag->width - len;
	fill_with_char(len, ' ');
	return (len > 0 ? len : 0);
}

static int		null_case(t_flags *flag)
{
	char	*null;
	char	*cpy;
	int		size;
	int		ret;

	null = ft_strdup("(null)");
	cpy = null;
	ret = 0;
	size = 0;
	while (*null)
	{
		size += 1;
		if (flag->dot && size > flag->precision)
			break ;
		ret += ft_putchar_ret(*null);
		null++;
	}
	free(cpy);
	return (ret);
}

int				format_string(t_flags *flag, char *str)
{
	int		size;
	char	*cpy;
	int		ret;

	size = 0;
	ret = 0;
	if (!(flag->minus))
		ret += print_gaps(flag, str);
	cpy = str;
	if (!str)
		ret += null_case(flag);
	else
	{
		while (*str)
		{
			size++;
			if (flag->dot && size > flag->precision)
				break ;
			ret += ft_putchar_ret(*str);
			str++;
		}
	}
	if (flag->minus)
		ret += print_gaps(flag, cpy);
	return (ret);
}
