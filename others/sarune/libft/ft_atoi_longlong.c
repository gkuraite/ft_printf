/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:17:11 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/03 17:15:08 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_atoi_longlong(const char *str)
{
	unsigned long long	ret;

	ret = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret);
}
