/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:13:34 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 14:15:21 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		precision_analysis(t_tab *tab, int i)
{
	int				len;
	char			*num;
	int				n;

	len = 1;
	n = -1;
	if (tab->string[i] == '.')
	{
		if (tab->string[i + 1] > 47 && tab->string[i + 1] < 58)
		{
			i++;
			while (tab->string[i + len] && tab->string[i + len] > 47
										&& tab->string[i + len] < 58)
				len++;
			num = ft_strnew(len);
			while (++n < len)
				num[n] = tab->string[i + n];
			tab->precision = ft_atoi(num);
			ft_strdel(&num);
		}
		else
			tab->precision = 0;
		i = i + len - 1;
	}
	return (i);
}

static int		width_analysis(t_tab *tab, int i)
{
	char			*num;
	unsigned int	len;
	unsigned int	n;

	len = 0;
	n = 0;
	num = NULL;
	if (tab->string[i] > 47 && tab->string[i] < 58)
	{
		while (tab->string[i + len] > 47 && tab->string[i + len] < 58)
			len++;
		num = ft_strnew(len);
		while (n < len)
		{
			num[n] = tab->string[i + n];
			n++;
		}
		tab->width = ft_atoi(num);
		i = i + len - 1;
	}
	if (num)
		ft_strdel(&num);
	i = precision_analysis(tab, i);
	return (i);
}

static int		next_flags(t_tab *tab, int i)
{
	if (tab->string[i] == '0' && (tab->string[i - 1] < '0'
								|| tab->string[i - 1] > '9'))
		tab->zero = 1;
	if (tab->string[i] == 'h')
	{
		tab->h = 1;
		if (tab->string[i + 1] == 'h')
		{
			i++;
			tab->h = 2;
		}
	}
	if (tab->string[i] == 'l')
	{
		tab->l = 1;
		if (tab->string[i + 1] == 'l')
		{
			i++;
			tab->l = 2;
		}
	}
	i = width_analysis(tab, i);
	return (i);
}

t_tab			read_flags(t_tab tab)
{
	int				i;

	i = 1;
	while (tab.string[i] && !ft_strchr(tab.specifier_tab, tab.string[i])
						&& ft_strchr(tab.flag_tab, tab.string[i]))
	{
		if (tab.string[i] == '-')
			tab.minus = 1;
		if (tab.string[i] == '+')
			tab.plus = 1;
		if (tab.string[i] == ' ')
			tab.space = 1;
		if (tab.string[i] == '#')
			tab.sharp = 1;
		if (tab.string[i] == 'j')
			tab.j = 1;
		if (tab.string[i] == 'z')
			tab.z = 1;
		i = next_flags(&tab, i);
		i++;
	}
	if (tab.minus && tab.zero)
		tab.zero = 0;
	tab.string = move_char(tab.string, i);
	return (tab);
}
