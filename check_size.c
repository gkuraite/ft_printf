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

static char     size(char c)
{
    return (c == 'h' || c == 'j' || c == 'l' || c == 'z');
}

int     check_size(t_flags *f)
{
    while (size(f->format[f->i]))
    {
        f->i++;
        if (f->format[f->i] == 'h')
        {
            if (f->format[f->i++] == 'h' && f->format++)
                f->size = 1;
            f->size = 2;
        }
        if (f->format[f->i] == 'l')
        {
            if (f->format[f->i++] == 'l' && f->format++)
                f->size = 3;
            f->size = 4;
        }
        if (f->format[f->i] == 'z')
            f->size = 5;
        if (f->format[f->i] == 'j')
            f->size = 6;
        f->i++;
    }
    return (f->i);
}