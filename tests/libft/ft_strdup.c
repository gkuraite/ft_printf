/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:32:45 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/26 16:57:44 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*sret;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	sret = (char *)malloc(sizeof(*s1) * (i + 1));
	if (!sret)
		return (sret);
	i = 0;
	while (s1[i])
	{
		sret[i] = s1[i];
		i++;
	}
	sret[i] = '\0';
	return (sret);
}
