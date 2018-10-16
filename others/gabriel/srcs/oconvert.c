/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oconvert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:59:52 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/21 17:00:05 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab				oconvert(t_tab tab)
{
	uintmax_t	num;
	char		*octo;
	int			i;
	int			len;

	i = -1;
	if (tab.string[0] == 'O')
		tab = longer_int(tab);
	num = get_unsigned(tab);
	octo = ft_itoa_base(num, 8);
	if (tab.sharp && num != 0)
		octo = ft_strjoinfree(ft_strdup("0"), octo);
	if (tab.precision > -1)
	{
		tab.zero = 0;
		octo = precision_solver(octo, tab.precision);
	}
	len = (int)ft_strlen(octo);
	if (num == 0 && tab.precision == 0 && tab.sharp)
		octo[0] = '0';
	octo = width_parser(octo, tab);
	tab.reply = ft_strjoinfree(tab.reply, octo);
	tab.string = move_char(tab.string, 1);
	return (tab);
}
