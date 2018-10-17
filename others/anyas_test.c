#include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>

int     main(void)
{

	setlocale(LC_ALL, "");
/*
** d TESTS
*/

	/*printf("%s\n", "-----------------");
	printf("\n%s\n", "d tests");
	printf("\n%s\n", "-----------------");
	
	printf("ORIG1>\t[%d]\n", 650);
	printf("ORIG2>\t[%d]\n", -650);
	printf("ORIG3>\t[%+d]\n", 650);
	printf("ORIG4>\t[%+1d]\n", 650);
	printf("ORIG5>\t[%+10d]\n", 123);
	printf("ORIG6>\t[%+10d]\n", -650);
	printf("ORIG7>\t[%10d]\n", 650);
	printf("ORIG8>\t[%-10d]\n", 650);
	printf("ORIG9>\t[%-5d]\n", 650);
	printf("ORIG10>\t[% d]\n", 650);
	printf("ORIG>11\t[% 5d]\n", 650);
	printf("ORIG>12\t[% d]\n", -650);
	printf("ORIG>13\t[% 5d]\n", -650);
	printf("ORIG>14\t[%05d]\n", -650);
1
	printf("ORIG>15\t[%-05d]\n", -650);
	printf("ORIG>16\t[%+-05d]\n", -650);
	printf("ORIG>17\t[%+-09d]\n", -650);
	printf("ORIG>18\t[%+09d]\n", 650);
	printf("ORIG19>\t[%+-1d]\n", -650);
	printf("ORIG>20\t[%+01d]\n", -650);
	printf("ORIG>21\t[%'d]\n", 65000);
	printf("ORIG>22\t[%'d]\n", 6500000);
	printf("ORIG>23\t[%+'.10d]\n", 65000);
	printf("ORIG24>\t[%+4.15d]\n", 650);
	printf("ORIG>25\t[%+15.5d]\n", 42);
	printf("ORIG>26\t[%+0.5d]\n", 650);
	printf("ORIG>27\t[%-0.5d]\n", 650);
	
	printf("ORIG>28\t[%0d]\n", 650);
	
	printf("ORIG29>\t[%.0d]\n", 650);
	
	printf("ORIG>30\t[% .5d]\n", 650);
	printf("ORIG>31\t[%.5d]\n", 650);
	printf("ORIG>32\t[%.14d]\n", 650);
	printf("ORIG>33\t[%4d]\n", 650);
	
	printf("ORIG>34\t[%-10.5d]\n", 4242);
	printf("ORIG>35\t[%03.2d]\n", 0);
	printf("ORIG>36\t[%03.2d]\n", 1);
	printf("ORIG>37\t[%01d]\n", -1);*/

	//printf("ORIG>\t[%lld]\n", 9223372036854775808);
	//printf("ORIG>\t[@moulitest: %.10d]\n", -42);

/*
**  u TESTS
*/ 
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "u tests");
	printf("\n%s\n", "-----------------");
	printf("ORIG>\t[%u]\n", 123);
	printf("ORIG>\t[%-u]\n", 123);
	printf("ORIG>\t[%+u]\n", 123);
	
	printf("ORIG>\t[%0u]\n", 123);
	printf("ORIG5>\t[%5u]\n", -123);
	printf("ORIG>\t[%0.5u]\n", 123);
	printf("ORIG>\t[%5.10u]\n", 123456789);
	printf("ORIG>\t[%-0.5u]\n", -123456789);
	printf("ORIG>\t[%+05.10u]\n", 123);
	printf("ORIG10>\t[%h5u]\n", 123456789123456);
	printf("ORIG>\t[%.5u]\n", 123);
	printf("ORIG>\t[%.0u]\n", 123);
	printf("ORIG>\t[%u%u%u%u%u]\n", 1, 100, 999, 42, 999988888);
	printf("ORIG>\t[a%ub%uc%ud]\n", 0, 55555, 100000);
	printf("ORIG>\t[%u]\n", UINT_MAX);
	printf("ORIG>\t[%U]\n", 42);
	printf("ORIG>\t[%U]\n", ULONG_MAX / 2);
	printf("ORIG>\t[%U]\n", ULONG_MAX);
*/

