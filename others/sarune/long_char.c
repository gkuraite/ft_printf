/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:00:18 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 16:37:22 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_gaps(t_flags *flag, long int c)
{
	int		len;

	len = flag->width - ft_unicode_len(c);
	if (flag->zero)
		fill_with_char(len, '0');
	else
		fill_with_char(len, ' ');
	return (len > 0 ? len : 0);
}

int			format_long_char(t_flags *flag, long int c)
{
	int		ret;

	ret = 0;
	if (!(flag->minus) && !(flag->precision))
		ret += print_gaps(flag, c);
	ret += (c == 0 ? 1 : 0);
	if (c >= 0 && c <= 127)
		ret += ft_putchar_ret(c);
	else
	{
		ft_putchar_unicode(c);
		ret += ft_unicode_len(c);
	}
	if (flag->minus && !(flag->precision))
		ret += print_gaps(flag, c);
	return (ret);
}
