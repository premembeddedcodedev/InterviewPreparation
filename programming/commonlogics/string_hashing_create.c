#include<stdio.h>
#include <string.h>

void create_hash(char *str)
{
	int start = 0, end = 0, len = strlen(str), hashmap[26];

	memset(hashmap, 0, len);

	for(start = 0; start < len; start++)
		hashmap[str[start] - 'a']++;

	start = 0;
	int count = 0;

	while(start < 26) {
		if(hashmap[start] == 1)
			count++;
		start++;
	}

	if(count > 1)
		printf("not a palindrome\n");
	else
		printf("palindrome may found\n");
}

int main()
{
	char *str = "babad";

	create_hash(str);

	return 0;
}
