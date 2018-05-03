/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:22:40 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/21 14:46:50 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_finish(ssize_t n, ssize_t len, int neg)
{
	char *ret;

	if (neg == -1)
		len++;
	ret = ft_strnew(len + 1);
	if (!ret)
		return (NULL);
	if (neg == -1)
		ret[0] = '-';
	ret[len] = 0;
	while (n)
	{
		len--;
		ret[len] = n % 10 + '0';
		n = n / 10;
	}
	if (!ft_strlen(ret))
		return (ft_strdup("0"));
	return (ret);
}

char		*ft_sttoa(ssize_t n)
{
	ssize_t	lenght;
	ssize_t	nb;
	int		neg;

	lenght = 0;
	neg = 1;
	if (n < 0 && n - 1 > 0)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		neg = -1;
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
