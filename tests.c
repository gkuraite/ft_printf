/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:20:16 by gkuraite          #+#    #+#             */
/*   Updated: 2018/05/04 17:26:59 by gkuraite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int		ft_printf(const char *restrict format, ...)
//{
//}

#include <stdio.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int		main()
{
/*	int		num;
	printf("Enter a number : ");
	scanf("%d", &num);
	printf("You entered : %d", num);
	return (0);*/

	/*char	x = 5;
	long int	y = 20;
	printf("sizeof (x) = %lu \nsizeof (y) = %lu", sizeof(x), sizeof(y));
	return (0);*/

	/*printf("Condition\t\t Return");
	printf("\n5 > 3   : \t\t %d", 5 > 3);
	printf("\n2 == 2  : \t\t %d", 2 == 2);
	printf("\n10 >= 2 : \t\t %d", 10 == 2);*/

	/*int		a = 385; // prints binary stuff 
	int		b = 45;
	printf("a & b =  %d ", a & b);*/
	
	/*int		bonbons = 0; // prints total bonbons number won after 50 tirs
	int		tir = 1;
	repeat(50)
	{
		bonbons = bonbons + tir;
		printf("%d\n", bonbons);
		tir++;;
	}*/

	/*int		cube = 1; \\ prints total numbers of cubes by primary numbers
	int		cote = 1;
	int		total = 0;
	
	repeat(9)
	{
		cube = cote*cote*cote;
		total =  cube;
		cote = cote + 2;
	 }
	printf("%d\n", total);*/

/*	int		j; // prints multiplicationction table until 20 using for
	int		i;

	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
			printf("%5d ", i*j);
		printf("\n");
	}*/

	/*int		i = 1; // prints multiplication tabble of until 20
	int		j = 1;

	repeat(20)
	{
		j = 1;
		repeat(20)
		{
			printf("%5d", i*j);;
			j++;
		}
		printf("\n");
		i++;
	}*/

	/*int		tempMin; //prints graduatly numbers min to max
	int		tempMax;

	scanf("%d", &tempMin);
	scanf("%d", &tempMax);
	int		difference = tempMax - tempMin + 1;
	
	repeat(difference)
	{
		printf("%d\n", tempMin);
		tempMin++;
	}*/

	/*int		number; // prints mental calcualtions by incrementing multiplier by 1
	int		first_entry = 66;
	int		multiplier = 1;

	scanf("%d", &number);
	repeat (number)
	{
		int result  = first_entry * multiplier;
		printf("%d\n", result);
		multiplier++;
		first_entry = result;
	}*/

	/*int		positionDepart; //prints interval of locations depending on the vendors
	int		largeurEmplacement;
	int		nbVendeurs;

	scanf("%d", &positionDepart);
	scanf("%d", &largeurEmplacement);
	scanf("%d", &nbVendeurs);

	printf("%d\n", positionDepart);
	repeat (nbVendeurs)
	{
		positionDepart = positionDepart + largeurEmplacement;
		printf("%d\n", positionDepart);
	}*/

	// caclul l nombre de betes mais version longue 
	/*intt		a, hi, c, d, e, f, g, h, j, i, k, l, m, n, o, p, r, s, t, v; 

	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a,&hi,&c,&d,&e,&f,&g,&h,&j,&i,&k,&l,&m,&n,&o,&p,&r,&s,&t,&v);
	int hello = a+hi+c+d+e+f+g+h+j+i+k+l+m+n+o+p+r+s+t+v;
	printf("%d", hello);*/

	// calcul nombre de bete mais version courte, 20 ferniers donnes nb vache
	int		total = 0;

	repeat (20)
	{
		int		nbBetes;
		scanf("%d", &nbBetes);
		total = nbBetes + total;
	}
	printf("%d", total);
}
