#include <stdio.h>
int main(void)
{
	int inp = 12;
	char error;
	while (scanf("%d",&inp) != 1)
	{
		while((error = getchar()) != '\n')
			putchar(error);
		printf(" is not a number, please enter a number correctly:");
	}
   /*  while(scanf("%d", &inp)!= 1) */
		// putchar(getchar());
	// while(getchar() != '\n')
		// continue;
	/* printf("%d", inp); */
	return 0;
}
