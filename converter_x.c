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

/*static int	doevenmoreflags(t_flags *f, char *out)
{
	int ret;

	if (f->hash && ft_strstr(out, "x") > ft_strstr(out, "0") + 1)
	{
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "x"))] = '0';
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "0")) + 1] = 'x';
	}
	if (f->type == 'X')
		ft_toupperstr(&out);
	ft_putstr(out);
	ret = ft_strlen(out);
	free(out);
	return (ret);
}*/

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
    //return (doevenmoreflags(f, str));
}