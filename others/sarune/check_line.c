/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:05:46 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 11:51:50 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool			check_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C')
		return (TRUE);
	return (FALSE);
}

static t_bool	check_flag(char c, char *str)
{
	if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#' || c == '.')
	{
		str++;
		while (*str)
		{
			if (check_type(*str))
				break ;
			if (c == '+' || c == ' ')
			{
				if (*str == '+' || *str == ' ')
					return (FALSE);
			}
			if (c == *str)
				return (FALSE);
			str++;
		}
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	check_size(char **str)
{
	char	*cpy;

	cpy = *str;
	if (*cpy == 'j' || *cpy == 'z')
		return (TRUE);
	else if (*cpy == 'l')
	{
		if (*(cpy + 1) == 'l')
			*str = ++cpy;
		return (TRUE);
	}
	else if (*cpy == 'h')
	{
		if (*(cpy + 1) == 'h')
			*str = ++cpy;
		return (TRUE);
	}
	return (FALSE);
}

static int		check_all(char *str)
{
	int		size_count;

	size_count = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			if (check_size(&str))
				size_count++;
			else if (check_type(*str))
				break ;
			else if (!check_flag(*str, str))
				return (FALSE);
			else if (check_flag(*str, str))
				;
			else
				return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

t_bool			check_line(const char *src)
{
	int		size_count;
	char	*str;

	str = (char *)src;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			size_count = 0;
			check_all(str);
		}
		if (!(size_count <= 1 && check_type(*str)))
			return (FALSE);
	}
	str++;
	return (TRUE);
}
