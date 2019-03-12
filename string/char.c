#include <stdio.h>
int main(void)
{
	for(char i = 0; i < 127; ++i) 
		printf("%d\n", i);
	getchar();
	return 0;
}
