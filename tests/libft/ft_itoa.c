/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:22:40 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/21 14:44:50 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_finish(int n, int len, int neg)
{
	char *ret;

	ret = (char*)ft_strnew(len + neg + 1);
	if (!ret)
		return (NULL);
	if (neg)
		ret[0] = '-';
	ret[len + neg] = 0;
	while (n)
	{
		len--;
		ret[len + neg] = n % 10 + '0';
		n = n / 10;
	}
	if (!ft_strlen(ret))
		return (ft_strdup("0"));
	return (ret);
}

char		*ft_itoa(int n)
{
	int lenght;
	int nb;
	int neg;

	lenght = 0;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	nb = n;
	while (n)
	{
		lenght++;
		n = n / 10;
	}
	if (lenght == 0)
		return (ft_strdup("0"));
	return (ft_finish(nb, lenght, neg));
}
