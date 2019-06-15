#include <stdio.h>
#include <string.h>
#include "test.h"
static int c = 3;
int d = 4;
int main(void)
{
	int actual_data[20] = {1,3,4};
	extern int a[];
	extern int *b;
	extern int c;
	extern int d;
	int x, y;
	x = a[3];
	/* y = ++a; */
	struct {
		int age;
		char name[20];
	} peter;
	peter.age = 12;
	strcpy(peter.name, "jinke");
	int *data = actual_data - 1;
	/* printf("%d, %d", c, d); */
	/* printf("%p, %p, %p", &actual_data[0], data, &peter.name[16]); */
	
	int array[4][5][3];
	int (*arr)[5][3];
	arr = array;

	printf("%d\n", *array == array[0]);
	printf("%d\n", *(array+2) == array[2]);
	printf("%d\n", *(array+1) + 4 == array[1]+4);
	printf("%d\n", *(*(array+1) + 4) == array[1][4]);
	
	int arr2[][3][3] = {
		{
			{1,2,3},
			{1,2,3},
			{1,2,3}
		},
		{
			{1,2,3},
			{1,2,3},
			{1,2,3}
		},
		{0}
	};
	int *pt;
	for (pt = **arr2; *pt != 0; pt++)
		printf("%d ", *pt);
	/*

	 ****
	 ****
	 ****

	 ****
	 ****
	 ****

	  */

	return 0;
}

