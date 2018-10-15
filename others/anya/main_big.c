/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:00:58 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/31 16:35:30 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>

#include <stdio.h> /* !!! */

typedef unsigned long long	ull;
typedef long long			ll;
typedef unsigned long		ul;

typedef enum
{
	NONE,
		HH,
		H,
		L,
		LL,
		J,
		T,
		Z
}e_modifier;

void	ft_print_result(int mr, int or, int line)
{
	static int c = 0;
	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
	if (mr == or)
		printf("\t\033[32m✔\033[0m");
	else
		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
				line - 3, line);
	printf("\n---------------\n");
	c++;
}

#define RED "\E[31m"
#define GRE "\E[32m"
#define YEL "\E[33m"
#define WHI "\E[37m"
#define EOC "\E[0m"

int	main(void)
{
	int		or, mr;
	char	**test;
	wchar_t	c;

	test = malloc(sizeof(char*));
	or = 0;
	mr = 0;
//	printf("\033[1;37m======== %%d ========\033[0m\n");

	setlocale(LC_ALL, "");

/*
** d TESTS
*/
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "d tests");
	printf("\n%s\n", "-----------------");
	
	mr = ft_printf("MINE>\t[%d]\n", 650);
	or = printf("ORIG>\t[%d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%d]\n", -650);
	or = printf("ORIG>\t[%d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+d]\n", 650);
	or = printf("ORIG>\t[%+d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+1d]\n", 650);
	or = printf("ORIG>\t[%+1d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%+10d]\n", 123);
	or = printf("ORIG5>\t[%+10d]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10d]\n", -650);
	or = printf("ORIG>\t[%+10d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%10d]\n", 650);
	or = printf("ORIG>\t[%10d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-10d]\n", 650);
	or = printf("ORIG>\t[%-10d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5d]\n", 650);
	or = printf("ORIG>\t[%-5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[% d]\n", 650);
	or = printf("ORIG10>\t[% d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", 650);
	or = printf("ORIG>\t[% 5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% d]\n", -650);
	or = printf("ORIG>\t[% d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", -650);
	or = printf("ORIG>\t[% 5d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%05d]\n", -650);
	or = printf("ORIG>\t[%05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE15>\t[%s %+08d %s]\n", RED, -650, EOC);
