/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:56:44 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 07:44:48 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*adjust_string(char *str, int precision)
{
	int		len;
	char	*adjusted;
	int		i;
	int		n;
	char	c;

	i = 0;
	n = 0;
	len = (int)ft_strlen(str);
	c = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		precision++;
		c = str[0];
		str[0] = '0';
	}
	adjusted = ft_strnew(precision);
	while (i < precision - len)
		adjusted[i++] = '0';
	while (i < precision)
		adjusted[i++] = str[n++];
	if (c)
		adjusted[0] = c;
	ft_strdel(&str);
	return (adjusted);
}

char	*precision_solver(char *str, int precision)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strcmp(str, "0") == 0 && precision == 0)
	{
		ft_strdel(&str);
		return (ft_strdup(""));
	}
	else if (precision == -1 || len > precision)
		return (str);
	else
		str = adjust_string(str, precision);
	return (str);
}
