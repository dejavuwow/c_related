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
}
