#include <stdio.h>
int ctsort(int array[], int size, int max)
{
	int counts[max];
	int temp[size];

	int i, j;

	for (i = 0; i < max; i++) counts[i] = 0;
	for (j = 0; j < size; j++) counts[array[j]]++;
	// 10020002001001
	// 11133335556667
	for (i = 1; i < max; i++)
		counts[i] = counts[i] + counts[i - 1];

	/** for (i = size - 1; i  >= 0; i--) */
	/** { */
	/**     temp[counts[array[i]] - 1] = array[i]; */
	/**     counts[array[i]]--; */
	/** } */
	for (i = 0; i < size; i++)
	{
		temp[counts[array[i]] - 1] = array[i];
		counts[array[i]]--;
	}
	for (int i = 0; i < size; i++)
		printf("%d ", temp[i]);

	return 0;
	
	
}

int main(void)
{
	int array[] = {89, 2, 3, 72, 12, 6, 38};
	ctsort(array, 7, 90);
	return 0;

}
