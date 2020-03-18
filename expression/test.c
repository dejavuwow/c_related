#include <stdio.h>
int main(void)
{
	int arr[] ={1, 2, 3};
	int *ar = arr;
	printf("%p, %p\n", &arr, arr);
	printf("%p, %p", &ar, ar);
	return 0;
}
