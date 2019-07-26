#include <stdio.h>
char buf[5120]; 
int main(int argc, char const *argv[])
{
	setvbuf(stdout, buf, _IOLBF, 5120);
	int i;
	for (i = 0; i < 3; ++i)
	{
		printf("1");
		fflush(stdout);
		fprintf(stderr, "2");
	}
}
