#include <stdio.h>

int main()
{
	//int A[] = {0, 1, 2, 0, 1, 2};
	int A[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int B[12];
	int start = 0, low = 0, mid, temp, end = sizeof(A)/sizeof(int), i = 0, j = 0, k = 0;

	temp = end;

	while(low < end) {
		if(A[low] == 0)
			i++;
		if(A[low] == 1)
			j++;
		if(A[low] == 2)
			k++;

		low++;
	}
	
	printf("Output: \n");
	while(start < temp) {
		if(start < i)
			B[start] = 0;
		if(start >= i)
			B[start] = 1;
		if(start >= (i + j))
			B[start] = 2;

		start++;
	}

	start = 0;

	while(start<end)
		printf("%d\t", B[start++]);

	printf("\n");

	return 0;
}
