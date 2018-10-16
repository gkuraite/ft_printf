/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:50:32 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/22 09:51:00 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*minus_solver(t_tab tab)
{
	char	*str;
	int		i;

	i = 1;
	str = ft_strnew(tab.width);
	str[0] = tab.string[0];
	while (i < tab.width)
		str[i++] = ' ';
	return (str);
}

static char	*width_include(t_tab tab)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(tab.width);
	if (tab.minus)
		str = minus_solver(tab);
	else if (tab.zero)
	{
		while (i < (tab.width - 1))
			str[i++] = '0';
		str[i] = tab.string[0];
	}
	else
	{
		while (i < (tab.width - 1))
			str[i++] = ' ';
		str[i] = tab.string[0];
	}
	return (str);
}

t_tab		percent_convert(t_tab tab)
{
	char	*str;

	if (tab.width > 1)
		str = width_include(tab);
	else
	{
		str = ft_strnew(1);
		str[0] = tab.string[0];
	}
	tab.reply = ft_strjoinfree(tab.reply, str);
	tab.string = move_char((tab.string), 1);
	return (tab);
}