//	or = printf("ORIG15>\t[%s %+08d %s]\n", RED, -650, EOC);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-05d]\n", -650);
	or = printf("ORIG>\t[%-05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-05d]\n", -650);
	or = printf("ORIG>\t[%+-05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-09d]\n", -650);
	or = printf("ORIG>\t[%+-09d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+09d]\n", 650);
	or = printf("ORIG>\t[%+09d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE20>\t[%+-1d]\n", -650);
	or = printf("ORIG20>\t[%+-1d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+01d]\n", -650);
	or = printf("ORIG>\t[%+01d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'d]\n", 65000);
	or = printf("ORIG>\t[%'d]\n", 65000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'d]\n", 6500000);
	or = printf("ORIG>\t[%'d]\n", 6500000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+'.10d]\n", 65000);
	or = printf("ORIG>\t[%+'.10d]\n", 65000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE25>\t[%+4.15d]\n", 650);
	or = printf("ORIG25>\t[%+4.15d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+15.5d]\n", 42);
	or = printf("ORIG>\t[%+15.5d]\n", 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+0.5d]\n", 650);
	or = printf("ORIG>\t[%+0.5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0.5d]\n", 650);
	or = printf("ORIG>\t[%-0.5d]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[%0d]\n", 650);
	or = printf("ORIG>\t[%0d]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE30>\t[%.0d]\n", 650);
	or = printf("ORIG30>\t[%.0d]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[% .5d]\n", 650);
	or = printf("ORIG>\t[% .5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.5d]\n", 650);
	or = printf("ORIG>\t[%.5d]\n", 650);

	mr = ft_printf("MINE>\t[%.14d]\n", 650);
	or = printf("ORIG>\t[%.14d]\n", 650);

	mr = ft_printf("MINE>\t[%4d]\n", 650);
	or = printf("ORIG>\t[%4d]\n", 650);
	
	mr = ft_printf("MINE>\t[%14d]\n", 650);
	mr = ft_printf("MINE>\t[%14d]\n", 650);

	mr = ft_printf("MINE>\t[%-10.5d]\n", 4242);
	or = printf("ORIG>\t[%-10.5d]\n", 4242);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[@moulitest: %.d %.0d]\n", 0, 0);
	or = printf("ORIG>\t[@moulitest: %.d %.0d]\n", 0, 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%03.2d]\n", 0);
	or = printf("ORIG>\t[%03.2d]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%03.2d]\n", 1);
	or = printf("ORIG>\t[%03.2d]\n", 1);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%05.2d]\n", -1);
	or = printf("ORIG>\t[%05.2d]\n", -1);
	ft_print_result(mr, or, __LINE__);

	//	mr = ft_printf("MINE>\t[%lld]\n", -9223372036854775808);
	//	or = printf("ORIG>\t[%lld]\n", -9223372036854775808);

	mr = ft_printf("MINE>\t[@moulitest: %.10d]\n", -42);
	or = printf("ORIG>\t[@moulitest: %.10d]\n", -42);
	ft_print_result(mr, or, __LINE__);


*/

/*
**  u TESTS
*/ 
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "u tests");
	printf("\n%s\n", "-----------------");

	mr = ft_printf("MINE>\t[%u]\n", 123);
	or = printf("ORIG>\t[%u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-u]\n", 123);
	or = printf("ORIG>\t[%-u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+u]\n", 123);
	or = printf("ORIG>\t[%+u]\n", 123);
	ft_print_result(mr, or, __LINE__);mr = ft_printf("MINE>\t[%0u]\n", 123);
	
	mr = ft_printf("MINE>\t[%+0u]\n", 123);
	or = printf("ORIG>\t[%0u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%5u]\n", -123);
	or = printf("ORIG5>\t[%5u]\n", -123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0.5u]\n", 123);
	or = printf("ORIG>\t[%0.5u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%5.10u]\n", 123456789);
	or = printf("ORIG>\t[%5.10u]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0.5u]\n", -123456789);
	or = printf("ORIG>\t[%-0.5u]\n", -123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+05.10u]\n", 123);
	or = printf("ORIG>\t[%+05.10u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%h5u]\n", 123456789123456);
	or = printf("ORIG10>\t[%h5u]\n", 123456789123456);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.5u]\n", 123);
	or = printf("ORIG>\t[%.5u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0u]\n", 123);
	or = printf("ORIG>\t[%.0u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%u%u%u%u%u]\n", 1, 100, 999, 42, 999988888);
	or = printf("ORIG>\t[%u%u%u%u%u]\n", 1, 100, 999, 42, 999988888);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[a%ub%uc%ud]\n", 0, 55555, 100000);
	or = printf("ORIG>\t[a%ub%uc%ud]\n", 0, 55555, 100000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%u]\n", UINT_MAX);
	or = printf("ORIG>\t[%u]\n", UINT_MAX);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%U]\n", 42);
	or = printf("ORIG>\t[%U]\n", 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%U]\n", ULONG_MAX / 2);
	or = printf("ORIG>\t[%U]\n", ULONG_MAX / 2);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%U]\n", ULONG_MAX);
	or = printf("ORIG>\t[%U]\n", ULONG_MAX);
	ft_print_result(mr, or, __LINE__);
*/

