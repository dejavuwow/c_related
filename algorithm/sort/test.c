#include <stdio.h>
#include "./mergesort.h"

void printArray(int array[], int array_size)
{
	for (int *temp = array; temp < array + array_size; temp++)
		printf("%d ", *temp);
	putchar('\n');
}

int main(void)
{
	int array[] = {35, 12, 4, 39, 28, 390, 207, 33};
	divide(array, 0, 8);
	printArray(array, 8);

	return 0;
}
