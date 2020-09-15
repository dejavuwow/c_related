#include <stdio.h>
void quickSort(int array[], int left, int right)
{
	if (left >= right) return;
	int base = array[left];
	int i = left,
		j = right;

	while (i < j)
	{
		while ( i < j && array[j] >= base)
			j--;

		array[i] = array[j];

		while ( i < j && array[i] <= base)
			i++;

		array[j] = array[i];
	}
	array[i] = base;
	quickSort(array, left, i - 1);
	quickSort(array, i + 1, right);

}
int main(void)
{
	int arr[] = {5, 23, 1, 32, 7, 2};
	quickSort(arr, 0, 5);

	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
