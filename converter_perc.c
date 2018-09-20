/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:09:46 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/20 14:09:48 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int			converter_perc(t_flags *f)
{
	char	*str;
	(void)f;

	if (!(str = ft_strdup("%")))
		return (-1);
	ft_putstr(str);
	free(str);
	return (0);
}