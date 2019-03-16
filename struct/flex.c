#include <stdio.h>
#include <stdlib.h>
struct flex {
	char name[10];
	float f1;
	double arr[];
};

int main(void)
{
	FILE *fp;
	fp = fopen("ts.txt", "w+");
	fprintf(fp,"%s, %f", "nihao ya", 25.87);
	fclose(fp);

	return 0;
}

