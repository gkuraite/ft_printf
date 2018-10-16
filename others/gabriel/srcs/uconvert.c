/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uconvert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:13:27 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/24 08:14:04 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab			longer_int(t_tab tab)
{
	tab.h = 0;
	tab.l = 0;
	tab.z = 0;
	tab.j = 1;
	return (tab);
}

static t_tab	flag_changer(t_tab tab)
{
	if (tab.space)
		tab.space = 0;
	if (tab.plus)
		tab.plus = 0;
	return (tab);
}

uintmax_t		get_unsigned(t_tab tab)
{
	uintmax_t	num;

	if (tab.h == 2)
		num = (unsigned char)va_arg(*(tab.ap), unsigned int);
	else if (tab.h == 1)
		num = (unsigned short)va_arg(*(tab.ap), unsigned int);
	else if (tab.l == 1)
		num = (unsigned long)va_arg(*(tab.ap), unsigned long int);
	else if (tab.l == 2)
		num = (unsigned long long)va_arg(*(tab.ap), unsigned long long int);
	else if (tab.j == 1)
		num = (uintmax_t)va_arg(*(tab.ap), uintmax_t);
	else if (tab.z == 1)
		num = (size_t)va_arg(*(tab.ap), size_t);
	else
		num = (unsigned int)va_arg(*(tab.ap), unsigned int);
	return (num);
}

t_tab			uconvert(t_tab tab)
{
	intmax_t	num;
	char		*reply;
	int			i;
	int			len;

	i = -1;
	if (tab.string[0] == 'U')
		tab = longer_int(tab);
	num = get_unsigned(tab);
	tab = flag_changer(tab);
	reply = ft_itoa_base(num, 10);
	len = (int)ft_strlen(reply);
	if (tab.precision > -1)
		tab.zero = 0;
	reply = precision_solver(reply, tab.precision);
	if ((reply[0] != '-') && (tab.plus || tab.space))
		reply = sign_checker(reply, tab);
	len = (int)ft_strlen(reply);
	if (tab.width > len)
		reply = width_converter(reply, tab);
	tab.reply = ft_strjoinfree(tab.reply, reply);
	tab.string = move_char(tab.string, 1);
	return (tab);
}
