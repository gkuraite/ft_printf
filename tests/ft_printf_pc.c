/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:29:20 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/22 14:25:58 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			dofortypepc(t_flags *f)
{
	char	*out;
	char	*temp;
	int		s;

	if (!(out = ft_strdup("%")))
		return (-1);
	if (f->width > (s = ft_strlen(out)))
	{
		while (s < f->width)
		{
			temp = out;
			if (f->minus)
				out = ft_strjoin(out, " ");
			else if (f->zero)
				out = ft_strjoin("0", out);
			else
				out = ft_strjoin(" ", out);
			free(temp);
			s++;
		}
	}
	ft_putstr(out);
	s = ft_strlen(out);
	free(out);
	return (s);
}
