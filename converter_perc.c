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
	char	*tmp;
	int		len;

	if (!(str = ft_strdup("%")))
		return (-1);
	while (f->width > (int)ft_strlen(str))
	{
		tmp = str;
		if (f->minus)
			str = ft_strjoin(str, " ");
		else if (f->zero)
			str = ft_strjoin("0", str);
		else
			str = ft_strjoin(" ", str);
		free(tmp);
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}