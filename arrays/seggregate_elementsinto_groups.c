#include <stdio.h>

int main()
{
	//int A[] = {0, 1, 2, 0, 1, 2};
	int A[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int low = 0, mid, end = sizeof(A)/sizeof(int), i, j;

	i = low;
	j = end;

	int temp;

	while(i<end) {
		if(A[i] == A[j]) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		} else
			j--;

		if(i>=j) {
			i++;
			j = end;
		}
	}
	
	i = 0;

	printf("Output: \n");
	while(i<end)
		printf("%d\t", A[i++]);

	printf("\n");

	return 0;
}
