#include <stdio.h>
void sort(int *arr, int i1, int j1);

int main(void)
{
	int arr[] = {1,2,1, 34, 12,2,1};
	sort(arr, 0, 6);
	for (int i = 0; i < 7; i++)
		printf("%d\n", arr[i]);

	return 0;
}

void sort(int *arr, int i1, int j1)
{
	if (i1 >= j1)
		return;

	int i = i1;
	int j = j1;
	int base = arr[i];

	while (i < j)
	{
		while (i < j && arr[j] >= base)
			j--;
		arr[i] = arr[j];

		while (i < j && arr[i] < base)
			i++;
		arr[j] = arr[i];
	}

	arr[i] = base;
	sort(arr, i1, i);
	sort(arr, i+1 , j1);
}
//1,2,1
//1,2,1
//1,2,1
//1,2,2
//1,1,2
//1,1
//2,1
//
//1,2
//1,2
//
//1,2
//1,1
//1,2
//2,2
//1,1
//1,1
