/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:56:07 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/22 15:58:49 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
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
	tlength1 = -1;
	tlength2 = 0;
	while (s1[++tlength1])
		ret[tlength1] = s1[tlength1];
	while (s2[tlength2])
		ret[tlength1++] = s2[tlength2++];
	ret[tlength1] = '\0';
	free(s1);
	free(s2);
	return (ret);
}
