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

static char *handle_flags(t_flags *f, char *str)
{
    if (f->hash && ft_strstr(str, "x") > ft_strstr(str, "0") + 1)
    {
        str[ft_strlen(str) - ft_strlen(ft_strstr(str, "x"))] = '0';
         str[ft_strlen(str) - ft_strlen(ft_strstr(str, "0")) + 1] = 'x';
    }
    ft_putstr(str);
    //free(str);
    return (str);
}

static char *handle_width(t_flags *f, char *str)
{
    char    *tmp;
    int     i;

    if (f->width > (i = ft_strlen(str)))
    {
        while (i < f->width)
        {
            tmp = str;
            if (f->minus)
                str = ft_strjoin(str, " ");
            if (f->zero)
                str = ft_strjoin("0", str);
            else
                str = ft_strjoin(" ", str);
            free(tmp);
            i++;
        }
    }
    return (str);
}

int     converter_p(t_flags *f, va_list *ap)
{
    intmax_t num;
    int     ret;
    char	*str;
    char    *tmp;
    //(void)f;
    
    num = va_arg(*ap, intmax_t);
    str = ft_itoabase(num, 16);
    tmp = str;
    str = ft_strjoin("0x", str);
    free(tmp);
    str = handle_width(f, str);
    str = handle_flags(f, str);
    //ft_putstr(str);
    ret = ft_strlen(str);
    free(str);
    printf("ret = %d\n", ret);
    return (ret);
    //return (0);
}