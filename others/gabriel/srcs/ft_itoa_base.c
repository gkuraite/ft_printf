/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:25:19 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/22 14:25:51 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		absolute(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

static int		numlen(uintmax_t num, int base)
{
	int			len;

	len = 0;
	while (num != 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

static char		basetab(int num)
{
	char		*basetab;
	char		c;

	basetab = ft_strdup("0123456789abcdef");
	c = basetab[num];
	ft_strdel(&basetab);
	return (c);
}

char			*ft_itoa_base(uintmax_t num, int base)
{
	int			len;
	char		*reply;

	if (num == 0)
		return (ft_strdup("0"));
	len = numlen(num, base);
	reply = ft_strnew(len);
	len--;
	while (num != 0)
	{
		reply[len--] = basetab(absolute(num % base));
		num = num / base;
	}
	return (reply);
}
