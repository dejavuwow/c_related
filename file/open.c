#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int main(int argc, char *argv[])
{
	FILE *f1, *f2;
	char inp[SIZE];
	char ins[SIZE];
	char *pi, *ps;
	char *find;
	if (argc < 3)
	{
		fputs("too few arguments, 3 at least:", stdout);
		exit(EXIT_FAILURE);
	}
	if ((f1 = fopen(argv[1],"r")) == NULL || (f2 = fopen(argv[2],"r")) == NULL)
	{
		fputs("Cant open the file", stderr);
		exit(EXIT_FAILURE);
	}
	while ((pi = fgets(inp, SIZE, f1)) != NULL && (ps = fgets(ins, SIZE, f2)) != NULL)
	{
		find = strchr(pi,'\n');
		*find = '\0';
		fputs(pi, stdout); 
		fputs(ps, stdout);
		putchar('\n');
	}
	do {
		fputs(pi, stdout);
	} while ((pi = fgets(inp, SIZE, f1)) != NULL);


	do {
		fputs(ps, stdout);
	} while ((ps = fgets(ins, SIZE, f2)) != NULL);

	fclose(f1);
	fclose(f2);

	return 0;
}
