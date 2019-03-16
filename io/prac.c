#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);

int main(int argc, char *argv[])
{
	FILE *fa, *fs; //fa指向目标文件，fs指向源文件
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	int ch;

	if ((fa = fopen(argv[1], "ab+")) == NULL)
	{
		fprintf(stderr,"Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	for ( int i = 2; i < argc; i++)
	{
		if (strcmp(argv[1],argv[i]) == 0)
			fputs("Can't append file to itself\n", stderr);
		else if ((fs = fopen(argv[i],"rb")) == NULL)
			fprintf(stderr,"Can't open %s\n", argv[i]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n", argv[1]);
			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
			puts("Next file (empty line to quit):");
		}
	}
	printf("Done appending. %d files appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);
	getchar();

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}

char *s_gets(char *st, int n)
{
	char *ret_val, *find;

	ret_val = fgets(st,n,stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
