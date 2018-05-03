/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:12:36 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/26 17:18:06 by mfiguera         ###   ########.fr       */
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

	temp = output;
	output = ft_strjoin("0x", output);
	free(temp);
	if (!output)
		output = ft_strdup("");
	return (domoreflags(f, output));
}

int			dofortypep(t_flags *f, va_list ap)
{
	char	*out;

	out = ft_itoabase((size_t)va_arg(ap, unsigned long int), 16);
	if (!out)
		return (-1);
	else
		return (dotheflags(f, out));
}
