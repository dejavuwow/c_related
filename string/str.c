#include <stdio.h>
int main(void)
{
	char *pt1 = "he is my brother";
	char ar1[] = "he is my sister";
	/* char ar2[] = {'n', 'i' , 'h','\0'}; */
	ar1[0] = 'w';
	/* ar2[0] = 'k'; */
	char scan[100];
	/* int i = scanf("%s", scan); */
	/* if (i == 1) */
		/* while(getchar() != '\n') */
			/* continue; */
	/* printf("%s", scan); */
	gets(scan);
	puts(scan);
	getchar();
	return 0;
}
