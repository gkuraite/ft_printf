/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:13:32 by mfiguera          #+#    #+#             */
/*   Updated: 2018/01/16 10:34:13 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float flt, int precision)
{
	int		print;
	char	*ret;
	int		sign;

	sign = 1;
	if (precision == -6)
		precision = 6;
	if (flt < 0)
		sign = -1;
	print = flt;
	ret = ft_itoa(print);
	if (precision)
	{
		while (precision--)
		{
			print *= 10;
			flt *= 10;
		}
		ret = ft_strjoin(ret, ".");
		print = flt - print;
		if ((int)(10 * flt - 10 * print) % 10 >= 5)
			print++;
		ret = ft_strjoin(ret, ft_itoa(print * sign));
	}
	return (ret);
}
