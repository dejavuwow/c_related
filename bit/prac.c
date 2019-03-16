#include <stdio.h>
#include <string.h>
void combine(int *arr, int *flag, int n, int size, int num);
#define AVG(X,Y) (2/(1.0/(X) + 1.0/(Y)))
int main(void)
{
	int arr[4] = {6,4, 3,2}; //12
	int flag[4] = {0};
	double data1[10] = {10.0, 20.0};
	double data2[30] = {11.3, 21.3};

	memcpy(data1, data2, 10 * sizeof(double));
	for (int i = 0; i < 10; i++)
		printf("%f ", data1[i]);
	putchar('\n');

	memcpy(data1, data2+20, 10 * sizeof(double));
	for (int i = 0; i < 10; i++)
		printf("%f ", data1[i]);

	putchar('\n');
	printf("%f", AVG(1+3, 2+3));
	// 2 5 5  1
	//
	/* combine(arr,flag,0,3,36); */

	return 0;
}

void combine(int *arr, int *flag, int n, int size, int num)
{
	if (!num || n > size)
		return;

	int i = num / arr[n];
	int j = num % arr[n];

	if (i && !j)
	{
		flag[n] = i;
		for (int i1 = 0; i1 <= n; i1++)
			if (flag[i1] > 0)
				printf("%d * %d %c ", flag[i1], arr[i1], i1 == n ? ' ' : '+');
		putchar('\n');
	}

	for (int i1 = 0; i1 <= i; i1++)
	{
		if (i1 < i)
			flag[n] = i - i1;
		else
			flag[n] = 0;
		combine(arr, flag, n+1, size, i1*arr[n]+j);
	}

}
//11 1101   3b     00111011 77   01110111
//	21 25 15
//	85 125 55
//	76 114 4c
//	157 235 9d
// 252 2 7 7 5 3 28
// 255 1 0  4 6  2 40
// 0111 1111     0177  0x7F 127
