/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:40:57 by gkuraite          #+#    #+#             */
/*   Updated: 2018/06/18 15:22:33 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	foo(char *fmt, ...)
{
	va_list ap;
	int d;
    char c, *s;

    va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == 's')
		{
			s = va_arg(ap, char *);
			printf("string %s\n", s);
		}
		if (*fmt == 'd')
		{
			d = va_arg(ap, int);
			 printf("int %d\n", d);
        }
		if (*fmt == 'c')
        {
			c = va_arg(ap, int);
			printf("char %c\n", c);
		}
		fmt++;
	}
    va_end(ap);
 }

int		main(void)
{
	foo("sdcc", "as", 10, 'G');
	return (0);
}
