/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:35:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/04/28 17:51:47 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long value, int base)
{
	char	*buff;
	char	*digits;
	int		len;
	int		tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_numlen_umax(value, base);
	tmp = value % base;
	tmp *= (tmp < 0) ? -1 : 1;
	value /= base;
	buff = ft_strnew(len);
	digits = "0123456789ABCDEF";
	buff[len - 1] = digits[tmp];
	while (--len && value)
	{
		buff[len - 1] = digits[value % base];
		value /= base;
	}
	return (buff);
}
