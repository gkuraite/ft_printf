/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconvert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:21:36 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/24 14:21:51 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*adjust_ptr(char *ptr)
{
	int			i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == 'x')
			ptr[i] = '0';
		i++;
	}
	ptr[1] = 'x';
	return (ptr);
}

t_tab			pconvert(t_tab tab)
{
	uintmax_t	value;
	char		*ptr;
	int			len;

	value = (uintmax_t)va_arg(*(tab.ap), uintmax_t);
	ptr = ft_lltoa_base(value, 16);
	len = ft_strlen(ptr);
	ptr = precision_solver(ptr, tab.precision);
	ptr = ft_strjoinfree(ft_strdup("0x"), ptr);
	if (tab.width)
		ptr = hexa_width(ptr, tab);
	if ((tab.width > len || tab.precision > len) && tab.zero)
		ptr = adjust_ptr(ptr);
	tab.reply = ft_strjoinfree(tab.reply, ptr);
	tab.string = move_char(tab.string, 1);
	return (tab);
}
