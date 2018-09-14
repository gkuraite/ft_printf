/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:24:26 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/12 11:24:28 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     converter_o(t_flags *f, va_list *ap)
{
    int num;
	char	*str;
	(void)f;
	
	num = (int)va_arg(*ap, int);
	printf("\n NUM = %d\n", num);
	str = ft_itoabase(num, 8);
	ft_putstr(str);
	return (0);
}
}
