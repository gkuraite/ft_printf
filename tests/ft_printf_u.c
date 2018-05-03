/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:07:57 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/28 18:39:49 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	domoreflags(t_flags *f, char *out)
{
	char	*temp;
	int		s;

	if (f->width > (s = ft_strlen(out)))
	{
		while (s < f->width)
		{
			temp = out;
			if (f->minus)
				out = ft_strjoin(out, " ");
			else if (f->zero)
				out = ft_strjoin("0", out);
			else
				out = ft_strjoin(" ", out);
			free(temp);
			s++;
		}
	}
	ft_putstr(out);
	s = ft_strlen(out);
	free(out);
	return (s);
}

static int	dotheflags(t_flags *f, char *output)
{
	char	*temp;
	int		a;

	if (!f->precision && output && output[0] == '0')
	{
		temp = output;
		output = ft_strdup("");
		free(temp);
	}
	if (f->precision != -6 && f->precision > (a = ft_strlen(output)))
	{
		while (a < f->precision)
		{
			temp = output;
			output = ft_strjoin("0", output);
			free(temp);
			a++;
		}
	}
	return (domoreflags(f, output));
}

int			dofortypeu(t_flags *f, va_list ap)
{
	char	*output;

	if (!f->size && f->type != 'U')
		output = ft_utoa((size_t)va_arg(ap, unsigned int));
	else if (f->size == 1 && f->type != 'U')
		output = ft_utoa((size_t)(unsigned char)va_arg(ap, size_t));
	else if (f->size == 2 && f->type != 'U')
		output = ft_utoa((size_t)(unsigned short)va_arg(ap, size_t));
	else if (f->size == 4 && f->type != 'U')
		output = ft_utoa((size_t)va_arg(ap, unsigned long long));
	else if (f->size == 5 && f->type != 'U')
		output = ft_utoa((size_t)va_arg(ap, uintmax_t));
	else if (f->size == 6 && f->type != 'U')
		output = ft_utoa(va_arg(ap, size_t));
	else
		output = ft_utoa((size_t)va_arg(ap, unsigned long));
	if (!output)
		return (-1);
	else
		return (dotheflags(f, output));
}
