/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:04:28 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/03 20:47:53 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_char(t_flags *flag, char c)
{
	if (!(flag->minus) && !(flag->precision))
		fill_with_char(flag->width - 1, ' ');
	ft_putchar(c);
	if (flag->minus && !(flag->precision))
		fill_with_char(flag->width - 1, ' ');
	return (flag->width > 0 && !(flag->precision) ? flag->width : 1);
}
