#include <stdlib.h>
#include <string.h>

void mergesort(int array[], int start, int mid, int end)
{
	int counts = end - start + 1;
	int temp[counts];
	int i = start,
		j = mid + 1;
	
	int o_start = 0;
	while (i <= mid && j <= end )
	{
		if (array[i] <= array[j])
			temp[o_start++] = array[i++];
		else
			temp[o_start++] = array[j++];
	}
	while (i <= mid)
		temp[o_start++] = array[i++];
	while (j <= end)
		temp[o_start++] = array[j++];

	memcpy(array+start, temp, counts * sizeof(int));
}

void divide(int array[], int start, int end)
{
	if (start >= end) return;
	int mid = start + (end - start) /  2;
	divide(array, start, mid);
	divide(array, mid + 1, end);
	
	mergesort(array, start, mid, end);
}

