/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:34:21 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:26:28 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s + ft_strlen(s);
	while (*str != (char)c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}
