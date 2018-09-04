/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:48:01 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:37:34 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int nb)
{
	int		i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i = i - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		*str = '0';
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
