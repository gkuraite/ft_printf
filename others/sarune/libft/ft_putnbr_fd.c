/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:46:42 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/24 12:24:29 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	char		str;

	i = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	str = i % 10 + '0';
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(str, fd);
}
