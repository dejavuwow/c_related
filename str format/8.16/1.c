#include <stdio.h>
int main(void)
{
	int d1 = -12;
	int d2 = 12;
	float f1 = -13.5;
	printf("%.5d\n", d1);
	printf("% d\n", d2);
	printf("%     d\n", d2);
	printf("%6d\n", d2);
	printf("%5d\n", d1);
	printf("%5.5d\n", d1);
	printf("%-05d\n", d1);
	printf("%-5d\n", d1);
	printf("%#f\n", f1);
	printf("%f\n", f1);
	printf("%#7.0f\n", f1);
	printf("%.7f\n", f1);
	printf("%8.2f\n", f1);
	printf("%08.2f\n", f1);
	getchar();
	return 0;
}