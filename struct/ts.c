#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *pt(char *ptr)
{
	char temp[] = "yes you do";
	ptr = (char *)malloc(strlen(temp)+1);
	strcpy(ptr,temp);
	printf("%p\n", temp);
	printf("%p\n", ptr);
	printf("%s\n", ptr);

	return ptr;
}

int main(void)
{
	char *ptr;
	int *in;
	float *f1;
	double *f2;
	int a = 123;
	char arr[] = "yes";
	printf("%p\n%p\n%p\n", ptr, &a, arr);
	printf("%p\n%p\n%p", in, f1, f2);
	
	getchar();
	return 0;
}
