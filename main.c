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


	printf("ORIG>\t[%C]\n", L'Å');
	//ft_printf("MINE>\t[%C]\n", L'Å');
//	printf("ORIG>\t[%C]\n", L'Å');
//	printf("ORIG>\t[%C]\n",  L'Å');
//	printf("ORIG>\t[%C]\n", L'Å');
//	printf("ORIG>\t[%C]\n", L'ॵ');
//	printf("ORIG>\t[%C]\n", L'༆');

	//printf("ORIG>\t[%010p]\n", (void*)14785478);

	return(0);
}
