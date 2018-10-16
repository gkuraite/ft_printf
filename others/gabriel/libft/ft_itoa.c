/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:36:57 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/28 15:44:21 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		ft_symcount(int n)
{
	int i;
	int puiss;
	int neg;

	i = 0;
	puiss = 1;
	neg = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		neg = 1;
	}
	while (puiss <= n && i < 10)
	{
		puiss = puiss * 10;
		i++;
	}
	if (neg == 1)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		t;

	i = ft_symcount(n) - 1;
	t = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((str = (char *)malloc(ft_symcount(n) + 1)) == NULL)
		return (NULL);
	if (n < 0)
		t = n * -1;
	if (n == 0)
		str[0] = '0';
	while (t > 0)
	{
		str[i] = ((t % 10) + '0');
		t = t / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[ft_symcount(n)] = '\0';
	return (str);
}
