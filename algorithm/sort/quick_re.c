#include <stdio.h>
#define print(array, size) {\
	for (int i = 0; i < size; i++)\
		printf("\t%d", array[i]);\
}
void insertSort(int array[], int start, int end)
{
	int temp, i, j;
	for (i = start + 1; i <= end; i++)
	{

		temp = array[i];
		j = i - 1;

		while (temp < array[j] && j >= 0)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}	
}

static inline void swap(int *adr1, int *adr2)
{
	int temp = *adr1;
	*adr1 = *adr2;
	*adr2 = temp;
}

int getMedian(int array[], int i, int j)
{
	int middle = (i + j) / 2;
	if (array[i] > array[middle]) swap(&array[i], &array[middle]);
	if (array[i] > array[j]) swap(&array[i], &array[j]);
	if (array[middle] > array[j]) swap(&array[middle], &array[j]);

	swap(&array[middle], &array[j - 1]);
	return array[j - 1];
}

void quickSort(int array[], int i, int j)
{
	if (i + 3 <= j)
	{
		int pivot = getMedian(array, i, j);
		int left = i;
		int right = j - 1;

		for (;;)
		{
			while (array[++left] < pivot){};
			while (array[--right] > pivot){};
			if (left < right)
			{
				swap(&array[left], &array[right]);
			}
			else
				break;
		}
		swap(&array[left], &array[j - 1]);
		quickSort(array, i, left - 1);
		quickSort(array, left + 1, j);
	}
	else
		insertSort(array, i, j);

}

void pureQuickSort(int *array, int i, int j)
{
	if (i >= j) return;
	int mid =  (i+j)/2;
	int pivot = array[mid];
	swap(&array[mid], &array[j]);
	
	int left = i,
		right = j - 1;
	while (left <= right)
	{
		while (array[left] < pivot){left++;};
		while (right > i && array[right] > pivot){right--;};
		if (left < right)
		{
			swap(&array[left], &array[right]);
			left++;
			right--;
		}
		else
			break;
	}
	swap(&array[left], &array[j]);
	pureQuickSort(array, i, left - 1);
	pureQuickSort(array, left + 1, j);
	
}

int main(void)
{
	int array[] = {23, 21, 3, 34, 334, 11, 452, 124};
	pureQuickSort(array, 6, 7);
	/** quickSort(array, 0, 7); */
	/** insertSort(array, 0, 7); */
	print(array, 8);
	return 0;
}
