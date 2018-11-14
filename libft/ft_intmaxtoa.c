/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:02:24 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/18 15:45:12 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(ssize_t nb)
{
	ssize_t		index;

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

char			*ft_intmaxtoa(ssize_t n)
{
	char		*str;
	ssize_t		index;

	if (n < 0 && n - 1 > 0)
		return (ft_strdup("-9223372036854775808"));
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
