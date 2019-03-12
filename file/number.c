#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char words[] = " .':~*=$%#";
	char nums_str[] = "0123456789";
	char *find;
	int ch;

	fp = fopen(argv[1], "r+");
	while (!feof(fp))
	{
		ch = getc(fp);
		find = strchr(nums_str, ch);
		if (find)
		{
			char str[] = {ch,'\0'};
			ch = words[atoi(str)];
			fseek(fp, -1, SEEK_CUR);
			putc(ch, fp);
			fseek(fp, 0, SEEK_CUR);
		}
		else
			continue;
	}

	fclose(fp);
	getchar();
	return 0;
}
