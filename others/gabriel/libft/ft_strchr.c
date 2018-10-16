/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:01:13 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 15:09:45 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)str;
	while (dest[i] != c && dest[i])
		i++;
	if (dest[i] == c)
		return (&dest[i]);
	else
		return (NULL);
}
