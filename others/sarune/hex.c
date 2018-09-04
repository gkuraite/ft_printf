/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:48:57 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/08 17:25:48 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_gaps(t_flags *flag, char *str, unsigned long long hex)
{
	int		len;

	if (flag->zero && !(flag->dot))
		return (0);
	if (flag->precision >= flag->width)
		return (0);
	len = flag->width;
	len -= (ft_strlen(str) > (size_t)flag->precision ?
			ft_strlen(str) : flag->precision);
	len += (hex == 0 ? 1 : 0);
	if (flag->hashtag)
		len -= 2;
	fill_with_char(len, ' ');
	return (len > 0 ? len : 0);
}

static int	fill_zeros(t_flags *flag, char *str, unsigned long long hex)
{
	int len;

	if (flag->zero && !(flag->dot))
	{
		if (flag->width >= flag->precision)
			len = flag->width;
		else
			len = flag->precision;
		len -= ft_strlen(str);
		if (flag->hashtag && hex != 0)
			len -= 2;
		fill_with_char(len, '0');
		return (len > 0 ? len : 0);
	}
	if (flag->precision)
	{
		len = flag->precision - ft_strlen(str);
		fill_with_char(len, '0');
		return (len > 0 ? len : 0);
	}
	return (0);
}

int			format_hex(t_flags *flag, unsigned long long hex, t_bool hex_case)
{
	char		*hex_str;
	int			ret;

	ret = 0;
	hex_str = ft_convert_to_base(hex, 16);
	if ((flag->precision > flag->width) &&
			flag->hashtag && hex != 0)
		ft_putstr((!hex_case ? "0x" : "0X"));
	if (!(flag->minus))
		ret += fill_gaps(flag, hex_str, hex);
	if (!(flag->precision > flag->width) &&
			flag->hashtag && hex != 0)
		ft_putstr((!hex_case ? "0x" : "0X"));
	ret += (flag->hashtag && hex != 0 ? 2 : 0);
	ret += fill_zeros(flag, hex_str, hex);
	if (hex_case)
		ft_str_to_upper(hex_str);
	if (!(hex == 0 && flag->dot && flag->precision == 0))
	{
		ret += ft_strlen(hex_str);
		ft_putstr(hex_str);
	}
	ret += (flag->minus ? fill_gaps(flag, hex_str, hex) : 0);
	free(hex_str);
	return (ret);
}
