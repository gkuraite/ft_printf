/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:40:52 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 07:45:11 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	reset_flags(t_tab tab)
{
	tab.minus = 0;
	tab.plus = 0;
	tab.space = 0;
	tab.sharp = 0;
	tab.zero = 0;
	tab.width = 0;
	tab.precision = -1;
	tab.h = 0;
	tab.l = 0;
	tab.j = 0;
	tab.z = 0;
	return (tab);
}
