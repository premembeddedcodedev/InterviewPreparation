#include <stdio.h>
#include <string.h>
#include <limits.h>


int find_lcp(char str1[][20], int num_strings)
{
	int i = 0, j = 0, count_s = 0, count = 0, min = INT_MAX, largestring = 0, left = 0;

	for(i=0; i<num_strings; i++) {
		if(str1[i][0] == '\0') {
			return 0;
		}
		if(strlen(str1[i]) < min) {
			min = strlen(str1[i]);
			largestring = i;
		}
	}
	
	i = 0;

	while(j<strlen(str1[largestring])-1) { //iterate number of characters
		count_s = 0; //this will reset the after comparisions done in # of strings
		char c = str1[largestring][j];
		while(i<num_strings) { // iterate number of strings
			if (i == largestring) { // this will skip comparision of maxlen string
				i++;
				continue;
			}

			if(str1[i][0] == '\0') {
				return count;
			}

			if(c = str1[i][j]) {
				count_s++;	
			}

			i++;
		}
		i = 0; // this was bug
		if (count_s == num_strings - 1)
			count++; //counting the common characters
		else
			return count;
		j++;
	}

	return count;
}

int main()
{
	//char str[][10] = {"geeks", "geek", "geezer"};

	//char str[][20] = {"geeksforgeeks", "geeks", "geek", "geezer"};

	char str[][20] = {"apple", "ape", "april"};

	printf("LCP: %d\n", find_lcp(str, 3));

	

	return 0;
}
