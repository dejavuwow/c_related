#include <stdio.h>
#include <math.h>
#define SIZE 3
void transform(const double source[], double target[], int n, double (*ptr)(double))
{
	for (int i = 0; i < n; i++)
	{
		printf("%f ->", source[i]);
		target[i] = (*ptr)(source[i]);
		printf("%f\n", source[i]);
	}

}

int main(void)
{
	double source[] = {19.2, 23.2, 53.77};
	double target[3] = {0.0};
	transform(source, target, 3, floor);
	putchar('\n');
	for (int i = 0; i < 3; i++)
		printf("%f\n", source[i]);
	putchar('\n');
	for (int i = 0; i < 3; i++)
		printf("%f -> %f\n", source[i], target[i]);

	return 0;
}
