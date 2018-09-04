/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 18:47:38 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 15:02:17 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unicode_len(t_flags *flag, wchar_t *str)
{
	int size;

	size = 0;
	if (flag->dot && flag->precision == 0)
		return (0);
	while (*str)
	{
		if ((unsigned int)*str <= 127)
			size += 1;
		else
			size += ft_unicode_len(*str);
		if (flag->dot && size > flag->precision)
			break ;
		str++;
	}
	return (size);
}

static int	print_gaps(t_flags *flag, wchar_t *str)
{
	int		len;

	len = flag->width;
	if (!str)
		len -= (flag->precision > 6 ? 6 : flag->precision);
	else
		len -= unicode_len(flag, str);
	fill_with_char(len, ' ');
	return (len > 0 ? len : 0);
}

static int	null_case(t_flags *flag)
{
	char	*null;
	char	*cpy;
	int		size;
	int		ret;

	null = ft_strdup("(null)");
	cpy = null;
	size = 0;
	ret = 0;
	while (*null)
	{
		size += 1;
		if (flag->dot && size > flag->precision)
			break ;
		ret += ft_putchar_ret(*null);
		null++;
	}
	free(cpy);
	return (ret);
}

static void	do_string(t_flags *flag, wchar_t *str, int *ret)
{
	int		size;

	size = 0;
	while (*str)
	{
		if ((unsigned int)*str <= 127)
			size += 1;
		else
			size += ft_unicode_len(*str);
		if (flag->dot && size > flag->precision)
			break ;
		if ((unsigned int)*str <= 127)
			*ret += ft_putchar_ret(*str);
		else
		{
			*ret += ft_unicode_len(*str);
			ft_putchar_unicode(*str);
		}
		str++;
	}
}

int			format_long_string(t_flags *flag, wchar_t *str)
{
	wchar_t	*cpy;
	int		ret;

	ret = 0;
	if (!(flag->minus))
		ret += print_gaps(flag, str);
	cpy = str;
	if (!str)
		ret += null_case(flag);
	else
		do_string(flag, str, &ret);
	if (flag->minus)
		ret += print_gaps(flag, cpy);
	return (ret);
}
