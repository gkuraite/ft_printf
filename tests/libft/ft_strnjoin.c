/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:44:19 by mfiguera          #+#    #+#             */
/*   Updated: 2018/02/01 14:54:12 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		l1;
	int		l2;
	char	*ret;

	l1 = 0;
	l2 = 0;
	if (!(ret = ft_strnew(ft_strlen(s1) + n + 1)))
		return (NULL);
	while (s1[l1])
	{
		ret[l1] = s1[l1];
		l1++;
	}
	while (s2[l2] && l2 < n)
		ret[l1++] = s2[l2++];
	ret[l1] = 0;
	return (ret);
}