/*
**  o TESTS
*/ 
/*

	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "o tests");
	printf("\n%s\n", "-----------------");
	

	mr = ft_printf("MINE>\t[%o]\n", 1000);
	or = printf("ORIG>\t[%o]\n", 1000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%o]\n", -123456789);
	or = printf("ORIG>\t[%o]\n", -123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#o]\n", 0);
	or = printf("ORIG>\t[%#o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#o]\n", 3000);
	or = printf("ORIG>\t[%#o]\n", 3000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%#+o]\n", -896);
	or = printf("ORIG5>\t[%#+o]\n", -896);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hho]\n", (unsigned char)-12);
	or = printf("ORIG>\t[%hho]\n", (unsigned char)-12);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%ho]\n", (unsigned short)1475);
	or = printf("ORIG>\t[%ho]\n", (unsigned short)1475);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lo]\n", (unsigned long)258);
	or = printf("ORIG>\t[%lo]\n", (unsigned long)258);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%llo]\n", (unsigned long long)-127);
	or = printf("ORIG>\t[%llo]\n", (unsigned long long)-127);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%.2o]\n", 0);
	or = printf("ORIG10>\t[%.2o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.2o]\n", 120);
	or = printf("ORIG>\t[%.2o]\n", 120);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0o]\n", 12012);
	or = printf("ORIG>\t[%.0o]\n", 12012);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%1o]\n", 0);
	or = printf("ORIG>\t[%1o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%01o]\n", 0);
	or = printf("ORIG>\t[%01o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE15>\t[%03o]\n", 0);
	or = printf("ORIG15>\t[%03o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%6o]\n", 01423);
	or = printf("ORIG>\t[%6o]\n", 01423);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#-2o]\n", 874);
	or = printf("ORIG>\t[%#-2o]\n", 874);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[%-8.30o]\n", 120);
	or = printf("ORIG>\t[%-8.30o]\n", 120);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5.10o]\n", 2500);
	or = printf("ORIG>\t[%-5.10o]\n", 2500);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-#6o]\n", 2500);
	or = printf("ORIG>\t[%-#6o]\n", 2500);
	ft_print_result(mr, or, __LINE__);
*/

/*
** x TESTS
*/
/*

	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "x tests");
	printf("\n%s\n", "-----------------");
	
	
	mr = ft_printf("MINE>\t[%x]\n", 0);
	or = printf("ORIG>\t[%x]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%x]\n", 0xa0ffff);
	or = printf("ORIG>\t[%x]\n", 0xa0ffff);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%x]\n", -12345678);
	or = printf("ORIG>\t[%x]\n", -12345678);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#X]\n", 0);
	or = printf("ORIG>\t[%#X]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%#x]\n", 0x78aa);
	or = printf("ORIG5>\t[%#x]\n", 0x78aa);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#x]\n", 0xff7744);
	or = printf("ORIG>\t[%#x]\n", 0xff7744);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.x]\n", 12);
	or = printf("ORIG>\t[%.x]\n", 12);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0X]\n", 0xaabbcc);
	or = printf("ORIG>\t[%.0X]\n", 0xaabbcc);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.2X]\n", 0x11aabbcc);
	or = printf("ORIG>\t[%.2X]\n", 0x11aabbcc);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[% x]\n", 0x1234abcd);
	or = printf("ORIG10>\t[% x]\n", 0x1234abcd);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.10x]\n", 0x1234abcd);
	or = printf("ORIG>\t[%.10x]\n", 0x1234abcd);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% x]\n", -650);
	or = printf("ORIG>\t[% x]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% .5x]\n", 0x78);
	or = printf("ORIG>\t[% .5x]\n", 0x78);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%05x]\n", 0xa43);
	or = printf("ORIG>\t[%05x]\n", 0xa43);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE15>\t[%8X]\n", 0xa3);
	or = printf("ORIG15>\t[%8X]\n", 0xa3);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5x]\n", 0xdd);
	or = printf("ORIG>\t[%-5x]\n", 0xdd);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%011X]\n", 0xdd66);
	or = printf("ORIG>\t[%011X]\n", 0xdd66);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%01hhx]\n", 0xaabb);
	or = printf("ORIG>\t[%01hhx]\n", 0xaabb);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#7.5X%0006.2x and %lX]\n", 0xab, 0x876, 0xff11ff11ff1);
	or = printf("ORIG>\t[%#7.5X%0006.2x and %lX]\n", 0xab, 0x876, 0xff11ff11ff1);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE20>\t[%0##0.4X %#4.2x oh boy]\n", 0x037a, 0x9e);
	or = printf("ORIG20>\t[%0##0.4X %#4.2x oh boy]\n", 0x037a, 0x9e);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[yikes %#.4X can you handle %#012x]\n", 0xaef, 0xe);
	or = printf("ORIG>\t[yikes %#.4X can you handle %#012x]\n", 0xaef, 0xe);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hhx]\n", (unsigned char)-10);
	or = printf("ORIG>\t[%hhx]\n", (unsigned char)-10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hX]\n", (unsigned short)40);
	or = printf("ORIG>\t[%hX]\n", (unsigned short)40);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lx]\n", (unsigned long)-178965423);
	or = printf("ORIG>\t[%lx]\n", (unsigned long)-178965423);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE25>\t[%zx]\n", 65423000000);
	or = printf("ORIG25>\t[%zx]\n", 65423000000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+15.5x]\n", 42);
	or = printf("ORIG>\t[%+15.5x]\n", 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0.5x]\n", 650);
	or = printf("ORIG>\t[%-0.5x]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0x]\n", 650);
	or = printf("ORIG>\t[%0x]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE30>\t[%.0x]\n", 650);
	or = printf("ORIG30>\t[%.0x]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#08x]\n", 42);
	or = printf("ORIG>\t[%#08x]\n", 42);
	ft_print_result(mr, or, __LINE__);

*/

