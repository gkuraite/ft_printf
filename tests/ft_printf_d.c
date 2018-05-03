/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:38:48 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/28 18:39:36 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	doevenevenmoreflags(t_flags *f, char *out)
{
	int s;

	if (ft_strstr(out, "-") > ft_strstr(out, "0") && ft_strstr(out, "0"))
	{
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "-"))] = '0';
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "0"))] = '-';
	}
	if (ft_strstr(out, "+") > ft_strstr(out, "0") && ft_strstr(out, "0"))
	{
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "+"))] = '0';
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "0"))] = '+';
	}
	if (ft_strstr(out, " ") > ft_strstr(out, "0") && ft_strstr(out, "0")
			&& f->zero)
	{
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, " "))] = '0';
		out[ft_strlen(out) - ft_strlen(ft_strstr(out, "0"))] = ' ';
	}
	ft_putstr(out + 0 * (s = ft_strlen(out)));
	free(out);
	return (s);
}

static int	doevenmoreflags(t_flags *f, char *out)
{
	char	*temp;
	int		s;

	if (f->width > (s = ft_strlen(out)))
	{
		while (s++ < f->width)
		{
			temp = out;
			if (f->minus)
				out = ft_strjoin(out, " ");
			else if (f->zero)
				out = ft_strjoin("0", out);
			else
				out = ft_strjoin(" ", out);
			free(temp);
		}
	}
	return (doevenevenmoreflags(f, out));
}

static int	domoreflags(t_flags *f, char *output)
{
	char	*temp;

	if ((f->plus || f->space) && !ft_strstr(output, "-") &&
			!ft_strstr(output, "+"))
	{
		temp = output;
		if (f->plus)
			output = ft_strjoin("+", output);
		else
			output = ft_strjoin(" ", output);
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
	if (f->precision != -6 && f->precision > (a = ft_strlen(output) -
			(output[0] == '-' ? 1 : 0)))
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

int			dofortypeid(t_flags *f, va_list ap)
{
	char	*output;

	if (!f->size && f->type != 'D')
		output = ft_sttoa((ssize_t)va_arg(ap, int));
	else if (f->size == 1 && f->type != 'D')
		output = ft_sttoa((ssize_t)(signed char)va_arg(ap, ssize_t));
	else if (f->size == 2 && f->type != 'D')
		output = ft_sttoa((ssize_t)(short)va_arg(ap, ssize_t));
	else if (f->size == 4 && f->type != 'D')
		output = ft_sttoa((ssize_t)va_arg(ap, long long));
	else if (f->size == 5 && f->type != 'D')
		output = ft_sttoa((ssize_t)va_arg(ap, intmax_t));
	else if (f->size == 6 && f->type != 'D')
		output = ft_sttoa(va_arg(ap, ssize_t));
	else
		output = ft_sttoa((ssize_t)va_arg(ap, long));
	if (!output)
		return (-1);
	else
		return (dotheflags(f, output));
}
