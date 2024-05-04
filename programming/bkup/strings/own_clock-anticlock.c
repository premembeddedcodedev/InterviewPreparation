//https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int my_strncpy(char fl_str[], char str[], int count, int start_offset)
{
	int i = 0;

	while(i<count) {
		fl_str[i] = str[start_offset+i];
		i++;
	}
}

int my_strncmp(char fl_str[], char str[], int count, int start_offset)
{
	int i = 0, k = 0;

	while(i<count) {
		if(fl_str[i] == str[start_offset+i]) {
			k++;
		} else
			k = 0;
		
		i++;
	}

	return k == count ? 0 : 1;
}

int main()
{
	char str[] = "geeks";
	//enable this and below
	//char str2[] = "eksge";
	char str2[] = "ksgee";
	
	char substr_f[3], substr_l[3];

	my_strncpy(substr_f, str, 3, 0);
	printf("first: %c\t",substr_f[0]);
	printf("%c\t",substr_f[1]);
	printf("%c\n",substr_f[2]);

	my_strncpy(substr_l, str, 3, 2);
	printf("second: %c\t",substr_l[0]);
	printf("%c\t",substr_l[1]);
	printf("%c\n",substr_l[2]);

	if(my_strncmp(substr_f, str2, 3, 2) == 0)
		printf("matched with Anti-clock\n");

	if(my_strncmp(substr_l, str2, 3, 0) == 0)
		printf("matched with Clockwise\n");
	
	return 0;
}
