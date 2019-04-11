#include <stdio.h>
int main(void)
{
	int arg1,arg2;
	printf("Please enter arg2:");
	scanf("%d", &arg2);
	getchar();
	printf("Please enter arg1:");
	scanf("%d", &arg1);
	getchar();

	while(arg1 > 0)
	{
		printf("%d %% %d = %d\n",arg1, arg2, arg1 % arg2);
		printf("Please enter arg1:");
		scanf("%d", &arg1);
		getchar();
	}
	return 0;
}