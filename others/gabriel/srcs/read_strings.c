/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:15:45 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 14:30:33 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*move_char(char *str, size_t i)
{
	char			*temp;

	temp = ft_strdup(str + i);
	ft_strdel(&str);
	return (temp);
}

char		*ft_realloc(char *str, size_t size)
{
	char			*temp;
	int				i;

	i = 0;
	if (!str)
	{
		str = ft_strnew(size);
		return (str);
	}
	temp = str;
	str = ft_strnew(ft_strlen(temp) + size);
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	ft_strdel(&temp);
	return (str);
}

t_tab		read_string(t_tab tab)
{
	unsigned int	n;
	unsigned int	i;
	unsigned int	len;

	n = 0;
	i = 0;
	len = ft_strlen(tab.reply);
	while (tab.string[n] && tab.string[n] != '%')
		n++;
	tab.reply = ft_realloc(tab.reply, n);
	while (i < n)
	{
		tab.reply[len + i] = tab.string[i];
		i++;
	}
	if (tab.string[i])
		tab.string = move_char((tab.string), i);
	else
		ft_strdel(&tab.string);
	return (tab);
}
