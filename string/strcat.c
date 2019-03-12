#include <stdio.h>
#include <string.h>
#define SIZE 8
int main(void)
{
	char t1[18] = "nihaoya";
	char inp[SIZE];
	char res[] = "kkkkkkkk";
	char *test = "jiang";
	char formal[20];
	/* res = fgets(inp, SIZE, stdin); */
	/* strncat(t1, inp,3); */
	/* printf("%s , %p, %p\n", res, t1, inp); */
	strncpy(res, test,4);
	puts(test);
	printf("%c, %c, %c \n", res[3], res[4], res[5]);
	printf("%s \n", res);
	puts(t1);
	printf("%p, %p, %p \n", t1, res, test);
	sprintf(formal, "%s, %s", res, test);
	puts(formal);
	getchar();

	return 0;

}
