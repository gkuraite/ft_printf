/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:17:00 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/03 16:17:03 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_check_flags(t_flags *flags)
{
    if (flags->format[flags->i] == '+')
        flags->plus = 1;
    if (flags->format[flags->i] == '-')
        flags->minus = 1;
    if (flags->format[flags->i] == '0')
        flags->zero = 1;
    if (flags->format[flags->i] == ' ')
        flags->space = 1;
    if (flags->format[flags->i] == '#')
        flags->hash = 1;
}