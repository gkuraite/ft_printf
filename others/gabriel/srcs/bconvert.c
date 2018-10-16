/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bconvert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:06:27 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/29 11:06:09 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab				bconvert(t_tab tab)
{
	uintmax_t	num;
	char		*bin;
	char		*reply;
	int			i;
	int			len;

	i = -1;
	num = get_unsigned(tab);
	bin = ft_itoa_base(num, 2);
	if (tab.sharp == 1)
		reply = ft_strjoin("0", bin);
	else
		reply = ft_strdup(bin);
	ft_strdel(&bin);
	len = (int)ft_strlen(reply);
	reply = precision_solver(reply, tab.precision);
	reply = width_parser(reply, tab);
	tab.reply = ft_strjoinfree(tab.reply, reply);
	tab.string = move_char(tab.string, 1);
	return (tab);
}
