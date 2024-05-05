#include <stdio.h>
#include <string.h>

#define MAX 5

int dest[MAX*10];
int offset = 0;
void print_array(int num[], int max_array);

void swap(int *src, int *dst)
{
	int temp = *src;
	*src = *dst;
	*dst = temp;
}

void internal_sort(int a[][MAX], int array_index, int max_array)
{
	int i, j;

	for(i=0; i<max_array; i++) {
		for(j=i+1;j<max_array;j++) {
			if(a[array_index][i] > a[array_index][j])
				swap(&a[array_index][i], &a[array_index][j]);
		}
	}
}

void mergearray_sort(int a[][MAX], int array1, int max_array)
{
	int i, j;

	for(j=0;j<max_array;j++) {
		for(i=0; i<offset && (offset < (MAX*10)); i++) {
			if(a[array1][j] < dest[i]) {
				swap(&dest[i], &a[array1][j]);
			}
		}
		dest[offset++] = a[array1][j];
	}
}

void sort(int a[][MAX], int array_count, int max_array)
{
	int i, j;

	internal_sort(a,0, max_array);
	memcpy(dest, a, MAX*4);

	print_array(dest, MAX);

	printf("\n done with printing \n");

	offset = MAX;

	for(i=0; i<array_count; i++)
		internal_sort(a,i, max_array);

	i = 1;

	while(i<array_count) {
		mergearray_sort(a, i, max_array);
		i++;
	}

}

void print_array(int num[], int max_array)
{
	int j;

	for(j=0;j<offset;j++)
		printf("%d\t", num[j]);
	printf("\n");
}

void print(int num[][MAX], int array_count, int max_array)
{
	int i, j;

	for(i=0; i<array_count; i++) {
		printf("Array count: %d\n", i);
		for(j=0;j<max_array;j++)
			printf("%d\t", num[i][j]);
		printf("\n");
	}
}

int main()
{
	int m, n, i = 0, j = 0;

	printf("Enter the max arrays\n");
	scanf("%d", &m);

	printf("Enter the max values of arrays\n");
	scanf("%d", &n);

	int num[m][n];


	for(i=0; i<m; i++) {
		printf("Array count: %d\n", i);
		for(j=0;j<n;j++)
			scanf("%d", &num[i][j]);
		printf("\n");
	}

	print(num, m, n);

	sort(num, m, n);

	print(num, m, n);

	printf("\n Destination Array : \n");


	print_array(dest, MAX*10);

	return 0;
}
