/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:44:44 by gkuraite          #+#    #+#             */
/*   Updated: 2017/12/13 15:08:15 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int nb)
{
	int		index;

	index = 0;
	if (nb <= 0)
		index++;
	while (nb)
	{
		index++;
		nb = nb / 10;
	}
	return (index);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_intlen(n) + 1))))
		return (NULL);
	str[index] = '\0';
	index = ft_intlen(n) - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		*str = '0';
	while (n > 0)
	{
		str[index] = '0' + (n % 10);
		n = n / 10;
		index--;
	}
	return (str);
}
