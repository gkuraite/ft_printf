/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:12:48 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/28 12:01:31 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *srcnew;
	char *destnew;

	srcnew = (char*)src;
	destnew = (char*)dest;
	if (srcnew < destnew)
		while (n--)
			destnew[n] = srcnew[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
