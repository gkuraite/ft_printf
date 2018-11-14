/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:07:28 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:40:04 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase(size_t nbr, int base)
{
	char	*bse;
	char	*tmp;
	char	*ret;

	bse = "0123456789abcdef";
	ret = ft_strdup("");
	while (nbr)
	{
		tmp = ret;
		ret = ft_strnjoin(ret, &bse[nbr % base], 1);
		nbr = nbr / base;
		free(tmp);
	}
	if (ft_strlen(ret) == 0)
	{
		tmp = ret;
		ret = ft_strnjoin(ret, &bse[0], 1);
		free(tmp);
	}
	ft_strrev(&ret);
	return (ret);
}
