/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:26:12 by mfiguera          #+#    #+#             */
/*   Updated: 2018/02/01 14:52:36 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tlength1;
	int		tlength2;
	char	*ret;

	tlength1 = 0;
	tlength2 = 0;
	if (!s1 || !s2)
		return (NULL);
	tlength1 = ft_strlen(s1);
	while (s2[tlength2])
		tlength2++;
	ret = (char*)malloc(sizeof(*ret) * (tlength1 + tlength2 + 1));
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
