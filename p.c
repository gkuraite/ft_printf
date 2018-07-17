#include<stdio.h>
int main(){
	int i = 3;
	int *j;
	j = &i;
	*j++;
	printf("%d ",*j);
	return 0;
}