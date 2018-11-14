/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:39:31 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:43:28 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_finish(size_t n, size_t len)
{
	char *ret;

	ret = ft_strnew(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (n)
	{
		len--;
		ret[len] = n % 10 + '0';
		n = n / 10;
	}
	if (!ft_strlen(ret))
		return (ft_strdup("0"));
	return (ret);
}

char		*ft_utoa(size_t n)
{
	size_t	length;
	size_t	nb;

	length = 0;
	nb = n;
	while (n)
	{
		length++;
		n = n / 10;
	}
	if (length == 0)
		return (ft_strdup("0"));
	return (ft_finish(nb, length));
}
