/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:01:26 by mfiguera          #+#    #+#             */
/*   Updated: 2018/02/02 14:07:45 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrstr(const wchar_t *haystack, const wchar_t *needle)
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
			return ((wchar_t*)&haystack[s]);
		else
			h = s;
		h++;
	}
	if (!needle[0])
		return ((wchar_t*)&haystack[0]);
	return (NULL);
}
