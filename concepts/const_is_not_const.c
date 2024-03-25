
#if 0
#include <stdio.h>

int main() {
    volatile const char c = 'A';

    c = 'X';

    printf(" &c: %p |    c: %c\n", &c, c);

    return 0;
}
#endif

#include <stdio.h>

int main() {
    volatile const char c = 'A';
    char *ptr = (char *)&c;

    printf(" &c: %p |    c: %c\n", &c, c);

    *ptr = 'X';

    printf(" &c: %p |    c: %c\n", &c, c);
    printf("ptr: %p | *ptr: %c\n", ptr, *ptr);

    return 0;
}
