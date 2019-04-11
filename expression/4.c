#include <stdio.h>
int main(void)
{
	const float inch = 2.54;
	const float foot = 30.48;
	float height = 0;
	int feet = 0;
	float inches = 0;

	printf("Please enter your height in centimeters:");
	scanf("%f",&height);
	getchar();

	while(height > 0)
	{
		feet = height / foot;
		inches = (height - feet * foot) / inch;
		printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);
		printf("Please enter your height in centimeters:");
		scanf("%f",&height);
		getchar();
	}
	return 0;
}