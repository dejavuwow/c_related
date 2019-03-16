#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
char *s_gets(FILE *fp, char *str, int size);

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[MAX];
	fp = fopen(argv[2], "r");

	while (!feof(fp))
		if(s_gets(fp,line, MAX) && strstr(line, argv[1]))
			puts(line);

	fclose(fp);
	getchar();
	return 0;
}

char *s_gets(FILE *fp, char *str, int size)
{
	char *find;
	char *ret_val;
	ret_val = fgets(str,size,fp);
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
