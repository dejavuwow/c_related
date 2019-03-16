#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *ptr[100];
	printf("%p\n%p\n%p\n",ptr, ptr + 1, ptr + 2);
	*ptr = (char *)malloc(sizeof(char));
	ptr[1] = (char *)malloc(sizeof(char));
	ptr[2] = (char *)malloc(sizeof(char));
	**ptr = 'a';
	*(*ptr+1) = 'b';
	*(*ptr+2) = 'c';
	printf("%p\n%p\n%p\n",ptr, ptr + 1, ptr + 2);
	printf("%c\n%c\n%c",**ptr, *(*ptr + 1), *(*ptr + 2));
	free(*ptr);
	free(ptr[1]);
	free(ptr[2]);

	getchar();
	return 0;
}

