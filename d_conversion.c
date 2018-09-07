/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:33:42 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/06 10:46:54 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	modifier_size_d(va_list *ap, t_flags *f)
{

	char *str;

	if (f->size == 2 && f->format[f->i] != 'D')
		str = (long long)((signed char)va_arg(*ap, int));
	else if (!f->size && f->format[f->i] != 'D')
		str = (int)(va_arg(*ap, int));
	else if (f->size == 1 && f->format[f->i] != 'D')
		str = (long long)((short int)va_arg(*ap, int));
	else if (f->size == 4)
		str = (long long)va_arg(*ap, long long);
	else if (f->size == 5)
		str = (intmax_t)va_arg(*ap, intmax_t);
	else if (f->size == 6)
		str = (long long)va_arg(*ap, size_t);
	else
		str = (long long)va_arg(*ap, intmax_t);
	if (!str)
		return (-1);
	return (str);
	//return (addthezeros());
}

int     d_conversion(t_flags *f, va_list *ap)
{
    int num;
	
	num = (int)va_arg(*ap, int);

	if (f->type != 'D')
		modifier_size_d(num);
		printf("\nwhat's inside %d\n", num);
    	ft_putnbr(num);
	return (0);
}

/*static int		addthezeros(t_flags *f, char *out)
{
	char	*tmp;
	int		i;

	if (f->precison > (i = ft_strlen(out) - (output[0] == '-' ? 1 : 0)))
	{
		while (f->precision > i)
		{
			tmp = out;
			out = ft_strjoin("0", out);
			free(tmp);
			a++;
		}
	}
}*/

