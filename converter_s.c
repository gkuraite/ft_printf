/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:41:24 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/11 11:41:26 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     converter_s(t_flags *f, va_list *ap)
{
    char  *str;

    str = (char*)va_arg(*ap, char*);
    (void)f;

    ft_putstr(str);
    
    return (0);
}

