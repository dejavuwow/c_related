#include <stdio.h>
int main(void)
{
	float f1;
	printf("please enter a float value:");
	scanf("%f",&f1);
	getchar();
	printf("fixed-point notation:%f\n", f1);
	printf("exponential notation:%e\n",f1);
	printf("p notation:%a\n",f1);
	getchar();
	return 0;
}