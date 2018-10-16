/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:07:20 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 13:28:00 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*dest;
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = ft_strlen(s1);
	if ((dest = (char*)malloc(l + 1)) == NULL)
		return (0);
	while (i < l)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
