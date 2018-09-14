/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:33:42 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/06 10:46:54 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int     converter_d(t_flags *f, va_list *ap)
{
	int num;
	(void)f;
	
	num = (int)va_arg(*ap, int);

		printf("\nwhat's inside %d\n", num);
    	ft_putnbr(num);
	return (0);
}

