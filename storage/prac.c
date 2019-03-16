#include <stdio.h>
static int distance;
static double fuel;
void set_mode(int * const restrict mode, int * const restrict old_mode)
{
	if (*mode > 1)
	{
		*mode = *old_mode;
		printf("Invalid mode specified."
				"Mode %d(%s)used", *mode, *mode == 1 ? "US" : "metric");
	}
	else
		*old_mode = *mode;
}
void get_info(int * const distance, double * const fuel, const int * const restrict mode)
{
	if (*mode == 1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%d", distance);
		printf("Enter fuel consumed in gallons");
		scanf("%lf", fuel);
	}
	else {
		printf("Enter distance traveled in kilomerters:");
		scanf("%d", distance);
		printf("Enter fuel consumed in liters:");
		scanf("%lf", fuel);
	}

}
void show_info(const int * const restrict distance, const double * const restrict fuel, const int * const restrict mode)
{
	if (*mode == 1)
		printf("Fuel consumption is %f miles per gallon",*distance / *fuel );
	else
		printf("Fuel consuptionis %f liters per 100km", *fuel / (*distance / 100));

}
