/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:39:57 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/04 15:13:17 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_gaps(t_flags *flag)
{
	int		len;

	if (flag->precision >= flag->width)
		return (0);
	len = flag->width - 1;
	if (flag->zero)
		fill_with_char(len, '0');
	else
		fill_with_char(len, ' ');
	return ((len > 0 ? len : 0));
}

int				format_percent(t_flags *flag)
{
	int		ret;

	ret = 0;
	if (!(flag->minus))
		ret += print_gaps(flag);
	ret += ft_putchar_ret('%');
	if (flag->minus)
		ret += print_gaps(flag);
	return (ret);
}
