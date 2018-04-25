#include <stdio.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int main()
{
	int		tempMin;
	int		tempMax;

	scanf("%d", &tempMin, &tempMax);
	int		difference = tempMax - tempMin;
	repeat(difference)
	{
		printf("%d\n", tempMin);
		tempMin++;
	}
	printf("%d", tempMax);
}
