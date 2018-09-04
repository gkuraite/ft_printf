/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:47:36 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/30 18:33:58 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src)
		return (dst);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n > 0)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return ((void*)(d + 1));
		d++;
		s++;
		n--;
	}
	return (NULL);
}
