/*
 * How this program works,
- We define an array of integers with a size of `ARRAY_SIZE`.
- We access the elements of the array sequentially in a loop, which is likely to utilize the CPU cache effectively.
- We measure the time taken for sequential access.
- We then access the elements of the array in a non-sequential manner by skipping elements based on the cache line size, potentially causing cache misses.
- We measure the time taken for non-sequential access.

By comparing the times taken for sequential and non-sequential access, you can observe the impact of CPU cache on program performance. Accessing elements sequentially should be significantly faster due to cache utilization, while non-sequential access may incur cache misses and result in longer execution times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define CACHE_LINE_SIZE 64 // Assuming cache line size of 64 bytes

int main() {
	int array[ARRAY_SIZE];
	clock_t start, end;
	double cpu_time_used;

	// Initialize array elements
	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = i;
	}

	// Access elements sequentially to utilize cache
	start = clock();
	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i]++;
	}
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for sequential access: %f seconds\n", cpu_time_used);

	// Access elements in a non-sequential manner to potentially cause cache misses
	start = clock();
	for (int i = 0; i < ARRAY_SIZE; i += CACHE_LINE_SIZE/sizeof(int)) {
		array[i]++;
	}
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for non-sequential access: %f seconds\n", cpu_time_used);

	return 0;
}
