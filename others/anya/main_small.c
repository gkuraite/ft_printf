#include "./includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main()
{
	int mr;
	int or;
	char c;

	setlocale(LC_ALL, "");
/*	ft_printf("mine %s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	ft_putchar('\n');

	printf("printf %s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	ft_putchar('\n');
*/	
	//printf("prin %zo, %zo", 0, ULLONG_MAX);
	//ft_printf("mine %zo, %zo", 0, ULLONG_MAX);

//	printf("\n");
//	ft_printf("my: {%03c}", 0);
//	printf("\n");
//	printf("pf: {%03c}", 0);

//	printf("\n");
//	ft_printf("my: {% 03d}", 0);
//	printf("\n");
//	printf("pf: {% 03d}", 0);

//	printf("\n");
//	ft_printf("my: {%#O}", 1);
//	printf("\n");
//	printf("pf: {%#O}", 1);



/*
	printf("\n");
	printf("o\n");
	ft_printf("%4.15o", 424242);
	printf("\n");
	printf("%4.15o", 424242);




	printf("\n");
	printf("o\n");
	ft_printf("%jd", -9223372036854775808);
	printf("\n");
	printf("%jd", -9223372036854775808);

	printf("\n");
	printf("o\n");
	ft_printf("%zi", LLONG_MIN);
	printf("\n");
	printf("%zi", LLONG_MIN);


	printf("\n");
	printf("o\n");
	ft_printf("%lld", -9223372036854775808);
	printf("\n");
	printf("%lld", -9223372036854775808);

	printf("\n");
	printf("o\n");
	ft_printf("%lld", -9223372036854775808);
	printf("\n");
	printf("%lld", -9223372036854775808);

	printf("\n");
	printf("o\n");
	ft_printf("%jd", -9223372036854775808);
	printf("\n");
	printf("%jd", -9223372036854775808);

	printf("\n");
	printf("o\n");
	ft_printf("%lld", -9223372036854775807);
	printf("\n");
	printf("%lld", -9223372036854775807);


*/

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

