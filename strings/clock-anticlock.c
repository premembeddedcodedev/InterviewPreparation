//https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "geeks";
	//char str[] = "AMAZON";
	//enable this and below
	//char str2[] = "AZONAM";
	//char str2[] = "eksge";
	char str2[] = "ksgee";
	//char str2[] = "ONAMAZ";
	
	char substr_f[3], substr_l[3];

	strncpy(substr_f, str, 3);
	strncpy(substr_l, str+2, 3);

	if(strncmp(substr_f, str2+2, 2) == 0)
		printf("matched with Anti-clock\n");

	if(strncmp(substr_l, str2, 2) == 0)
		printf("matched with Clockwise\n");
	
	return 0;
}
