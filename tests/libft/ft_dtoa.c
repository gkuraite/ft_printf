/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:13:32 by mfiguera          #+#    #+#             */
/*   Updated: 2018/01/11 10:31:16 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double dbl, int precision)
{
	int		print;
	char	*ret;

	print = dbl;
	ret = ft_itoa(print);
	while (precision--)
	{
		print *= 10;
		dbl *= 10;
	}
	ret = ft_strjoin(ret, ".");
	print = dbl - print;
	if ((int)(dbl * 10 - print * 10) % 10 >= 5)
		print++;
	ret = ft_strjoin(ret, ft_itoa(print));
	return (ret);
}
