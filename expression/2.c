#include <stdio.h>
int main(void)
{
	int integer;
	const int constant = 10;
	printf("Please enter an integer:");	

	while(scanf("%d",&integer) != 0)
	{
		int max = integer + constant;
		while(integer <= max)
		{
			printf("%d ",integer);
			integer++;
		}
		printf("\nPlease enter an integer:");
	}
	return 0;
}