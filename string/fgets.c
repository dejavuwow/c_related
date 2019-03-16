#include <stdio.h>
int main(void)
{
	char inp[6];
	fgets(inp, 6, stdin);
	fputs(inp, stdout);
	puts(inp);
	getchar();

	return 0;
}
