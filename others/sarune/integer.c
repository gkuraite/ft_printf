/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:53:47 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 14:57:33 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int		print_gaps(t_flags *flag, long long int nbr)
{
	int		numb_len;

	if (flag->precision > flag->width)
		return (0);
	numb_len = flag->width - flag->precision;
	numb_len -= (ft_get_nbr_len(nbr) > flag->precision ?
			ft_get_nbr_len(nbr) - flag->precision : 0);
	numb_len -= (flag->space ? 1 : 0);
	numb_len -= (flag->plus && (nbr >= 0) ? 1 : 0);
	numb_len -= (nbr < 0 && !(flag->space) ? 1 : 0);
	numb_len += (nbr == 0 && flag->dot && flag->precision == 0 ? 1 : 0);
	if (flag->zero && !(flag->precision) && nbr < 0)
		ft_putchar('-');
	if (flag->zero && !(flag->dot))
		fill_with_char(numb_len, '0');
	else
		fill_with_char(numb_len, ' ');
	if (numb_len < 0)
		numb_len = 0;
	return (flag->zero && nbr < 0 ? numb_len + 1 : numb_len);
}

static int		print_precision(t_flags *flag, long long int nbr)
{
	int		numb_len;

	if (!(flag->precision))
		return (0);
	numb_len = flag->precision - ft_get_nbr_len(nbr);
	if (nbr < 0 && !(flag->space))
		ft_putchar('-');
	fill_with_char(numb_len, '0');
	if (numb_len < 0)
		numb_len = 0;
	if (flag->space && nbr < 0 && flag->precision)
		return (numb_len);
	return (!(flag->zero) && nbr < 0 ? numb_len + 1 : numb_len);
}

static void		do_functions(t_flags *flag, long long int nbr, int *ret)
{
	if (flag->space && flag->zero)
		*ret += ft_putchar_ret((nbr >= 0 ? ' ' : '-'));
	if (flag->plus && !(flag->precision) && flag->zero && nbr >= 0)
		*ret += ft_putchar_ret('+');
	if (!(flag->minus))
		*ret += print_gaps(flag, nbr);
	if (flag->plus && !(flag->precision) && !(flag->zero))
		*ret += ft_putchar_ret((nbr >= 0 ? '+' : '-'));
	if (flag->space && !(flag->zero))
		*ret += ft_putchar_ret((nbr >= 0 ? ' ' : '-'));
	if (flag->plus && flag->precision && flag->width)
		*ret += ft_putchar_ret((nbr >= 0 ? '+' : 0));
}

int				format_integer(t_flags *flag, long long int nbr)
{
	int ret;

	ret = 0;
	do_functions(flag, nbr, &ret);
	ret += print_precision(flag, nbr);
	if (!(flag->zero || flag->plus || flag->space || flag->precision)
			&& nbr < 0)
		ret += ft_putchar_ret('-');
	if (nbr == LLONG_MIN)
	{
		ft_putstr("9223372036854775808");
		ret += ft_get_nbr_len(nbr);
	}
	else if (!(nbr == 0 && flag->dot && flag->precision == 0))
	{
		ft_putnbr_longlong(ABS(nbr));
		ret += ft_get_nbr_len(nbr);
	}
	if ((flag->minus))
		ret += print_gaps(flag, nbr);
	return (ret);
}
