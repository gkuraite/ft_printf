/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:46:08 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/03 20:50:03 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_gaps(t_flags *flag, unsigned long long nbr)
{
	int		numb_len;

	if (flag->precision > flag->width)
		return (0);
	numb_len = flag->width - flag->precision;
	numb_len -= (ft_get_nbr_len_unsigned(nbr) > flag->precision ?
			ft_get_nbr_len_unsigned(nbr) - flag->precision : 0);
	numb_len -= (flag->space ? 1 : 0);
	if (flag->zero && !flag->precision)
		fill_with_char(numb_len, '0');
	else
		fill_with_char(numb_len, ' ');
	return (numb_len > 0 ? numb_len : 0);
}

static int		print_precision(t_flags *flag, unsigned long long nbr)
{
	int		numb_len;

	if (!(flag->precision))
		return (0);
	numb_len = flag->precision - ft_get_nbr_len_unsigned(nbr);
	fill_with_char(numb_len, '0');
	return (numb_len > 0 ? numb_len : 0);
}

int				format_unsigned(t_flags *flag, unsigned long long nbr)
{
	int		ret;

	ret = 0;
	if (flag->space)
		ret += ft_putchar_ret(' ');
	if (!(flag->minus))
		ret += print_gaps(flag, nbr);
	if (flag->space && !(flag->zero))
		ret += ft_putchar_ret(' ');
	ret += print_precision(flag, nbr);
	if (!(nbr == 0 && flag->dot && flag->precision == 0))
	{
		ret += ft_get_nbr_len_unsigned(nbr);
		ft_putnbr_unsigned(ABS(nbr));
	}
	if ((flag->minus))
		ret += print_gaps(flag, nbr);
	return (ret);
}
