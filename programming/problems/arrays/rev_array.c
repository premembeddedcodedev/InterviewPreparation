#include <stdio.h>

void rev_array(int a[], int length)
{
	int temp, i = 0, mid = length/2;

	while( i < mid) {
		temp = a[i];
		a[i] = a[length - 1 - i];
		a[length - 1 - i] = temp;
		i++;
	}
}

int main()
{
	int i;
	int a[10] = {99, 78, 67, 44, 34, 24, 89, 56, 45, 24};

	int length = sizeof(a)/sizeof(int);
	
	for(i=0;i<10;i++)
		printf("%d\t", a[i]);

	printf("\n");

	rev_array(a, length);


	for(i=0;i<10;i++)
		printf("%d\t", a[i]);

	printf("\n");

	return 0;
}
