#include <stdio.h>
#include <stdlib.h>
_Bool isInclude(int arr[], int n, int num);

int main(void)
{
}
_Bool isInclude(int arr[], int n, int num)
{
	int max = n - 1;
	int min = 0;
	int mid;
	while (min <= max)
	{
		mid = (min + max) / 2;
		if (arr[mid] == num)
			return 1;
		else if (arr[mid] > num)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return 0;
}
