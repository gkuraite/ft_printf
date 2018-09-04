/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:10:15 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/08 17:25:50 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_gaps(t_flags *flag, char *str, unsigned long long octal)
{
	int		len;

	if (flag->zero && !(flag->dot))
		return (0);
	if (flag->precision > flag->width)
		return (0);
	if (flag->width == 0)
		return (0);
	len = flag->width;
	len -= (octal != 0 && ft_strlen(str) > (size_t)flag->precision ?
			ft_strlen(str) : flag->precision);
	len -= (octal == 0 && !(flag->dot) ? 1 : 0);
	if (flag->hashtag && octal != 0 && !(flag->dot && flag->precision))
		len -= 1;
	fill_with_char(len, ' ');
	return (len > 0 ? len : 0);
}

static int	fill_zeros(t_flags *flag, char *str, unsigned long long octal)
{
	int len;

	if (flag->zero && !(flag->dot))
	{
		if (flag->width > flag->precision)
			len = flag->width;
		else
			len = flag->precision;
		len -= ft_strlen(str);
		if (flag->hashtag)
			len -= 1;
		fill_with_char(len, '0');
		return (len > 0 ? len : 0);
	}
	if (flag->dot)
	{
		len = flag->precision - ft_strlen(str);
		len -= (flag->hashtag && octal != 0 ? 1 : 0);
		fill_with_char(len, '0');
		return (len > 0 ? len : 0);
	}
	return (0);
}

int			format_octal(t_flags *flag, unsigned long long octal)
{
	char		*octal_str;
	int			ret;

	ret = 0;
	octal_str = ft_convert_to_base(octal, 8);
	if (!(flag->minus))
		ret += fill_gaps(flag, octal_str, octal);
	if (octal != 0 && flag->hashtag && (flag->zero || flag->dot))
		ret += ft_putchar_ret('0');
	if (octal != 0 && flag->hashtag && (!(flag->zero) && !(flag->dot)))
		ret += ft_putchar_ret('0');
	ret += fill_zeros(flag, octal_str, octal);
	if (octal == 0 && flag->hashtag && flag->dot && flag->precision == 0)
		ret += ft_putchar_ret('0');
	if (!(octal == 0 && flag->dot && flag->precision == 0))
	{
		ret += ft_strlen(octal_str);
		ft_putstr(octal_str);
	}
	if (flag->minus)
		ret += fill_gaps(flag, octal_str, octal);
	free(octal_str);
	return (ret);
}
