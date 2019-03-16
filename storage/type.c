#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char t1[] = "nihaoa",
		 t2[] = "thank you";
	char *t3 = (char *)malloc(sizeof(char) * 10);
	strcpy(t3,"noimnotmyi");
	printf("%p, %p, %p, %p\n", t1, t2, "nihaoa","thank you");
	printf("%p, %p", t3, "noimnotmyi");
	getchar();

	return 0;
}
