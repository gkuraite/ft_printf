/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:43:42 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/20 15:35:04 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase(size_t nbr, int base)
{
	char	*bse;
	char	*temp;
	char	*ans;

	bse = "0123456789abcdef";
	ans = ft_strdup("");
	while (nbr)
	{
		temp = ans;
		ans = ft_strnjoin(ans, &bse[nbr % base], 1);
		nbr = nbr / base;
		free(temp);
	}
	if (ft_strlen(ans) == 0)
	{
		temp = ans;
		ans = ft_strnjoin(ans, &bse[0], 1);
		free(temp);
	}
	ft_strrev(&ans);
	return (ans);
}
