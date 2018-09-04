/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:19:34 by sivinska          #+#    #+#             */
/*   Updated: 2018/04/25 13:20:28 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nbr, int times)
{
	int		ret;
	int		i;

	i = 1;
	ret = nbr;
	if (times == 0)
		return (1);
	while (i++ < times)
		ret *= nbr;
	return (ret);
}
