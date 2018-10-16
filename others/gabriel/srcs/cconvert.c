/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cconvert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:35:16 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/21 13:35:30 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab			cconvert(t_tab tab)
{
	wchar_t	c;
	char	*reply;

	if (!tab.l && tab.string[0] == 'c')
		c = (char)va_arg(*(tab.ap), int);
	else
		c = (wchar_t)va_arg(*(tab.ap), wint_t);
	if (!c)
		c = -1;
	if (c > 127)
		reply = wide_cconvert(c);
	else
	{
		reply = ft_strnew(1);
		reply[0] = c;
	}
	if (tab.width)
		reply = width_parser(reply, tab);
	tab.reply = ft_strjoinfree(tab.reply, reply);
	tab.string = move_char(tab.string, 1);
	return (tab);
}
