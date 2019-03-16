#include <stdio.h>
#define XNAME(n) xn
#define NAME(n) x##n
int include(int arr[], int max, int num)
{
	int XNAME(1) = 3;
	int NAME(2) = 4;
	printf("%d %d\n", xn, x2);
	int min = 0;
	int mid;
	while (min <= max)
	{
		mid = (max+min)/2;
		if (num > arr[mid])
			min = mid + 1;
		else if (num < arr[mid])
			max = mid - 1;
		else
			return 1;
	}
	return 0;
}
int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9 ,10};
	int inp;
	puts("Enter your number:");
	while (scanf("%d", &inp) == 1)
	{
		printf("%d %sin arrs.\n", inp, include(arr, 9, inp) ? "is " : "isn't ");
		puts("Enter your number:");

	}

	return 0;
}
