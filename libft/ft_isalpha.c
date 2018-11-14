/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:02:29 by gkuraite          #+#    #+#             */
/*   Updated: 2017/11/30 19:17:26 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isupper(int c)
{
	while (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int		ft_islower(int c)
{
	while (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int				ft_isalpha(int c)
{
	while (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
