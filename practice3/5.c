#include <stdio.h>
int main(void)
{
	short age;
	float second = 3.156e7;
	float allsecond;
	printf("please enter your age:");
	scanf("%d",&age);
	getchar();
	allsecond = age * second;
	printf("your age is equal to %f\n", allsecond);	
	getchar();
	return 0;
}