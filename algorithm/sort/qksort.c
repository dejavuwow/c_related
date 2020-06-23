#include <stdio.h>
void printArray(int array[], int array_size)
{
	for (int *temp = array; temp < array + array_size; temp++)
		printf("%d ", *temp);
	putchar('\n');
}

void quickSort(int array[], int start, int end)
{
	if (start >= end) return;
	int base = array[start];
	int origin_start = start;
	int origin_end = end;
	while (origin_start < origin_end)
	{
		//0  1
		//2
		while (array[origin_end] >= base && origin_start < origin_end){
		origin_end--;
		
		} 	
		array[origin_start] = array[origin_end];
		while (array[origin_start] < base && origin_start < origin_end)
		{
			origin_start++;
		}		
		array[origin_end] = array[origin_start];
	}
	array[origin_start] = base;
	printArray(array, 8);
	quickSort(array, start, origin_start - 1);
	quickSort(array, origin_start + 1, end);
}

int main(void)
{
	int array[] = {35, 12, 4, 39, 28, 390, 207, 33};
	quickSort(array, 0, 7);
	printArray(array, 8);
	return 0;
}
