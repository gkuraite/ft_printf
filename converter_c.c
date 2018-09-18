/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:24:37 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/12 11:24:39 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     converter_c(t_flags *f, va_list *ap)
{
    wchar_t  c;
    
        c = (wchar_t)va_arg(*ap, wchar_t);
        (void)f;
    
        ft_putchar(c);
        
        return (0);
}