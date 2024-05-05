#include <stdio.h>
#define MAX 7

#if 0
	if(str[f_off] == '\0') {
		dest[s_off] = '\0';
		printf("%s\n", dest);
		return;
	}
#endif

void generate_substr(char num[], char target[], int index, int seq)
{
	int i;
	static int j = 0, k = 0;

	if(index > MAX) {
		for(i =0 ; i < seq; i++) {
			printf(" %c", target[i]);
		}
		printf("\n");
		return;
	}

	target[j] = num[index];
	j += 1;

	generate_substr(num, target, ++index, j);
	
	generate_substr(num, target, index, --j);
}

int main()
{
	char str[] = "abcdefgh", dest[10];

	generate_substr(str, dest, 0, 0);

	return 0;
}
