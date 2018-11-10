#include <stdio.h>
int main(void)
{
	char first_name[20],last_name[20];
	printf("Please enter your name:");
	scanf("%s%s",first_name, last_name);
	getchar();
	printf("hello,%s,%s\n", first_name, last_name);
	getchar();
	return 0;
}