#include <stdio.h>
#include <string.h>
int main(void)
{
	char t1[] = "yes ";
	char t2[] = "mytest";

	strncat(t1, t2,7);
	puts(t1);
	/*  char test[6] = {[5] = '\0'}; */
	/* for (int i = 0; i < 5; i++) */
	/* test[i] = getc(stdin); */

	/* while (getc(stdin) != '\n') */
	/* continue; */

	/* puts(test); */
	/* for (int i = 0; i < 5; i++) */
	/* putc(test[i],stdout); */
	getc(stdin);

	return 0;
}

