/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:09:53 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/12 12:09:59 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     converter_p(t_flags *f, va_list *ap)
{
    intmax_t num;
    char	*str;
    char    *tmp;
    (void)f;
    
    num = va_arg(*ap, intmax_t);
    //printf("\n NUM = %d\n", num);
    str = ft_itoabase(num, 16);
    tmp = str;
    str = ft_strjoin("0x", str);
    free(tmp);
    ft_putstr(str);
    return (0);
}