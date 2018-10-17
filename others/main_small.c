#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main()
{
	int mr;
	int or;
	char c;

	setlocale(LC_ALL, "");


	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "C tests");
	printf("\n%s\n", "-----------------");
	
	mr = ft_printf("MINE>\t[%C]\n", L'Å'); 
	or = printf("ORIG>\t[%C]\n",  L'Å');
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'Å');
	or = printf("ORIG>\t[%C]\n", L'Å');
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'ॵ');
	or = printf("ORIG>\t[%C]\n", L'ॵ');
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'༆');
	or = printf("ORIG>\t[%C]\n", L'༆');
//	ft_print_result(mr, or, __LINE__);

	return (0);
}

