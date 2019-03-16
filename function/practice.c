#include <stdio.h>
double min(double x, double y);
void chline(char ch, int i, int j);
double harmonic_mean(double x, double y);
void larger_of(double * x, double * y);
void sort(double * x, double * y, double * z);
int main(void)
{
	double x = 0.5, y = 0.6, z = 1.3;
	sort(&x, &y, &z);
	printf("%.2f, %.2f, %.2f", x, y, z);	
	getchar();
	return 0;
}

//求两个double类型数字的最大数
double min(double x, double y)
{
	return x >= y ? x : y;
}

//打印字符j行i列
void chline(char ch, int i, int j)
{
	for (int i1 = 1; i1 <= i; i1++)
	{
		for (int j1 = 1; j1 <= j; j1++)
			printf("%c", ch);
		printf("\n");
	}
}

double harmonic_mean(double x, double y)
{
	double average;
	average = (1 / x + 1 /y) / 2;
	return 1 / average;
}

void larger_of(double * x, double * y)
{
	if (*x > *y) {
		*y = *x;
	}
	else {
		*x = *y;
	}
}

void sort(double * x, double * y, double * z)
{
	double temp;
	if (*x > *y) {
		temp = *x;
		*x = *y;
		*y = temp;
	}
	if (*y > *z) {
		temp = *y;
		*y = *z;
		*z = temp;
	}
	if (*x > *y) {
		temp = *x;
		*x = *y;
		*y = temp;
	}
}
