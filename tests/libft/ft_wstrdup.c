/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:32:45 by mfiguera          #+#    #+#             */
/*   Updated: 2018/02/02 14:05:34 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	int		i;
	wchar_t	*sret;

	i = 0;
	while (s1[i])
		i++;
	sret = (wchar_t *)malloc(sizeof(*s1) * (i + 1));
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
