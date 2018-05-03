/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:11 by mfiguera          #+#    #+#             */
/*   Updated: 2018/01/27 18:59:02 by mfiguera         ###   ########.fr       */
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
	size_t	lenght;
	size_t	nb;

	lenght = 0;
	nb = n;
	while (n)
	{
		lenght++;
		n = n / 10;
	}
	if (lenght == 0)
		return (ft_strdup("0"));
	return (ft_finish(nb, lenght));
}
