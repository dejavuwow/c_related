#include <stdio.h>
#define WEEKDAYS 7
int main()
{
	int days;
	printf("Please enter days:");
	scanf("%d",&days);
	getchar();

	while(days > 0)
	{
		printf("days converted to %d weeks %d days\n", days / WEEKDAYS, days % WEEKDAYS);
		printf("Please enter days:");
		scanf("%d",&days);
		getchar();
	}
	return 0;
}