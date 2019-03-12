#include <stdio.h>
int add(int *a, int *b);
int main(void)
{
	int a = 2;
	int b = 3;
	int c = add(&a, &b);
	return c;
}
int add(int *a, int *b)
{
	return *a + *b;
}
