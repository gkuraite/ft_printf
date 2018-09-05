/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:24:24 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/04 13:24:26 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     check_precision(t_flags *f)
{
    if (f->format[f->i] == '.')
    {
        f->i++;
        while (ft_isdigit(f->format[f->i]))
        {
            f->precision *= 10;
            f->precision += (f->format[f->i] - 48);
            f->i++;  
        }
    }
}