#include <stdio.h>
int main(void)
{
	int days = 0,
	profit = 0;

	printf("Please enter days:");
	scanf("%d",&days);
	getchar();

	while(days > 0)
	{
		while(days > 0)
		{
			profit += days;
			days--;
		}
		printf("you can earn $%d\n", profit);
		profit = 0;
		
		printf("Please enter days:");
		scanf("%d",&days);
		getchar();
	}
	return 0;
}
//test
