#include <stdio.h>
#include <string.h>
#define SIZE 10
char *s_gets(char *st, int n);
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes";
	puts("what's your favorite flower");
	if (s_gets(flower, SIZE))
	{
		printf("%u \n", sizeof(flower));
		printf("%u \n", strlen(flower));
		printf("%p \n", flower);
		strcat(flower, addon);
		puts(flower);
		printf("%u \n", sizeof(flower));
		printf("%u \n", strlen(flower));
		printf("%p \n", flower);
		puts(addon);
	}
	else
		puts("End of file encountered");
	puts("bye");
	getchar();
	
	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
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
