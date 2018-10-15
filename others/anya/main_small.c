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

	printf("\n");
	ft_printf("my: {%2.9p}", 1234); //undefined
	printf("\n");
	printf("or: {%2.9p}", 1234);


	printf("\n");
	ft_printf("my: {%2.9p}", 1234567);  //undefined
	printf("\n");
	printf("or: {%2.9p}", 1234567);

	printf("\n");
	printf("c\n");
	ft_printf("my: {%05.c}", 0); //undefined
	printf("\n");
	printf("or: {%05.c}", 0);

	printf("\n");
	printf("s\n");
	ft_printf("my: {%05.s}", 0);  //undefined
	printf("\n");
	printf("or: {%05.s}", 0);

	printf("\n");
	ft_printf("my: {% o|%+o}", 42, 42); //undefined
	printf("\n");
	printf("pf: {% o|%+o}", 42, 42);

	printf("\n");
	ft_printf("my: {%03c}", 0); //undefined
	printf("\n");
	printf("pf: {%03c}", 0);

	printf("\n");
	ft_printf("my: {%05.S}", L"42 c est cool"); //undefined
	printf("\n");
	printf("pf: {%05.S}", L"42 c est cool");

	printf("\n");
	printf("END UNDEFINED\n");

	printf("\n");
	ft_printf("my: {% 03d}", 0);
	printf("\n");
	printf("pf: {% 03d}", 0);

	printf("\n");
	ft_printf("my: %#.3o", 1);
	printf("\n");
	printf("pf: %#.3o", 1);

	printf("\n");
	ft_printf("MINE>\t[%.u, %.0u]\n", 0, 0);
	printf("\n");
	printf("ORIG>\t[%.u, %.0u]\n", 0, 0);

	printf("\n");
	ft_printf("my: {%.3%}");
	printf("\n");
	printf("pf: {%.3%}");

	printf("\n");
	printf(" - %d\n", ft_printf("{%d}\n", 42));
	printf(" - %d\n", printf("{%d}\n", 42));

	return (0);
}

