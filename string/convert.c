#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char t1[] = "-87jiang",
		 t2[] = "er89",
		 t3[] = "jiang";
	char *end;
	int i1 = strtoul(t1, &end, 10);
	int i2 = strtol(t1, &end, 10);
	int i3 = strtod(t1, &end);
	printf("%d, %d, %d", i1, i2, i3);
	getchar();

	return 0;
}
//10a 256+10
