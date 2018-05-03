/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:38:48 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/21 15:52:32 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	doevenmoreflags(t_flags *f, char *out)
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

static int	domoreflags(t_flags *f, char *output)
{
	char	*temp;

	if (f->hash && output[0] != '0')
	{
		temp = output;
		output = ft_strjoin("0", output);
		free(temp);
	}
	return (doevenmoreflags(f, output));
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

int			dofortypeo(t_flags *f, va_list ap)
{
	char	*output;

	if (!f->size)
		output = ft_itoabase((size_t)va_arg(ap, unsigned int), 8);
	else if (f->size == 1 && f->type != 'O')
		output = ft_itoabase((size_t)(unsigned char)va_arg(ap, size_t), 8);
	else if (f->size == 2 && f->type != 'O')
		output = ft_itoabase((size_t)(unsigned short)va_arg(ap, size_t), 8);
	else if (f->size == 4 && f->type != 'O')
		output = ft_itoabase((size_t)va_arg(ap, unsigned long long), 8);
	else if (f->size == 5 && f->type != 'O')
		output = ft_itoabase((size_t)va_arg(ap, uintmax_t), 8);
	else if (f->size == 6 && f->type != 'O')
		output = ft_itoabase(va_arg(ap, size_t), 8);
	else
		output = ft_itoabase((size_t)va_arg(ap, unsigned long), 8);
	if (!output)
		return (-1);
	else
		return (dotheflags(f, output));
}
