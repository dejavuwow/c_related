#include <stdio.h>
int main(void)
{
	int a = 0;
	while(a++ < 0)
		;
	printf("%d",a);
	getchar();
	return 0;
}