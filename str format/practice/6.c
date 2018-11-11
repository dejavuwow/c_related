#include <stdio.h>
#include <string.h>
int main(void)
{
	char first_name[20], last_name[20];
	int first_size = 0, last_size = 0;

	printf("Please enter your first name:");
	scanf("%s",first_name);
	getchar();

	printf("Please enter your last name:");
	scanf("%s",last_name);
	getchar();

	first_size = strlen(first_name);
	last_size = strlen(last_name);
	printf("%s %*s\n", first_name, last_size,last_name);
	printf("%*d%*d\n", first_size, first_size, last_size, last_size); 
	getchar();
	return 0;
}