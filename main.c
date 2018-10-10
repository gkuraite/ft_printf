/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:05:31 by gkuraite          #+#    #+#             */
/*   Updated: 2018/09/03 11:26:22 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{

	//setlocale(LC_ALL, "");
	
	printf("ORIG[%d]\n", printf("ORIG>\t[%#0+15p]\n", (void*)14785478));
	printf("MINE[%d]\n", ft_printf("MINE>\t[%#0+15p]\n", (void*)14785478));
	

	return(0);
}
