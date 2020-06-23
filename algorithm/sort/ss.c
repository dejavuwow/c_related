#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 15
#define L 2
#define R 3

void arrayShift(int array[], int size, int direction, int nums)
{
	int x = size - nums;
	int temp[size];
	if (direction == 1)
	{
		memmove(temp, array, nums * sizeof(int));
		memmove(array, array + nums, x * sizeof(int));
		memmove(array+size-nums, temp, nums * sizeof(int));
	}
	else if (direction == 2)
	{
	
		memmove(temp, array + x, nums * sizeof(int));
		memmove(array + nums, array, x * sizeof(int));
		memmove(array, temp, nums * sizeof(int));
	}
}
int main(void)
{
	int array[N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	arrayShift(array, N, 1, 2);
	puts("left 2:");
	for (int *i = array; i  < array + N; i++)
		printf("%d ", *i);
	
	putchar('\n');
	puts("right 3:");
	arrayShift(array, N, 2, 3);
	for (int *i = array; i  < array + N; i++)
		printf("%d ", *i);
	return 0;
}
