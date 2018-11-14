/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:19:54 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:42:13 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		line1;
	int		line2;
	char	*ret;

	line1 = 0;
	line2 = 0;
	if (!(ret = ft_strnew(ft_strlen(s1) + n + 1)))
		return (NULL);
	while (s1[line1])
	{
		ret[line1] = s1[line1];
		line1++;
	}
	while (s2[line2] && line2 < n)
		ret[line1++] = s2[line2++];
	ret[line1] = 0;
	return (ret);
}
