/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:36:25 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/28 18:37:30 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	domoreflags(t_flags *f, char *out, int len)
{
	int		s;
	char	*temp;

	while (f->type == 'S' ? len < f->width : (int)ft_strlen(out) < f->width)
	{
		temp = out;
		if (f->minus)
			out = ft_strjoin(out, " ");
		else if (f->zero)
			out = ft_strjoin("0", out);
		else
			out = ft_strjoin(" ", out);
		free(temp);
		len++;
	}
	ft_putstr(out);
	s = ft_strlen(out);
	free(out);
	return (s);
}

static int	dotheflags(t_flags *f, char *out, int len)
{
	char	*temp;
	int		s;

	s = 0;
	while (f->precision != -6 && f->precision < (int)ft_strlen(out) &&
			(out[f->precision] & 0xC0) == 0x80 && (s = 1))
		f->precision--;
	if (s)
		len--;
	if (f->precision != -6 && f->precision < (int)ft_strlen(out))
	{
		temp = out;
		out = ft_strsub(out, 0, f->precision);
		free(temp);
	}
	return (domoreflags(f, out, len));
}

int			dofortypes(t_flags *f, va_list ap)
{
	char	*output;
	wchar_t	*str;
	int		i;

	i = 0;
	if (f->type == 'S')
	{
		if (!(str = va_arg(ap, wchar_t*)))
			output = NULL;
		else
			output = ft_strdup("");
		while (output && str[i])
			output = ft_strjoinfree(output, ft_mbstr(str[i++]));
	}
	else
		output = ft_strdup(va_arg(ap, char*));
	if (!output)
		output = ft_strdup("(null)");
	return (dotheflags(f, output, i));
}
