#include <stdio.h>
#include <math.h>
#include <string.h>
//993433
#define RESETARRAY(array, size) \
{\
	for (int i = 0; i < size; i++)\
		array[i] = 0;\
}
int radixsort(int array[], int size, int p, int k)
{
	//k基数 p位数
	int counts[k],
		temp[size];

	int n;
	int i;
	int remain;
	int index;

	for (n = 0; n < p; n++)
	{
		RESETARRAY(counts, k);
		RESETARRAY(temp, size);

		remain = pow((double)k, (double)n);

		for (i = 0; i < size; i++)
		{

			index = (array[i] % (remain * k)) / remain;
			printf("%d\t", index);
			counts[index]++;
		}

		for (i = 1; i < k; i++)
			counts[i] += counts[i - 1];

		putchar('\n');
		for (i = 0; i < size; i++)
		{

			printf("%d\t", array[i]);
			index = (array[i] % (remain * k)) / remain;
			temp[counts[index] - 1] = array[i];
			counts[index]--;
		}
		putchar('\n');
		for (int *p = temp; p < temp + size; p++)
			printf("%d\t", *p);
		putchar('\n');
		putchar('\n');
		memcpy(array, temp, size * sizeof(int));
	} 
	return 0;
}
int main(void)
{
	int array[] = {23,19,150, 43, 7, 95};
	int *tp = array;
	radixsort(array, 6, 3, 10);
	printf("%d %d\n", sizeof(array), sizeof(tp));
	for (int *p = array; p < array + 6; p++)
		printf("%d\t", *p);
	return 0;
}
