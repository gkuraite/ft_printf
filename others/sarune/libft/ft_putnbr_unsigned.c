/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:10:01 by sivinska          #+#    #+#             */
/*   Updated: 2018/04/25 15:48:23 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned long long n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
}
