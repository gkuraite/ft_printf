/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 08:15:31 by ghaddad           #+#    #+#             */
/*   Updated: 2018/05/17 08:54:13 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	convert_arguments(t_tab tab)
{
	if (tab.string[0] == 's' && !tab.l)
		tab = sconvert(tab);
	else if (tab.string[0] == 'S' || (tab.string[0] == 's' && tab.l))
		tab = wide_sconvert(tab);
	else if (tab.string[0] == 'p')
		tab = pconvert(tab);
	else if (tab.string[0] == 'd' || tab.string[0] == 'D'
									|| tab.string[0] == 'i')
		tab = dconvert(tab);
	else if (tab.string[0] == 'o' || tab.string[0] == 'O')
		tab = oconvert(tab);
	else if (tab.string[0] == 'u' || tab.string[0] == 'U')
		tab = uconvert(tab);
	else if (tab.string[0] == 'x' || tab.string[0] == 'X')
		tab = xconvert(tab);
	else if (tab.string[0] == 'c' || tab.string[0] == 'C')
		tab = cconvert(tab);
	else if (tab.string[0] == 'b' || tab.string[0] == 'B')
		tab = bconvert(tab);
	else
		tab = percent_convert(tab);
	return (tab);
}
