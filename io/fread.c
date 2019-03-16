#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
int main(void)
{
	char inp[10] = "nihao232";
	FILE *fp;
	FILE *fs;
	unsigned count;
	fp = fopen("sa.txt", "r+");
	fs = fopen("fw.txt", "a+");
	count = fread(inp, sizeof(char) , 7,fp);
	rewind(fs);
	fwrite(inp, sizeof(char) * count , 1, fs);
	printf("%u", count);
	printf("\n%s",inp);
	getchar();

	return 0;
}
