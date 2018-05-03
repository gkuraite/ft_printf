/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:31:16 by mfiguera          #+#    #+#             */
/*   Updated: 2018/02/01 14:54:48 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	h;
	int	n;
	int s;

	h = 0;
	while (haystack[h])
	{
		n = 0;
		s = h;
		while (needle[n] && haystack[h] == needle[n])
		{
			n++;
			h++;
		}
		if (!needle[n])
			return ((char*)&haystack[s]);
		else
			h = s;
		h++;
	}
	if (!needle[0])
		return ((char*)&haystack[0]);
	return (NULL);
}
