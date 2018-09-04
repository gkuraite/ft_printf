/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:41:50 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 16:18:45 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_gaps(t_flags *flag, char *str)
{
	int len;

	if (flag->zero && !(flag->dot))
		return (0);
	if (flag->precision >= flag->width)
		return (0);
	len = flag->width - 2;
	len -= (ft_strlen(str) > (size_t)flag->precision ?
			ft_strlen(str) : flag->precision);
	fill_with_char(len, ' ');
	return (len > 0 ? len : 0);
}

static int	fill_zeros(t_flags *flag, char *str)
{
	int			len;

	if (flag->zero && !(flag->dot))
	{
		if (flag->width >= flag->precision)
			len = flag->width;
		else
			len = flag->precision;
		len -= ft_strlen(str);
		len -= 2;
		fill_with_char(len, '0');
		return (len > 0 ? len : 0);
	}
	if (flag->dot)
	{
		len = flag->precision - ft_strlen(str);
		fill_with_char(len, '0');
		return (len > 0 ? len : 0);
	}
	return (0);
}

int			format_pointer(t_flags *flag, unsigned long int ptr)
{
	char		*hex;
	int			ret;

	ret = 0;
	hex = ft_convert_to_base_long(ptr, 16);
	if (!(flag->minus))
		ret += fill_gaps(flag, hex);
	ft_putstr("0x");
	ret += 2;
	ret += fill_zeros(flag, hex);
	if (!(ptr == 0 && flag->dot && flag->precision == 0))
	{
		ret += ft_strlen(hex);
		ft_putstr(hex);
	}
	if (flag->minus)
		ret += fill_gaps(flag, hex);
	free(hex);
	return (ret);
}
