/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:43:07 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/04 14:47:05 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags			*init_flag(void)
{
	t_flags		*ret;

	ret = (t_flags *)malloc(sizeof(t_flags));
	if (!ret)
		return (NULL);
	ret->hashtag = 0;
	ret->type = 0;
	ret->minus = 0;
	ret->space = 0;
	ret->plus = 0;
	ret->zero = 0;
	ret->width = 0;
	ret->precision = 0;
	ret->dot = 0;
	ret->size = 0;
	ret->next = NULL;
	return (ret);
}

static void		flag_push_back(t_flags **list, t_flags *to_add)
{
	t_flags		*cpy;

	cpy = *list;
	if (!cpy)
		*list = to_add;
	else
	{
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = to_add;
	}
}

t_flags			*parse_flag(char **str)
{
	t_flags		*ret;
	char		*cpy;

	if (!(ret = init_flag()))
		return (NULL);
	cpy = *str;
	ft_set_flags(cpy, ret);
	ft_set_size(cpy, ret);
	ft_set_width(cpy, ret);
	ft_set_type(&cpy, ret);
	*str = cpy;
	return (ret);
}

t_flags			*fill_flags(char *str)
{
	t_flags		*ret;
	t_flags		*new;

	ret = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			new = parse_flag(&str);
			flag_push_back(&ret, new);
		}
		str++;
	}
	return (ret);
}
