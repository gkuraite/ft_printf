/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 07:22:55 by ghaddad           #+#    #+#             */
/*   Updated: 2017/12/08 07:27:53 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if ((str = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