/*
**  o TESTS
*/ 
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "o tests");
	printf("\n%s\n", "-----------------");
	
	printf("ORIG>\t[%o]\n", 1000);
	printf("ORIG>\t[%o]\n", -123456789);
	printf("ORIG>\t[%#o]\n", 0);
	printf("ORIG>\t[%#o]\n", 3000);
	printf("ORIG5>\t[%#+o]\n", -896);
	printf("ORIG>\t[%hho]\n", (unsigned char)-12);
	printf("ORIG>\t[%ho]\n", (unsigned short)1475);
	printf("ORIG>\t[%lo]\n", (unsigned long)258);
	printf("ORIG>\t[%llo]\n", (unsigned long long)-127);
	printf("ORIG10>\t[%.2o]\n", 0);
	printf("ORIG>\t[%.2o]\n", 120);
	printf("ORIG>\t[%.0o]\n", 12012);
	printf("ORIG>\t[%1o]\n", 0);
	printf("ORIG>\t[%01o]\n", 0);
	printf("ORIG15>\t[%03o]\n", 0);
	printf("ORIG>\t[%6o]\n", 01423);
	printf("ORIG>\t[%#-2o]\n", 874);
	
	printf("ORIG>\t[%-8.30o]\n", 120);
	printf("ORIG>\t[%-5.10o]\n", 2500);
	printf("ORIG>\t[%-#6o]\n", 2500);
*/

/*
** x TESTS
*/
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "x tests");
	printf("\n%s\n", "-----------------");
	
	
	printf("ORIG>\t[%x]\n", 0);
	printf("ORIG>\t[%x]\n", c);
	printf("ORIG>\t[%x]\n", -12345678);
	printf("ORIG>\t[%#X]\n", 0);
	printf("ORIG5>\t[%#x]\n", 0x78aa);
	printf("ORIG>\t[%#x]\n", 0xff7744);
	printf("ORIG>\t[%.x]\n", 12);
	printf("ORIG>\t[%.0X]\n", 0xaabbcc);
	printf("ORIG>\t[%.2X]\n", 0x11aabbcc);
	printf("ORIG10>\t[% x]\n", 0x1234abcd);
	printf("ORIG>\t[%.10x]\n", 0x1234abcd);
	printf("ORIG>\t[% x]\n", -650);
	printf("ORIG>\t[% .5x]\n", 0x78);
	printf("ORIG>\t[%05x]\n", 0xa43);
	printf("ORIG15>\t[%8X]\n", 0xa3);
	printf("ORIG>\t[%-5x]\n", 0xdd);
	printf("ORIG>\t[%011X]\n", 0xdd66);
	printf("ORIG>\t[%01hhx]\n", 0xaabb);
	printf("ORIG>\t[%#7.5X%0006.2x and %lX]\n", 0xab, 0x876, 0xff11ff11ff1);
	printf("ORIG20>\t[%0##0.4X %#4.2x oh boy]\n", 0x037a, 0x9e);
	printf("ORIG>\t[yikes %#.4X can you handle %#012x]\n", 0xaef, 0xe);
	printf("ORIG>\t[%hhx]\n", (unsigned char)-10);
	printf("ORIG>\t[%hX]\n", (unsigned short)40);
	printf("ORIG>\t[%lx]\n", (unsigned long)-178965423);
	printf("ORIG25>\t[%zx]\n", 65423000000);
	printf("ORIG>\t[%+15.5x]\n", 42);
	printf("ORIG>\t[%-0.5x]\n", 650);
	printf("ORIG>\t[%0x]\n", 650);
	
	printf("ORIG30>\t[%.0x]\n", 650);
	printf("ORIG>\t[%#08x]\n", 42);
*/

/*
** p TESTS
*/
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "p tests");
	printf("\n%s\n", "-----------------");
	
	printf("ORIG>\t[%p]\n", NULL);
	printf("ORIG>\t[%p]\n", (void*)-1);
	printf("ORIG>\t[%p]\n", (void*)30);
	printf("ORIG>\t[%p]\n", (void*)14785478);
	printf("ORIG5>\t[% p]\n", (void*)30);
	printf("ORIG>\t[%#p]\n", (void*)30);
	printf("ORIG>\t[%-10p]\n", (void*)30);
	printf("ORIG>\t[%+p]\n", (void*)30);
	printf("ORIG>\t[%.0p]\n", (void*)30);
	printf("ORIG10>\t[%3p]\n", (void*)30);
	printf("ORIG>\t[%0p]\n", (void*)14785478);
	printf("ORIG>\t[%15p]\n", (void*)14785478);
	printf("ORIG>\t[%-15p]\n", (void*)14785478);
	printf("ORIG>\t[%-.15p]\n", (void*)14785478);
	printf("ORIG>\t[%15.0p]\n", (void*)14785478);
	printf("ORIG>\t[%p]\n", (void*)14785478);
	printf("ORIG>\t[%010p]\n", (void*)14785478);
	printf("ORIG>\t[%#0+15p]\n", (void*)14785478);
	printf("ORIG>\t[%.0p]\n", (void*)14785478);
	printf("ORIG>\t[%.10p]\n", (void*)14785478);
