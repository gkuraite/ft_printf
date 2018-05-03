/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:00:12 by mfiguera          #+#    #+#             */
/*   Updated: 2018/02/02 14:08:15 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	int		tlength1;
	int		tlength2;
	wchar_t	*ret;

	tlength1 = 0;
	tlength2 = 0;
	if (!s1 || !s2)
		return (NULL);
	tlength1 = ft_wstrlen(s1);
	while (s2[tlength2])
		tlength2++;
	ret = (wchar_t*)malloc(sizeof(*ret) * (tlength1 + tlength2 + 1));
	if (!ret)
		return (ret);
	tlength1 = 0;
	tlength2 = 0;
	while (s1[tlength1])
	{
		ret[tlength1] = s1[tlength1];
		tlength1++;
	}
	while (s2[tlength2])
		ret[tlength1++] = s2[tlength2++];
	ret[tlength1] = '\0';
	return (ret);
}
