/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_len_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:02:46 by sivinska          #+#    #+#             */
/*   Updated: 2018/04/25 15:46:39 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nbr_len_unsigned(unsigned long long n)
{
	int				ret;

	ret = 1;
	while (n /= 10)
		ret++;
	return (ret);
}
