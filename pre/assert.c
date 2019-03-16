#include <stdio.h>
#include <math.h>
#define NDEBUG
#include <assert.h>
#define g 19
int main(void)
{
	union name {
		char first[8];
		double height;
	};
	union name f1 = {
		.first = "yes"
	};
	union name f2 = {
		.height = 15.9
	};
	printf("%f", f1.height);
	printf("\n%p\n%p\n", f1.first, &f1.height);
	printf("%u %s", sizeof(f1), f1.first);

	double x, y, z;
	x = 15.0;

	_Static_assert(g == 19, "x != 15");
	puts("Enter a paer of numbers(0 0 to quit):");
	while (scanf("%lf%lf", &x, &y) == 2
			&& (x != 0 || y != 0))
	{
		z = x * x - y * y;
		assert(z >= 0);
		printf("answer is %f\n", sqrt(z));
		puts("Next pair of numbers:");
	}

	puts("Done");

	return 0;
}
