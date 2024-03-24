#include <stdio.h>

int main()
{
	//int arr[] = {1, 1, 2, 2, 2, 2, 3},   x = 2;
	//int arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3;
	int arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1;
		int i;
	int count = 0;

	for(i=0; i<sizeof(arr)/sizeof(int); i++) {
		if ((x^arr[i]) == 0)
			count++;
	}

	printf("%d\n", count);

	return 0;
}
