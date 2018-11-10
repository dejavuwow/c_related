#include <stdio.h>
void Temperatures(float fahrenheit);
int main(void)
{
	double fahrenheit;
	printf("please enter Temperatures in fahrenheit:");

	while(scanf("%lf",&fahrenheit) == 1)
	{
		Temperatures(fahrenheit);
		printf("please enter Temperatures in fahrenheit(or enter q to quit):");
	}
	return 0;
}

void Temperatures(float fahrenheit)
{
	const float to_celsius1 = 5.0f / 9.0f;
	const float to_celsius12 = 32;
	const float to_kelvin = 273.16;
	float celsius = to_celsius1 * (fahrenheit - to_celsius12), 
	kelvin = celsius + to_kelvin;
	printf("%.2f fahrenheit are converted to celsius:%.2f, kelvin:%.2f\n", celsius, celsius, kelvin);
}