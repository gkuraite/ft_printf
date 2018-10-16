/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:55:17 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 13:59:02 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *foin, const char *aig, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	i = 0;
	j = 0;
	dest = (char*)foin;
	if (ft_strcmp(aig, "") == 0)
		return (dest);
	while (foin[i] && (i < len))
	{
		if (foin[i] == aig[0])
		{
			while (foin[i + j] == aig[j] && (i + j) < len)
			{
				j++;
				if (j == ft_strlen(aig))
					return (&dest[i]);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
