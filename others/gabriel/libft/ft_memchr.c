/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:12:31 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 11:07:14 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char*)str;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return (&dest[i]);
		i++;
	}
	return (NULL);
}
