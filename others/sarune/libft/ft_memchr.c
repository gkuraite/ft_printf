/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:23:34 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/30 19:14:47 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
