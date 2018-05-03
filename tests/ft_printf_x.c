/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:13:18 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/28 18:40:08 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	doevenmoreflags(t_flags *f, char *out)
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
}

static int	domoreflags(t_flags *f, char *output)
{
	char	*temp;
	int		s;

	if (f->width > (s = ft_strlen(output)))
	{
		while (s < f->width)
		{
			temp = output;
			if (f->minus)
				output = ft_strjoin(output, " ");
			else if (f->zero)
				output = ft_strjoin("0", output);
			else
				output = ft_strjoin(" ", output);
			free(temp);
			s++;
		}
	}
	return (doevenmoreflags(f, output));
}

static int	dotheflags(t_flags *f, char *output)
{
	char	*temp;
	int		a;

	if (f->hash && (temp = output) && output[0] && output[0] != '0')
	{
		output = ft_strjoin("0x", output);
		free(temp);
	}
	else
		f->hash = 0;
	if (!f->precision && output && output[0] == '0' && !f->hash)
		output = NULL;
	if (!output)
		output = ft_strdup("");
	if (f->precision != -6 && f->precision > (a = ft_strlen(output) -
				2 * f->hash))
	{
		while (a++ < f->precision)
		{
			temp = output;
			output = ft_strjoin("0", output);
			free(temp);
		}
	}
	return (domoreflags(f, output));
}

int			dofortypex(t_flags *f, va_list ap)
{
	char	*out;

	if (f->size == 1)
		out = ft_itoabase((size_t)(unsigned char)va_arg(ap, size_t), 16);
	if (f->size == 2)
		out = ft_itoabase((size_t)(unsigned short int)va_arg(ap, size_t), 16);
	if (f->size == 3)
		out = ft_itoabase((size_t)va_arg(ap, unsigned long int), 16);
	if (f->size == 4)
		out = ft_itoabase((size_t)va_arg(ap, unsigned long long int), 16);
	if (f->size == 5)
		out = ft_itoabase((size_t)va_arg(ap, uintmax_t), 16);
	if (f->size == 6)
		out = ft_itoabase(va_arg(ap, size_t), 16);
	if (!f->size)
		out = ft_itoabase((size_t)va_arg(ap, unsigned int), 16);
	if (!out)
		return (-1);
	else
		return (dotheflags(f, out));
}
