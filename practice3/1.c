#include <stdio.h>
int main(void)
{
	int arr[][3] = {1,2,3,4,5};
	int (*p)[3] = arr;
	printf("%d\n", *(*(p+1)+3));
	long long int pop = 100000000000000023;
	float f1 = 3.4E39,f2 = 1.2323212327812;
	printf("%lld,%e,%f\n",pop,f1,f2);
	getchar();
	return 0;
}
