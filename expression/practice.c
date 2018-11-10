#include <stdio.h>
#define ONE_HOUR 60
int main(void)
{
	int minutes;  //声明输入的分钟数

	printf("Please enter minutes to be converted:");
	scanf("%d",&minutes);
	printf("%d\n",minutes);
	getchar();

	while(minutes > 0)
	{
		printf("minutes your entered are converted to %d hours %d minutes.\n", minutes / ONE_HOUR, minutes % ONE_HOUR);
		printf("Please enter minutes to be converted:");
		scanf("%d",&minutes);
		getchar();
	}

	printf("done\n");
	getchar();
	return 0;

}
