/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:29:20 by mfiguera          #+#    #+#             */
/*   Updated: 2018/03/28 16:37:56 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	domoreflags(char *out)
{
	char	*addr;
	int		i;

	i = 0;
	if (!(addr = ft_strstr(out, "()")))
		ft_putstr(out);
	else
	{
		while (out && out[i] && &out[i] < addr)
			ft_putchar(out[i++]);
		ft_putchar(0);
		i++;
		while (out && out[++i])
			ft_putchar(out[i]);
	}
	i = ft_strlen(out) - (ft_strstr(out, "()") ? 1 : 0);
	free(out);
	return (i);
}

static int	dotheflags(t_flags *f, char *out)
{
	char	*temp;
	int		s;

	if (f->width > (s = ft_strlen(out) - (ft_strstr(out, "()") ? 1 : 0)))
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
	return (domoreflags(out));
}

int			dofortypec(t_flags *f, va_list ap)
{
	char	*output;
	char	*temp;

	if (f->size == 3 || f->type == 'C')
		output = ft_mbstr(va_arg(ap, wchar_t));
	else
		output = ft_mbstr((unsigned char)va_arg(ap, int));
	if (!output)
		return (-1);
	if (!output[0])
	{
		temp = output;
		output = ft_strdup("()");
		free(temp);
	}
	return (dotheflags(f, output));
}
