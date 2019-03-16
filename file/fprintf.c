#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	if ((fp = fopen("wordy","a+")) == NULL)
	{
		fprintf(stdout,"Cant't open \"wordy\"file.\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file;");
	puts("Press the # key at the beginning of a line to terminate");
	while ((fscanf(stdin,"%40s",words) == 1))
		fprintf(fp,"%s\n",words);
	getchar();
	puts("File contents:");
	rewind(fp);
	/* while (fscanf(fp, "%f",words) == 1) */
		/* puts(words); */
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr,"Error closing file\n");
	getchar();
	return 0;
}
/* 多个优惠券: */
/* /#/list?merchantId=xxxxxxx */
/* 单张优惠券 */
/* /#/detail?couponId=xxxxxxx */
//凯哥，我，班长，球，liang，赵
