/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recheck_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:49:41 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/03 20:49:43 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		recheck_flags(t_flags *flags)
{
	while (flags)
	{
		if (flags->minus && flags->zero)
			flags->zero = 0;
		if (flags->type == TYPE_INTEGER || flags->type == TYPE_UNSIGNED)
		{
			if (flags->space && flags->plus)
				flags->space = 0;
		}
		if (flags->type == TYPE_UNSIGNED)
		{
			flags->space = 0;
		}
		flags = flags->next;
	}
}
