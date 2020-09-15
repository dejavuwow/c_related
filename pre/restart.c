#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RAD_TO_DEG (180 / (4 * atan(1)))
#define TEST(X) _Generic((X),\
float: sinf,\
default: sin\
)((X)/RAD_TO_DEG)
int fun1(int a)
{
	return a+1;
};
float fun2(float b)
{
	return b+2;
};

int main(void)
{
	printf("%d", TEST(28.23f));
	return 0;
}