/*
** p TESTS
*/
/*

	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "p tests");
	printf("\n%s\n", "-----------------");
	

	mr = ft_printf("MINE>\t[%p]\n", NULL);
	or = printf("ORIG>\t[%p]\n", NULL);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%p]\n", (void*)-1);
	or = printf("ORIG>\t[%p]\n", (void*)-1);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%p]\n", (void*)30);
	or = printf("ORIG>\t[%p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%p]\n", (void*)14785478);
	or = printf("ORIG>\t[%p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[% p]\n", (void*)30);
	or = printf("ORIG5>\t[% p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#p]\n", (void*)30);
	or = printf("ORIG>\t[%#p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-10p]\n", (void*)30);
	or = printf("ORIG>\t[%-10p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+p]\n", (void*)30);
	or = printf("ORIG>\t[%+p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0p]\n", (void*)30);
	or = printf("ORIG>\t[%.0p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%3p]\n", (void*)30);
	or = printf("ORIG10>\t[%3p]\n", (void*)30);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0p]\n", (void*)14785478);
	or = printf("ORIG>\t[%0p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15p]\n", (void*)14785478);
	or = printf("ORIG>\t[%15p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-15p]\n", (void*)14785478);
	or = printf("ORIG>\t[%-15p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-.15p]\n", (void*)14785478);
	or = printf("ORIG>\t[%-.15p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15.0p]\n", (void*)14785478);
	or = printf("ORIG>\t[%15.0p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%p]\n", (void*)14785478);
	or = printf("ORIG>\t[%p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%010p]\n", (void*)14785478);
	or = printf("ORIG>\t[%010p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#0+15p]\n", (void*)14785478);
	or = printf("ORIG>\t[%#0+15p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0p]\n", (void*)14785478);
	or = printf("ORIG>\t[%.0p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.10p]\n", (void*)14785478);
	or = printf("ORIG>\t[%.10p]\n", (void*)14785478);
	ft_print_result(mr, or, __LINE__);
*/

/*
** C TESTS
*/

/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "C tests");
	printf("\n%s\n", "-----------------");
	
	mr = ft_printf("MINE>\t[%C]\n", L'Å'); 
	or = printf("ORIG>\t[%C]\n",  L'Å');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'Å');
	or = printf("ORIG>\t[%C]\n", L'Å');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'ॵ');
	or = printf("ORIG>\t[%C]\n", L'ॵ');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'༆');
	or = printf("ORIG>\t[%C]\n", L'༆');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[% C]\n", L'ᛤ');
	or = printf("ORIG5>\t[% C]\n", L'ᛤ');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#C]\n", L'ṧ');
	or = printf("ORIG>\t[%#C]\n", L'ṧ');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-C]\n", L'♥');
	or = printf("ORIG>\t[%-C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+C]\n", L'♥');
	or = printf("ORIG>\t[%+C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0C]\n", L'♥');
	or = printf("ORIG>\t[%0C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%3C]\n", L'⾈');
	or = printf("ORIG10>\t[%3C]\n", L'⾈');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0C]\n", L'ゆ');
	or = printf("ORIG>\t[%0C]\n", L'ゆ');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15C]\n", L'㘦');
	or = printf("ORIG>\t[%15C]\n", L'㘦');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-15C]\n", L'䢐');
	or = printf("ORIG>\t[%-15C]\n", L'䢐');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-.15C]\n", L'三');
	or = printf("ORIG>\t[%-.15C]\n", L'三');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15.0C]\n", L'仚');
	or = printf("ORIG>\t[%15.0C]\n", L'仚');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%C]\n", L'♥');
	or = printf("ORIG>\t[%C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%010C]\n", L'♥');
	or = printf("ORIG>\t[%010C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#0+15C]\n", L'♥');
	or = printf("ORIG>\t[%#0+15C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0C]\n", L'♥');
	or = printf("ORIG>\t[%.0C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.10C]\n", L'♥');
	or = printf("ORIG>\t[%.10C]\n", L'♥');
	ft_print_result(mr, or, __LINE__);