*/

/*
** C TESTS
*/


	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "C tests");
	printf("\n%s\n", "-----------------");
	
	printf("ORIG>\t[%C]\n",  L'Å');
	printf("ORIG>\t[%C]\n", L'Å');
	printf("ORIG>\t[%C]\n", L'ॵ');
	printf("ORIG>\t[%C]\n", L'༆');
	printf("ORIG5>\t[% C]\n", L'ᛤ');
	printf("ORIG>\t[%#C]\n", L'ṧ');
	printf("ORIG>\t[%-C]\n", L'♥');
	printf("ORIG>\t[%+C]\n", L'♥');
	printf("ORIG>\t[%0C]\n", L'♥');
	printf("ORIG10>\t[%3C]\n", L'⾈');
	printf("ORIG>\t[%0C]\n", L'ゆ');
	printf("ORIG>\t[%15C]\n", L'㘦');
	printf("ORIG>\t[%-15C]\n", L'䢐');
	printf("ORIG>\t[%-.15C]\n", L'三');
	printf("ORIG>\t[%15.0C]\n", L'仚');
	printf("ORIG>\t[%C]\n", L'♥');
	printf("ORIG>\t[%010C]\n", L'♥');
	printf("ORIG>\t[%#0+15C]\n", L'♥');
	printf("ORIG>\t[%.0C]\n", L'♥');
	printf("ORIG>\t[%.10C]\n", L'♥');


/*
** S TESTS
*/

/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "S tests");
	printf("\n%s\n", "-----------------");
	
	printf("ORIG>\t[%S]\n",  L"こんにちは私は月面です");
	printf("ORIG>\t[%S]\n", L"Для меня нет полонийного чая, спасибо");
	printf("ORIG>\t[%S]\n", L"هل الجو حار هنا أم هو نظام الأبوية؟");
	printf("ORIG>\t[%S]\n", L"You're my favorite ♥");
	printf("ORIG5>\t[% S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%#S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%-S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%+S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%0S]\n", L"You're my favorite ♥");
	printf("ORIG10>\t[%3S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%0S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%15S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%-15S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%-.15S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%15.0S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%010S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%#0+15S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%.0S]\n", L"You're my favorite ♥");
	printf("ORIG>\t[%.10S]\n", L"こんにちは私は月面です");
	printf("ORIG>\t[%#-6o]\n", 2500);
*/
/*
** c and s TESTS
*/
/*
	printf("\n%s\n", "-----------------");
	printf("\n%s\n", "S tests");
	printf("\n%s\n", "-----------------");
	printf("ORIG>\t[%2c]\n", 0);
	printf("ORIG>\t[%-5.2s is a string]\n", "this");
	printf("ORIG>\t[%.2s is a string]\n", "");
	printf("ORIG>\t[%-.2s is a string]\n", "");

%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c]\n", ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	printf("ORIG>\t[%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c]\n", ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
*/

/*
** % TESTS
*/

/*
	printf("%");										[error]
	printf("ORIG>\t[%%]\n");							[%]	
	printf("ORIG>\t[aa%%bb]\n");						[aa%bb]
	printf("ORIG>\t[%%%%%%%%%%]\n");					[%%%%%]
	printf("ORIG>\t[.%%.%%.%%.%%.%%.%%.%%.%%.]\n");		[.%.%.%.%.%.%.%.%.]
	printf("ORIG>\t[%]\n");								invalid conversion specifier ']'
	printf("ORIG>\t[% Zoooo]\n");						invalid conversion specifier 'Z'
	printf("ORIG>\t[{% %}]\n");							[{%}]



or = printf("ORIG>\t[%u]\n", UINT_MAX)
or = printf("ORIG>\t[%U]\n", 42)
or = printf("ORIG>\t[%U]\n", ULONG_MAX / 2)
or = printf("ORIG>\t[%U]\n", ULONG_MAX)
or = printf("%")

ft_putchar(42);*/
return(0);
}