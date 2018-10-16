/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:22:52 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 15:05:05 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && (str1[i] == str2[i]) && (i < (n - 1)))
		i++;
	if (str1[i] == 0 && str2[i] == 0)
		return (0);
	c1 = (unsigned char)str1[i];
	c2 = (unsigned char)str2[i];
	return (c1 - c2);
}
