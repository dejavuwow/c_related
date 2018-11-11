#include <stdio.h>
int main(void)
{
	double inp;
	scanf("%lf",&inp);
	getchar();
	printf("The input is %lf or %le\n", inp, inp);
	printf("The input is %+.3lf or %.3E\n", inp, inp);
	getchar();
	return 0;
}