#include <stdio.h>
#include <stdlib.h>
int main (void) {

    int b = 5;
    int *a;
	a[2] = 3;
	printf("%p\n", a);
    free(a);
	printf("%p\n", a);
    a = &b;
	printf("%p", a);
    return 0;
}  
