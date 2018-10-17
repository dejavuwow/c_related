#include <stdio.h>
int main(void)
{
	int inp;
	while((inp = getchar()) != EOF)
		putchar(inp);
	return 0;
}