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

	count1 = printf("ORIG>\t[%d]\n", 42);
    count2 = ft_printf("MINE>\t[%d]\n", 42);
	printf("ORIG %d\nMINE %d\n", count1, count2);
//	printf("ORIG>\t[%C]\n", L'Å');
//	printf("ORIG>\t[%C]\n",  L'Å');
	//printf("ORIG>\t[%C]\n", L'Å');
	//printf("ORIG>\t[%C]\n", L'ॵ');
	//printf("ORIG>\t[%C]\n", L'༆');

	//printf("ORIG>\t[%010p]\n", (void*)14785478);

	return(0);
}
