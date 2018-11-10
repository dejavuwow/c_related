#include <stdio.h>
int main(void)
{
	char ch;
	printf("Please enter a character.\n");
	scanf("%c",&ch);
	printf("The code for %c is %#x.\n",ch,ch);
	getchar();
	getchar();
	return 0;
}