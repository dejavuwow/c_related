#include <stdio.h>
double getDiffrence(double arr[], int n);
void reverse_arr(double arr[], int n);
int main(void)
{
	reverse_arr((double []){2.1, 2.56, 8.9, 19.2}, 4);
	getchar();
	return 0;
}
double getDiffrence(double arr[], int n)
{
	double min = arr[0], max = arr[0];
	int i = 0;
	while (++i < n)
	{
		max = max < arr[i] ? arr[i] : max;
		min = min > arr[i] ? arr[i] : min;
	}
	return max - min;
}
void reverse_arr(double arr[], int n)
{
	double temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;

	}
	for (int i = 0; i < n; i++)
		printf("%7.2f ", arr[i]);
}
