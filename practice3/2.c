#include <stdio.h>
int main(void)
{
	int ch;
	printf("please enter a ASCII value");
	scanf("%d",&ch);
	getchar();
	printf("the value is %c",ch);
	getchar();
	return 0;
}