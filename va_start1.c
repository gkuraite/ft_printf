/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_start1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:22:46 by gkuraite          #+#    #+#             */
/*   Updated: 2018/08/25 12:54:50 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include <stdarg.h>

int	yas_bitch(int numbers, ...)
{
	va_list		list;
	int		total;

	total = 0;
	va_start(list, numbers);
	int		count = 0;
	while (count < numbers)
	{
		total = total + va_arg(list, int);
		count++;
	}
	va_end(list);
	return (total);
}

int		main(void)
{
	int		v1, v2, v3, v4;
	int		result;

	v1 = 1;
	v2 = 2;
	v3 = 3;
	v4 = 4;

	result = yas_bitch(4, v1, v2, v3, v4);
	printf("%d\n", result);
	return (0);
}
