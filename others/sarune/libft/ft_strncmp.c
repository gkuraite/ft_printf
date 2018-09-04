/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:39:51 by sivinska          #+#    #+#             */
/*   Updated: 2017/11/29 18:28:24 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		i = (unsigned char)*s1 - (unsigned char)*s2;
		if (i != 0)
			return (i);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
