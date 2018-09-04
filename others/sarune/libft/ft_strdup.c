/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:15:39 by sivinska          #+#    #+#             */
/*   Updated: 2018/02/10 16:46:10 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	dst = (char*)malloc(sizeof(*dst) * (i + 1));
	if (dst == NULL)
		return (NULL);
	while (j < i)
	{
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
