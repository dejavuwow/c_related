#include <stdio.h>
#define TEST(a) {\
	if ( 5==a) \
		printf("yes, you do!");\
}
int main(void)
{
	int a = 5;
	TEST(a);
	return 0;
}
