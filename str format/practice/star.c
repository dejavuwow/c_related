#include <stdio.h>
int main(void)
{
	int d;
	char c[30];
	scanf("%d %s",&d, c);
	getchar();
	printf("%s,%d\n", c, d);
	getchar();
	return 0;
}
