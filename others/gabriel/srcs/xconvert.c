/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xconvert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:00:18 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/21 14:00:47 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*hexa_width(char *hexa, t_tab tab)
{
	char		*new_hexa;
	int			i;
	int			n;
	int			sharp;

	sharp = 0;
	if (!tab.zero || !tab.sharp)
	{
		hexa = width_parser(hexa, tab);
		return (hexa);
	}
	if (ft_strchr(hexa, 'x'))
		sharp = 1;
	i = (int)ft_strlen(hexa) - 1;
	n = tab.width - 1;
	new_hexa = ft_strnew(tab.width);
	while (ft_strchr("0123456789abcdef", hexa[i]) && i > 0)
		new_hexa[n--] = hexa[i--];
	while (n > -1)
		new_hexa[n--] = '0';
	if (sharp)
		new_hexa[1] = 'x';
	ft_strdel(&hexa);
	return (new_hexa);
}

t_tab				xconvert(t_tab tab)
{
	uintmax_t	num;
	char		*hexa;
	int			i;
	int			len;

	i = -1;
	num = get_unsigned(tab);
	hexa = ft_itoa_base(num, 16);
	len = (int)ft_strlen(hexa);
	if (tab.precision > -1)
	{
		tab.zero = 0;
		hexa = precision_solver(hexa, tab.precision);
	}
	if (tab.sharp && num != 0)
		hexa = ft_strjoinfree(ft_strdup("0x"), hexa);
	if (tab.width)
		hexa = hexa_width(hexa, tab);
	if (tab.string[0] == 'X')
		while (hexa[++i])
			hexa[i] = ft_toupper(hexa[i]);
	tab.reply = ft_strjoinfree(tab.reply, hexa);
	tab.string = move_char(tab.string, 1);
	return (tab);
}
