/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:42 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 14:11:30 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*string_precision(char *str, int precision)
{
	char	*trunc;
	int		i;

	i = 0;
	trunc = ft_strnew(precision);
	while (i < precision)
	{
		trunc[i] = str[i];
		i++;
	}
	ft_strdel(&str);
	return (trunc);
}

t_tab		sconvert(t_tab tab)
{
	char	*str;
	char	*reply;
	char	*new_reply;
	int		len;

	if ((str = va_arg(*(tab.ap), char*)) == NULL)
		reply = ft_strdup("(null)");
	else
		reply = ft_strdup(str);
	len = (int)ft_strlen(reply);
	if (tab.precision > -1 && tab.precision < len)
		reply = string_precision(reply, tab.precision);
	len = (int)ft_strlen(reply);
	if (tab.width > len)
		reply = width_parser(reply, tab);
	new_reply = ft_strjoin(tab.reply, reply);
	if (reply)
		ft_strdel(&reply);
	ft_strdel(&(tab.reply));
	tab.reply = new_reply;
	tab.string = move_char((tab.string), 1);
	return (tab);
}
