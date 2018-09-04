/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivinska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:48:16 by sivinska          #+#    #+#             */
/*   Updated: 2018/05/06 19:01:19 by sivinska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_flags(t_flags *flag)
{
	t_flags		*cpy;

	while (flag)
	{
		cpy = flag;
		flag = flag->next;
		free(cpy);
	}
}
