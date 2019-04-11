#include <stdio.h>
extern int a;
int main(void)
{
	int xy;
	a = 20;
	char *arr = "nihao";
	arr = "buhao";
	{
		extern int a;
		printf("%d", a);
	}
	puts(arr);
	return 0;
}
