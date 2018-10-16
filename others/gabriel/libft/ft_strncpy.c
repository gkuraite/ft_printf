/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:39:53 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/06 13:53:55 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == 0)
		while (i < len)
		{
			dest[i] = 0;
			i++;
		}
	return (dest);
}
