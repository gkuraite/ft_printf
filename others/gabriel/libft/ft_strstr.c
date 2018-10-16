/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:27:18 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 14:46:19 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *foin, const char *aiguille)
{
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	i = 0;
	j = 0;
	dest = (char*)foin;
	if (ft_strcmp(aiguille, "") == 0)
		return (dest);
	while (foin[i])
	{
		if (foin[i] == aiguille[0])
		{
			while (foin[i + j] == aiguille[j])
			{
				j++;
				if (j == ft_strlen(aiguille))
					return (&dest[i]);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
