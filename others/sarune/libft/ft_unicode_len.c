/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:14:52 by sivinska          #+#    #+#             */
/*   Updated: 2018/04/25 12:19:32 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			binary_to_dec(unsigned long long nbr)
{
	unsigned int		ret;
	unsigned int		tmp;
	int					i;

	i = 0;
	ret = 0;
	while (nbr != 0)
	{
		tmp = nbr % 10;
		nbr /= 10;
		ret += tmp * ft_pow(2, i++);
	}
	return (ret);
}

static unsigned long long	dec_to_binary(unsigned int c)
{
	unsigned long long		binary;
	char					*str;

	str = ft_convert_to_base(c, 2);
	if (!str)
		return (0);
	binary = ft_atoi_longlong(str);
	free(str);
	return (binary);
}

int							ft_unicode_len(unsigned int c)
{
	unsigned long long		binary;
	unsigned int			helper;
	unsigned int			counter;
	unsigned int			i;
	char					arr[7];

	counter = 0;
	binary = dec_to_binary(c);
	while (6 - counter < (unsigned int)ft_get_nbr_len(binary) && binary)
	{
		helper = 10000000 + binary % (unsigned int)ft_pow(10, 6);
		arr[counter++] = binary_to_dec(helper);
		binary /= ft_pow(10, 6);
	}
	helper = 10000000;
	i = 0;
	while (i < counter)
		helper += ft_pow(10, 6 - i++);
	helper += binary % (unsigned int)ft_pow(10, 6);
	arr[counter++] = binary_to_dec(helper);
	arr[counter] = '\0';
	ft_strrev(arr);
	return (ft_strlen(arr));
}
