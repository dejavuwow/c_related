#include <stdio.h>
extern unsigned rand0(void);
extern int a;
int main(void)
{
	int count;
	printf("%d\n", a);
	for (count = 0; count < 5; count++)
		printf("%d\n", rand0());
	getchar();

	return 0;
}
