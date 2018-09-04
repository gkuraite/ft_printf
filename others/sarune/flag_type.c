/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:06:10 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/07 14:13:19 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_type(char **str, t_flags *flag)
{
	char	*cpy;

	cpy = *str;
	flag->type = (*cpy == 'd' ? TYPE_INTEGER : flag->type);
	flag->type = (*cpy == 'i' ? TYPE_INTEGER : flag->type);
	flag->type = (*cpy == 's' ? TYPE_STRING : flag->type);
	flag->type = (*cpy == 'p' ? TYPE_POINTER : flag->type);
	flag->type = (*cpy == 'D' ? TYPE_SIGNED_INT : flag->type);
	flag->type = (*cpy == 'o' ? TYPE_OCT : flag->type);
	flag->type = (*cpy == 'O' ? TYPE_UNSIGNED_OCT : flag->type);
	flag->type = (*cpy == 'u' ? TYPE_UNSIGNED : flag->type);
	flag->type = (*cpy == 'x' ? TYPE_HEX : flag->type);
	flag->type = (*cpy == 'X' ? TYPE_HEX_BIG : flag->type);
	flag->type = (*cpy == 'c' ? TYPE_CHAR : flag->type);
	flag->type = (*cpy == 'C' ? TYPE_LONG_CHAR : flag->type);
	flag->type = (*cpy == 'S' ? TYPE_LONG_STRING : flag->type);
	flag->type = (*cpy == 'U' ? TYPE_UNSIGNED_INT : flag->type);
	flag->type = (*cpy == 'D' ? TYPE_BIG_D : flag->type);
}
