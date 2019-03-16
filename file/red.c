#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

char *s_gets(char *st, int n);
int main(void)
{
	FILE *in, *out;
	int ch;
	char source[LEN];
	char des[LEN];
	int count = 0;
	char *find;
	size_t nums;
	fputs("Please enter sorce file: ", stdout);
	s_gets(source, LEN);

	if ((in = fopen(source, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file\"%s\"\n", source);
		exit(EXIT_FAILURE);
	}

	find = strchr(source, '.');
	nums = find - source;
	strncpy(des,source, nums);
	des[nums] = '\0';
	strcat(des,".red");
	getchar();
	if ((out = fopen(des,"w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	fprintf(out, "it's a reduced file\n");
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(*st != '\n' && *st != '\0')
			st++;
		if(*st == '\n')
			*st = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
