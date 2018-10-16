/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:29:35 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/29 11:05:56 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int		i;
	unsigned int	n;
	unsigned int	t;

	i = 0;
	n = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t'
			|| str[n] == '\v' || str[n] == '\r' || str[n] == '\f')
		n++;
	t = n;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while (n < ft_strlen(str) && str[n] >= '0' && str[n] <= '9')
	{
		i = (i * 10) + (str[n] - '0');
		n++;
	}
	if (str[t] == '-')
		return (i * -1);
	else
		return (i);
}
