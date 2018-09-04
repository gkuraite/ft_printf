/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:16:11 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:27:19 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;

	if (*needle == '\0')
		return ((char*)haystack);
	l = ft_strlen(needle);
	while (*haystack != '\0' && len >= l)
	{
		if (ft_strncmp(haystack, needle, l) == 0)
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
