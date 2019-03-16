#include <stdio.h>
extern unsigned rand0(void);
int main(void)
{
	int count;
	for (count = 0; count < 5; count++)
		printf("%d\n", rand0());
	getchar();

	return 0;
}
