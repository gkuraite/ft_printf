/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:55:02 by gkuraite          #+#    #+#             */
/*   Updated: 2018/02/15 19:13:59 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		range;
	char	*str;

	if (!src)
		return (NULL);
	range = 0;
	i = 0;
	while (src[range])
		range++;
	str = (char*)malloc(sizeof(*str) * (range + 1));
	if (str == NULL)
		return (NULL);
	while (i < range)
	{
		str[i] = src[i];
		i++;
	}
	str[range] = '\0';
	return (str);
}
