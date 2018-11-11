#include <stdio.h>
int main(void)
{
	float f1 = 0x3.23p10;
	char ch[40];
	int size = sizeof(ch);
	
	printf("%d,%f\n", size,f1);
	getchar();
	return 0;
}