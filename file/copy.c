#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *s_gets(char *str, int n);

int main(void)
{
	FILE *fp;
	char name[40];
	char read, change;

	s_gets(name, 40);
	fp = fopen(name, "r+");
	while ((read = getc(fp)) != EOF)
	/* while ((change = getchar()) != '#') */
	{
		fseek(fp, -1, SEEK_CUR);
		int bi = putc(toupper(read), fp);
		printf("%d", bi);
		/* fseek(fp, 0, SEEK_CUR); */
	}
	//jiang

	fclose(fp);
	getchar();
	return 0;
}

char *s_gets(char *str, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		if (find = strchr(ret_val,'\n'))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
