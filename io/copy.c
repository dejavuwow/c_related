#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 4096
char *s_gets(char *st, int n);
/* void append(FILE *source, FILE *dest); */
int main(void)
{
	FILE *fp;
	FILE *fs;
	char file_name[40];
	fpos_t pos = 1;
	char read;
	char change;
	fputs("Please enter the file name: ", stdout);
	s_gets(file_name, 40);
	fp = fopen(file_name, "r+");
	/* fs = fopen(file_name, "r+"); */
	/* fseek(fp, 2, SEEK_CUR); */
	while((read = getc(fp)) && !feof(fp))
	{
		fseek(fp, -1, SEEK_CUR);
		change = toupper(read);
		putc(change,fp);
		fseek(fp, 0, SEEK_CUR);
		/* change = toupper(read); */
		/* putc(change, fp); */
	}
	fclose(fp);
	getchar();

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

/* int main(int argc, char *argv[]) */
/* { */
	/* FILE *fa; */
	/* FILE *fs; */
	
	/* if ((fa = fopen(argv[2],"wb")) == NULL) */
	/* { */
		/* fprintf(stderr,"Can't open %s\n", argv[2]); */
		/* exit(EXIT_FAILURE); */
	/* } */
	/* setvbuf(fa, NULL, _IOFBF, BUFSIZE); */
	/* if ((fs = fopen(argv[1], "rb")) == NULL) */
	/* { */
		/* fprintf(stderr,"Can't open %s\n", argv[1]); */
		/* exit(EXIT_FAILURE); */
	/* } */
	/* setvbuf(fs, NULL, _IOFBF, BUFSIZE); */
	/* append(fs, fa); */
	/* fclose(fs); */
	/* fclose(fa); */

	/* getchar(); */
	/* return 0; */
/* } */
/* void append(FILE *source, FILE *dest) */
/* { */
	/* size_t bytes; */
	/* static char temp[BUFSIZE]; */

	/* while ((bytes = fread(temp, sizeof(char) * BUFSIZE , 1, source)) > 0) */
		/* fwrite(temp, sizeof(char), bytes, dest); */
/* } */
