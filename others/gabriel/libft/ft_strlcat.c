/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:18:09 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/28 12:47:40 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int n;
	unsigned int len;

	i = 0;
	n = 0;
	len = ft_strlen(dest);
	if (size <= len)
		return (ft_strlen(src) + size);
	else
	{
		while (dest[i])
			i++;
		while (src[n] && (i < size - 1))
			dest[i++] = src[n++];
	}
	dest[i] = '\0';
	return (ft_strlen(src) + len);
}
