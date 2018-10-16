/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:17:20 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/20 18:28:55 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*dest;

	i = ft_strlen(str);
	dest = (char*)str;
	while (str[i] != c && (i > 0))
		i--;
	if (str[i] == c)
		return (&dest[i]);
	else
		return (NULL);
}
