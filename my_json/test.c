#include <stdio.h>
#include <stdlib.h>
double parse_num(const char *num);

int main(void)
{
	const char num[] = "-2.233E3";

	printf("%f", parse_num(num));
	char *ptr = malloc(20);
	ptr[0] = '2';
	ptr[1] = '3';
	ptr[2] = '\0';
	printf("%p, %s\n", ptr, ptr);
	free(ptr);
	printf("%p, %s\n", ptr, ptr);

	return 0;
}



