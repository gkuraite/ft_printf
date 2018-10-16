/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_sconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:44:29 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/28 09:44:44 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*trunc_precision(char *str, int precision)
{
	int		i;
	int		n;
	char	*trunc;

	i = precision - 1;
	n = 0;
	while (str[i + 1] > -64 && str[i + 1])
		i++;
	if (precision == 1 && str[0] > 0)
	{
		trunc = ft_strnew(1);
		trunc[0] = str[0];
		ft_strdel(&str);
		return (trunc);
	}
	trunc = ft_strnew(i);
	while (n < i)
	{
		trunc[n] = str[n];
		n++;
	}
	ft_strdel(&str);
	return (trunc);
}

static char		*add_wchar(char *str1, char *str2)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str1[len])
		len++;
	while (str2[i])
		str1[len++] = str2[i++];
	str1[len] = 0;
	return (str1);
}

static char		*wide_string(wchar_t *str)
{
	int		len;
	int		i;
	int		n;
	char	*reply;
	char	*temp;

	i = 0;
	n = 0;
	len = 0;
	while (str[len])
		len++;
	reply = ft_strnew(sizeof(wchar_t) * len);
	while (str[n])
	{
		if (str[n] < 128)
			reply[i++] = str[n++];
		else
		{
			temp = wide_cconvert(str[n++]);
			reply = add_wchar(reply, temp);
			i = i + ft_strlen(temp);
			ft_strdel(&temp);
		}
	}
	return (reply);
}

t_tab			wide_sconvert(t_tab tab)
{
	char	*reply;
	wchar_t	*str;
	int		len;

	if ((str = (wchar_t *)va_arg(*(tab.ap), wchar_t*)) == NULL)
		reply = ft_strdup("(null)");
	else
		reply = wide_string(str);
	len = (int)ft_strlen(reply);
	if (tab.precision > -1 && tab.precision < len)
	{
		reply = trunc_precision(reply, tab.precision);
		reply = string_precision(reply, tab.precision);
	}
	len = (int)ft_strlen(reply);
	if (tab.width > len)
		reply = width_parser(reply, tab);
	tab.reply = ft_strjoinfree(tab.reply, reply);
	tab.string = move_char((tab.string), 1);
	return (tab);
}
