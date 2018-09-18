/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:24:51 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/12 11:24:53 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     converter_x(t_flags *f, va_list *ap)
{
    int num;
    char	*str;
    (void)f;
    
    num = (int)va_arg(*ap, int);
    printf("\n NUM = %d\n", num);
    str = ft_itoabase(num, 16);
    ft_putstr(str);
    return (0);
}