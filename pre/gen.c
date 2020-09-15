#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RAD_TO_DEG (180 / (4 * atan(1)))

#define SQRT(X) _Generic((X),\
		long double: sqrtl,\
		default: sqrt, \
float: sqrtf)(x)

#define SIN(X) _Generic((X),\
		long double: sinl,\
		default: sin,\
float: sinf\
)((yyy)/RAD_TO_DEG)
#define pt(...) printf("nihao"__VA_ARGS__)
void pr(void)
{
	printf("quit!");
}
int main(void)
{
	int b = 12;
	atexit(&pr);
	if (1)
	{
		(b) = 13;
	}
	printf("youa are my\n");
	printf("lili\n");
	float x = 45.0f;
	double xx = 45.0;
	long double xxx = 45.0L;

	double y = SQRT(x);
	double yy = SQRT(xx);
	double yyy = SQRT(xxx);
printf("%.17f\n", y);
	printf("%.17f\n", yy);
	printf("%.17f\n", yyy);

	int i = 45;
	yy = SQRT(i);
	printf("%.17F\n",yy);
	yyy = SIN(xxx);
	printf("%.17f\n", yyy);

	return 0;
}
