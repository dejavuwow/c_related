#include <stdio.h>
#include <float.h>
int main(void)
{
	int cost  = 12.99;
	double d1 = 1.0 / 3.0;
	float f1 = 1.0 / 3.0;
	printf("%.6f,%.6f,%d,%f\n", d1, f1, cost, cost);
	printf("%.12f,%.12f\n", d1, f1);
	printf("%.16Lf,%.16Lf\n", d1, f1);
	printf("%f,%f\n", FLT_DIG, DBL_DIG);
	getchar();
	return 0;
}