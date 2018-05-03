/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:20:16 by gkuraite          #+#    #+#             */
/*   Updated: 2018/05/03 16:02:39 by gkuraite         ###   ########.fr       */
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

	/*int		a = 385;
	int		b = 45;
	printf("a & b =  %d ", a & b);*/
	
	/*int		bonbons = 0;
	int		tir = 1;
	repeat(50)
	{
		bonbons = bonbons + tir;
		printf("%d\n", bonbons);
		tir++;;
	}*/

	/*int		cube = 1;
	int		cote = 1;
	int		total = 0;
	
	repeat(9)
	{
		cube = cote*cote*cote;
		total =  cube;
		cote = cote + 2;
	 }
	printf("%d\n", total);*/

/*	int		j;
	int		i;

	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
			printf("%5d ", i*j);
		printf("\n");
	}*/

	/*int		i = 1;
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

	int		tempMin;
	int		tempMax;

	scanf("%d", &tempMin);
	scanf("%d", &tempMax);
	int		difference = tempMax - tempMin + 1;
	
	repeat(difference)
	{
		printf("%d\n", tempMin);
		tempMin++;
	}
}
