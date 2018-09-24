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

//yunus
static intmax_t	convert_size_di(va_list ap, t_flags *f)
{
	intmax_t	nb;

	printf("f->size = %d\n", f->size);
	if (f->size == 2)
		nb = (signed char)(va_arg(ap, int));
	else if (f->size == 1)
		nb = (short)(va_arg(ap, int));
	else if (f->size == 4)
		nb = (long long)(va_arg(ap, long long int));
	else if (f->size == 3)
		nb = (long)(va_arg(ap, long));
	else if (f->size == 5)
		nb = (intmax_t)(va_arg(ap, intmax_t));
	else if (f->size == 6)
		nb = (size_t)(va_arg(ap, size_t));
	else
		nb = (int)(va_arg(ap, int));
	nb = (intmax_t)nb;
	//printf("nb = %zu\n", nb);
	return (nb);
}

int     converter_d(t_flags *f, va_list *ap)
{
	size_t	num;
	char	*str;	
	(void)f;
	
	num = convert_size_di(*ap, f);
	//if (num < 0)
	//	write(1, "-", 1);
	//printf("\nnum after conversion size %zu\n", num);
	str = ft_itoabase(num, 10);
	ft_putstr(str);
	//ft_putnbr(num);
	return (0);
}

