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

int		main(void)
{

	//printf("MINE>\t[%5u]\n", 1);
	//ft_printf("MINE>\t[%5u]\n", 1);

	printf("ORIG>\t[%10x]\n", 874);
	ft_printf("MINE>\t[%10x]\n", 874);

	//ft_printf("%s is a %d student\n", "Gaby", 42);

	return(0);
}
