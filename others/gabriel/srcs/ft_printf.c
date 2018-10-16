/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:50:36 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 14:30:24 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_printf(const char *format, ...)
{
	t_tab	tab;
	va_list	ap;
	size_t	len;
	int		i;

	i = 0;
	tab.string = ft_strdup(format);
	tab = init_flags(tab);
	va_start(ap, format);
	tab.ap = &ap;
	tab = solver(tab);
	va_end(ap);
	len = ft_strlen(tab.reply);
	while (tab.reply[i])
	{
		if (tab.reply[i] == -1)
			tab.reply[i] = 0;
		i++;
	}
	write(1, tab.reply, len);
	ft_strdel(&tab.reply);
	ft_strdel(&tab.specifier_tab);
	ft_strdel(&tab.flag_tab);
	return (len);
}
