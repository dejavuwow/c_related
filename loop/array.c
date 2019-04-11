#include <stdio.h>
int main(void)
{
	int tt[10],index = 0;
	for (;index <= 12; index++)
	{
		scanf("%d",&tt[index]);
		getchar();
		printf("%d -> %d ", index, tt[index]);
	}
	getchar();
	return 0;
}
// 1：hi
// k = 1
// k is 1

// now k is 3
// k = 3 
// k is 3

// now k is 5
// k = 5
// k is 5

// now k is 7
// k = 7

