#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

int main(void)
{
	char file[SLEN];
	char ch;
	FILE *fp;
	long count,last;

	puts("Enter the name of the file to be processed:");
	scanf("%80s",file);
	if ((fp = fopen(file,"rb")) == NULL)
	{
		printf("reverse can't open %s\n",file);
		exit(EXIT_FAILURE);
	}
	getchar();
	fseek(fp,0L,SEEK_END);
	last = ftell(fp);
	for (count = 0L; count <= last; count++)
	{
		fseek(fp,count,SEEK_SET);
		ch = getc(fp);
		if (ch != CNTL_Z && ch != '\r')
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	getchar();
	return 0;
}
