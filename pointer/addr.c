#include <stdio.h>
int main(void)
{
	int arr[3][2] = {
		{1,2},
		{2,3},
		{4,5}
	};
	printf("%d, %d", arr[2][0], *(*(arr+2)));
	getchar();
	return 0;
}
