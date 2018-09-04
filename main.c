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
	//int		a;
	//int		b;

	/*ret1 = ft_printf("M : +d\n");
	ret2 = printf("O : +d\n");
	printf("%s\n%s\n", ret1, ret2);*/

	//wchar_t *str =;
	//ft_printf("O:%d M:%d", b, a);

	printf("printf > Hello World %.3f\n", 157);
	ft_printf("ft_printf > Hello World %.3f\n", 157);
	return(0);
}
