#include <stdio.h>
int main(void)
{
	float f = 2233.232;
	char test[] = "my stick";
	printf("%-7.2s  %2.2e\n", test, f);
	getchar();
	return 0;
}

