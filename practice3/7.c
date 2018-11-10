#include <stdio.h>
int main(void)
{
	float height;
	printf("please enter your height with inch:");
	scanf("%f",&height);
	getchar();
	float cm = height * 2.54;
	printf("%f\n", cm);
	getchar();
	return 0;
}