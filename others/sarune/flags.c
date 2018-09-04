/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:26:26 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 14:10:34 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_set_flags(char *str, t_flags *flag)
{
	char *cpy;

	cpy = str;
	cpy++;
	while (*cpy)
	{
		flag->plus = (*cpy == '+' ? 1 : flag->plus);
		flag->minus = (*cpy == '-' ? 1 : flag->minus);
		flag->hashtag = (*cpy == '#' ? 1 : flag->hashtag);
		if (!ft_isdigit(*(cpy - 1)) && !(flag->dot))
			flag->zero = (*cpy == '0' ? 1 : flag->zero);
		flag->space = (*cpy == ' ' ? 1 : flag->space);
		if (*cpy == '.')
		{
			flag->dot = 1;
			flag->precision = ft_atoi(cpy + 1);
		}
		if (check_type(*cpy) || *cpy == '%')
			break ;
		cpy++;
	}
}

static int	get_size(char **str)
{
	char *cpy;

	cpy = *str;
	if (*cpy == 'j')
		return (SIZE_INTMAX);
	else if (*cpy == 'z')
		return (SIZE_T);
	else if (*cpy == 'l')
	{
		if (*(cpy + 1) == 'l')
			return (SIZE_LONGLONG);
		return (SIZE_LONG);
	}
	else if (*cpy == 'h')
	{
		if (*(cpy + 1) == 'h')
			return (SIZE_SIGNED_CHAR);
		return (SIZE_SHORT);
	}
	return (0);
}

void		ft_set_size(char *str, t_flags *flag)
{
	int		size;
	char	*cpy;

	cpy = str;
	cpy++;
	while (*cpy)
	{
		size = get_size(&cpy);
		if (size)
		{
			flag->size = size;
			break ;
		}
		if (check_type(*cpy) || *cpy == '%')
			break ;
		cpy++;
	}
}

void		ft_set_width(char *str, t_flags *flag)
{
	int		width;
	char	*cpy;

	cpy = str;
	cpy++;
	while (*cpy)
	{
		if (check_type(*cpy) || *cpy == '%')
			break ;
		if (ft_isdigit(*cpy) && *cpy != '0')
		{
			width = ft_atoi(cpy);
			flag->width = width;
			break ;
		}
		cpy++;
	}
}

void		ft_set_type(char **str, t_flags *flag)
{
	char		*cpy;

	cpy = *str;
	cpy++;
	while (*cpy)
	{
		if (check_type(*cpy))
		{
			flag_type(&cpy, flag);
			break ;
		}
		if (*cpy == '%')
		{
			flag->type = TYPE_PERCENT;
			break ;
		}
		cpy++;
	}
	*str = cpy;
}
