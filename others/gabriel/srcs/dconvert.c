/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:14:57 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/22 09:01:42 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*width_converter(char *str, t_tab tab)
{
	int		flag;
	char	*indicator;
	int		i;

	flag = 0;
	i = 0;
	if (str[0] == ' ' || ((str[0] == '+' || str[0] == '-') && tab.zero))
	{
		flag = 1;
		indicator = ft_strnew(1);
		indicator[0] = str[0];
		str = move_char(str, 1);
		tab.width--;
	}
	str = width_parser(str, tab);
	if (flag)
		str = ft_strjoinfree(indicator, str);
	return (str);
}

char				*sign_checker(char *str, t_tab tab)
{
	char		*sign;

	if (str[0] == ' ' || str[0] == '+' || str[0] == '-')
		return (str);
	sign = ft_strnew(1);
	if (tab.plus)
		sign[0] = '+';
	else if (tab.space)
		sign[0] = ' ';
	sign = ft_strjoinfree(sign, str);
	return (sign);
}

static uintmax_t	getnum(t_tab tab)
{
	uintmax_t	num;

	if (tab.h == 2)
		num = (signed char)va_arg(*(tab.ap), int);
	else if (tab.h == 1)
		num = (short)va_arg(*(tab.ap), int);
	else if (tab.l == 1)
		num = (long)va_arg(*(tab.ap), long int);
	else if (tab.l == 2)
		num = (long long)va_arg(*(tab.ap), long long int);
	else if (tab.j == 1)
		num = (intmax_t)va_arg(*(tab.ap), intmax_t);
	else if (tab.z == 1)
		num = (size_t)va_arg(*(tab.ap), size_t);
	else
		num = (int)va_arg(*(tab.ap), int);
	return (num);
}

t_tab				dconvert(t_tab tab)
{
	intmax_t	num;
	char		*reply;
	int			i;
	int			len;

	i = -1;
	if (tab.string[0] == 'D')
		tab = longer_int(tab);
	if (tab.precision > -1)
		tab.zero = 0;
	num = getnum(tab);
	reply = ft_lltoa_base(num, 10);
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
