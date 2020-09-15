#include <stdio.h>
int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	char arr1[15] = {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'};
	char arr2[15] = {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'};

	const int period1 = 3;
	const int period2 = 5;
	const int cycle = 3;

	int dealed1,
		dealed2;

	int pt1;
	for (pt1 = 0, dealed1 = 1, dealed2 = 1; pt1 < 14; pt1++)
	{

		if (pt1 % period1 == 0) {
			per
			if (dealed1 == 1)
				dealed1 = 0;
			else
			{

				dealed1 = 1;
				arr1[pt1-1] = '#';
			}

		}
		if (pt1 % period2 == 0) {
			if (dealed2 == 1)
				dealed2 = 0; 
		} 
		if (pt1 % period2 == (cycle - 1))
		{
			arr2[pt1] = '@';
			dealed1 = 1;
			dealed2 = 1;
		}

	}
	for (pt1 = 0; pt1 < 14; pt1++)
	{
		printf("%c ", arr1[pt1]);
	}
	putchar('\n');

	for (pt1 = 0; pt1 < 14; pt1++)
	{
		printf("%c ", arr2[pt1]);
	}
	return 0;
	
}
