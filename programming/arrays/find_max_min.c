#include <stdio.h>
#include <limits.h>

int main()
{
	int N = 6, i=0, j, min = INT_MAX, max = 0;
	//int a[6] = {3, 2, 1, 56, 10000, 167};
	int a[5] = {1, 345, 234, 21, 56789};

	while(i<N) {
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
		i++;
	}

	printf("min : %d\n", min);
	printf("max : %d\n", max);

	return 0;
}
