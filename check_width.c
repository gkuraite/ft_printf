/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:02:34 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/03 17:02:37 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(t_flags *f)
{
	while (ft_isdigit(f->format[f->i]))
	{
		f->width *= 10;
		f->width += (f->format[f->i] - 48);
		f->i++;
	}
	if (f->width > INT_MAX || f->width <= 0)
		f->width= 0;
}