/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:55:37 by gkuraite          #+#    #+#             */
/*   Updated: 2018/10/16 16:43:48 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_toupperstr(char **str)
{
	int i;

	i = 0;
	while (str && str[0] && str[0][i])
	{
		if (str[0][i] >= 'a' && str[0][i] <= 'z')
			str[0][i] = ft_toupper(str[0][i]);
		i++;
	}
}
