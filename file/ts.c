#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
char *s_gets(char *str, int c);

int main(void)
{
	FILE *fp;
	char file_name[MAX];
	long int seek;
	char ch;
	fputs("Please enter the file: ", stdout);
	s_gets(file_name, MAX - 1);

	if ((fp = fopen(file_name, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (scanf("%ld", &seek) == 1 && fseek(fp, seek, SEEK_SET) == 0)
	{
		while ((ch = getc(fp)) != '\n' && ch != EOF)
			printf("%c", ch);
		/* putchar('\n'); */
	}

	fclose(fp);
	getchar();
	return 0;
}

char *s_gets(char *str, int c)
{
	char *ret_val;
	char *find;
	ret_val = fgets(str, c, stdin);
	if  (ret_val)
	{
		if (find = strchr(ret_val, '\n'))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;

	}
	return ret_val;
}