*/

/*
** S TESTS
*/

/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "S tests");
	printf("\n%s\n", "-----------------");
	

	mr = ft_printf("MINE>\t[%S]\n", L"こんにちは私は月面です"); 
	or = printf("ORIG>\t[%S]\n",  L"こんにちは私は月面です");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%S]\n", L"Для меня нет полонийного чая, спасибо");
	or = printf("ORIG>\t[%S]\n", L"Для меня нет полонийного чая, спасибо");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%S]\n", L"هل الجو حار هنا أم هو نظام الأبوية؟");
	or = printf("ORIG>\t[%S]\n", L"هل الجو حار هنا أم هو نظام الأبوية؟");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[% S]\n", L"You're my favorite ♥");
	or = printf("ORIG5>\t[% S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%#S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%-S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%+S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%0S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%3S]\n", L"You're my favorite ♥");
	or = printf("ORIG10>\t[%3S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%0S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%15S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-15S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%-15S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-.15S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%-.15S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15.0S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%15.0S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%010S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%010S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#0+15S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%#0+15S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0S]\n", L"You're my favorite ♥");
	or = printf("ORIG>\t[%.0S]\n", L"You're my favorite ♥");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.10S]\n", L"こんにちは私は月面です");
	or = printf("ORIG>\t[%.10S]\n", L"こんにちは私は月面です");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#-6o]\n", 2500);
	or = printf("ORIG>\t[%#-6o]\n", 2500);
	ft_print_result(mr, or, __LINE__);
*/
/*
** c and s TESTS
*/
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "S tests");
	printf("\n%s\n", "-----------------");

	mr = ft_printf("MINE>\t[%2c]\n", 0);
	or = printf("ORIG>\t[%2c]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5.2s is a string]\n", "this");
	or = printf("ORIG>\t[%-5.2s is a string]\n", "this");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.2s is a string]\n", "");
	or = printf("ORIG>\t[%.2s is a string]\n", "");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-.2s is a string]\n", "");
	or = printf("ORIG>\t[%-.2s is a string]\n", "");
	ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c]\n", ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	or = printf("ORIG>\t[%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c]\n", ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	ft_print_result(mr, or, __LINE__);
*/

/*
** % TESTS
*/

/*
	mr = ft_printf("%");
	or = printf("%");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%%]\n");
	or = printf("ORIG>\t[%%]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[aa%%bb]\n");
	or = printf("ORIG>\t[aa%%bb]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%%%%%%%%%%]\n");
	or = printf("ORIG>\t[%%%%%%%%%%]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[.%%.%%.%%.%%.%%.%%.%%.%%.]\n");
	or = printf("ORIG>\t[.%%.%%.%%.%%.%%.%%.%%.%%.]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%]\n");
	or = printf("ORIG>\t[%]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% Zoooo]\n");
	or = printf("ORIG>\t[% Zoooo]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%]\n");
	or = printf("ORIG>\t[%]\n");
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[{% %}]\n");
	or = printf("ORIG>\t[{% %}]\n");
	ft_print_result(mr, or, __LINE__);
*/

	mr = ft_printf("MINE>\t[%u]\n", UINT_MAX);
	or = printf("ORIG>\t[%u]\n", UINT_MAX);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%U]\n", 42);
	or = printf("ORIG>\t[%U]\n", 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%U]\n", ULONG_MAX / 2);
	or = printf("ORIG>\t[%U]\n", ULONG_MAX / 2);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%U]\n", ULONG_MAX);
	or = printf("ORIG>\t[%U]\n", ULONG_MAX);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("%");
	or = printf("%");
	ft_print_result(mr, or, __LINE__);

	ft_putchar(42);
	return(0);
}
