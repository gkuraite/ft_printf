/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_longlong.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:13:47 by sivinska          #+#    #+#             */
/*   Updated: 2018/04/25 15:33:05 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_longlong(long long n)
{
	if (n == -9223372036854775807)
	{
		ft_putchar('-');
		ft_putnbr_longlong(9223372036854775807 / 10);
		ft_putnbr_longlong(9223372036854775807 % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_longlong(-n);
	}
	else if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_longlong(n / 10);
		ft_putnbr_longlong(n % 10);
	}
}
