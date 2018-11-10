#include <stdio.h>
int main(void)
{
	float cups,pint,ounce,soulp,spoon;
	printf("please enter cups:");
	scanf("%f",&cups);
	getchar();
	pint = cups / 2;
	ounce = cups * 8;
	soulp = ounce * 2;
	spoon = soulp * 3;
	printf("cups equal to pint:%f,ounce:%f,soulp:%f,sppon:%f\n",pint,ounce,soulp,spoon);
	getchar();
	return 0;
}