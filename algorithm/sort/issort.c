#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
{
	char *a = data;
	void *key;
	int i, j;

	if ((key = (char *)malloc(esize)) == NULL)
		return -1;

	for (j = 1; j < size; j++)
	{
		memcpy(key, &a[j * esize], esize);
	}
}
void printArray(int array[], int array_size);
int simp_issort(int array[], int array_size)
{
	int j;
	int temp;
	for (int i = 1; i < array_size; i++)
	{
		j = i - 1;
		temp = array[i];
		while (j >= 0 && array[j] > temp) {
			array[j+1] = array[j];
			j--;
		};
		array[j+1] = temp;
	}
	return 0;
}
void printArray(int array[], int array_size)
{
	for (int *temp = array; temp < array + array_size; temp++)
		printf("%d ", *temp);
}
int main(void)
{
	//{18,25,12}
	int testArray[] = {9, 2, 8,234, 7, 1, 25, 18, 12};
	simp_issort(testArray, 9);
	printArray(testArray, 9);
	return 0;
}
