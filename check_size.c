/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:45:02 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/04 14:45:04 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    check_size(t_flags *f)
{
    if (f->format[f->i] == 'h')
    {
        f->size = 1;
        if (f->format[f->i + 1] == 'h')
            f->size = 2;
    }
    if (f->format[f->i] == 'l')
    {      
        f->size = 3;
        if (f->format[f->i + 1] == 'l')
            f->size = 4;
    }
    if (f->format[f->i] == 'z')
    {   
        f->size = 5;
        if (f->format[f->i + 1] == 'z')
            printf_errors(1);
    }
    if (f->format[f->i] == 'j')
    {
        f->size = 6;
        if (f->format[f->i + 1] == 'z')
             printf_errors(1);
    }
    f->i++;
}