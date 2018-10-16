/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:04:04 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/06 14:17:39 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int t;

	i = 0;
	t = 0;
	while (dest[i])
		i++;
	while (src[t] && (t < n))
	{
		dest[i] = src[t];
		i++;
		t++;
	}
	dest[i] = 0;
	return (dest);
}
