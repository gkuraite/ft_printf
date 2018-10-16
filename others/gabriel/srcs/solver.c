/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:23:55 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 14:19:20 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	solver(t_tab tab)
{
	while (tab.string)
	{
		tab = read_string(tab);
		if (tab.string)
			tab = read_flags(tab);
		if (tab.string)
			tab = convert_arguments(tab);
		if (tab.string)
			tab = reset_flags(tab);
	}
	return (tab);
}
