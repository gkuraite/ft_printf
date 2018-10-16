/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:39:18 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/15 17:36:59 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*zero_read(char *str, t_tab tab)
{
	int		i;

	i = 0;
	if (tab.zero)
	{
		if (!tab.minus)
			while ((str[i] == 0 || str[i] == ' ') && i < tab.width)
				str[i++] = '0';
	}
	return (str);
}

static char	*minus_read(char *dest, char *src, t_tab tab)
{
	int		i;
	int		n;

	i = 0;
	n = tab.width - 1;
	if (tab.minus)
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	else
	{
		i = (int)ft_strlen(src) - 1;
		while (i >= 0)
			dest[n--] = src[i--];
	}
	return (dest);
}

char		*width_parser(char *str, t_tab tab)
{
	char	*widestr;
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str);
	if (len > tab.width)
		return (str);
	widestr = ft_strnew(tab.width);
	widestr = minus_read(widestr, str, tab);
	widestr = zero_read(widestr, tab);
	ft_strdel(&str);
	while (i < tab.width)
	{
		if (!widestr[i])
			widestr[i] = ' ';
		i++;
	}
	return (widestr);
}
