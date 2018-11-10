#include <stdio.h>
#include <string.h>
int main(void)
{
	char yourName[20];
	int nameLength = 0;
	printf("Please enter your name:");
	scanf("%s",yourName);

	getchar();

	nameLength = strlen(yourName);

	printf("\"%20s\"\n", yourName);
	printf("\"%-20s\"\n", yourName);
	printf("%*s\n", nameLength + 3, yourName);
	getchar();
	return 0;
}