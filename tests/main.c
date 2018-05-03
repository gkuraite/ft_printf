#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int a;
	int b;

	//setlocale(LC_ALL, "");
	a = ft_printf1("me%C\n", 0x11fffe);
	b = ft_printf1("he%C\n", 0x11fffe);
	ft_printf1("O:%d M:%d\n", b, a);
	return (0);
}

//sS
