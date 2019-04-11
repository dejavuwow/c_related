#include <stdio.h>
#include <string.h>
int main(void)
{
	char t1[] = "adcou";
	char t2[] = "acahid";
	int ret;
	ret = strcmp(t1, t2);
	printf("%d \n", ret);
	ret = strncmp(t1, t2, 6);
	printf("%d \n", ret);
	getchar();
	
	return 0;
}
