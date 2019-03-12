#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long int count_char(FILE *fp, char seek);

int main(int argc, char *argv[])
{
	FILE *fp;
	if (argc < 2)
	{
		puts("too few arguments,at least 2");
		exit(EXIT_FAILURE);
	}
	else if (2 == argc)
		printf("%c in %s times: %ld", argv[1][0], argv[2], count_char(stdin, argv[1][0]));
	else
	{
		for (int i = 2; i < argc; i++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr,"Can't open the file %s.\n", argv[i]);
				exit(EXIT_FAILURE);
			}
			printf("%c in %s times: %ld.\n", argv[1][0], argv[i], count_char(fp, argv[1][0]));
		}

	}
}

long int count_char(FILE *fp, char seek)
{
	long int count = 0;
	char ch;
	/* while ((ch = getc(fp)) != EOF && ch != '#' && ch == seek) */
	while ((ch = getc(fp)) != EOF && ch != '#')
		if (ch == seek)
			count++;

	return count;
}
