/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:57:54 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/30 18:34:17 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == dst)
		return (dst);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}
