#include <stdio.h>
#include <string.h>
int main(void)
{
	char arr[3] = {'n','i', 'h'};
	char string[] = "nihaowa";
	char *res;
	res = strchr(string, 'h');
	printf("%s", res);
	getchar();
	return 0;
}
