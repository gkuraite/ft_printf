/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:42:33 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:26:58 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (*needle == '\0' && *haystack == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		k = i;
		j = 0;
		while (haystack[k] == needle[j] && needle[j] != '\0')
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
