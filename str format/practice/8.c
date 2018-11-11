#include <stdio.h>
#define GALLON 3.785
#define KM 1.609
int main(void)
{
	double mileage, gallon,average = 0,average_usa;

	printf("Please enter mileage:");
	scanf("%lf",&mileage);
	getchar();

	printf("Please enter gallon:");
	scanf("%lf",&gallon);
	getchar();

	average = mileage / gallon;
	printf("every gallon can run %.1f\n", average);
	getchar();

	average = gallon * GALLON / (mileage * KM);
	average = average * 100;

	average_usa = mileage * KM / (gallon * GALLON);

	printf("EU %.12f,USA:%.f\n", average, average_usa);
	getchar();
	return 0;

}