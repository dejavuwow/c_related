#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *fp;
	fpos_t pos = 20;
	char name[10];
	scanf("%s",name);
	getchar();
	printf("%s", name);
	fp = fopen(name,"w+");
	if (fp == NULL)
	{
		fputs("can't open the file!.\n", stderr);
		getchar();
		exit(EXIT_FAILURE);
	}
	/* fgetpos(fp,&pos); */
	fsetpos(fp, &pos);
	fputs("bit这将覆盖之前的内容", fp);
	printf("%u\n",sizeof(pos));
	fclose(fp);
	printf("%llu, %llu, %p",pos,pos,&pos);
	getchar();
	/* int a = 1; */
	/* long long b = 2; */
	/* printf("%p, %p, %p, %p, %u", &a, &a+1, &b, &b+1, sizeof(long)); */
	/* getchar(); */

	return 0;
})

