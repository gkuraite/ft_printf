/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:58:18 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/11 11:58:21 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int     converter_u(t_flags *f, va_list *ap)
{
	int num;
	char	*str;
	(void)f;
	
	num = (int)va_arg(*ap, int);
	printf("\n NUM = %d\n", num);
	str = ft_utoa(num);
	//printf("str = [%s]", str);
	ft_putstr(str);
	return (0);
}