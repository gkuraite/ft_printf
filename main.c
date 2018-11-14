/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:05:31 by gkuraite          #+#    #+#             */
/*   Updated: 2018/11/12 16:17:29 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <string.h>

int		main(void)
{

	setlocale(LC_ALL, "");

	int	count1;
	int	count2;

	//count1 = printf("ORIG>\t[%]\n");
    //count2 = ft_printf("MINE>\t[%]\n");
	count1 = printf("ORIG>[t%f]\n", 0.123);
    count2 = ft_printf("MINE>[t%f]\n", 0.123);
	//printf("ORIG %d\nMINE %d\n", count1, count2); 

	return(0);
}
