#include <stdio.h>
char buf[5120]; 
int main(int argc, char const *argv[])
{
	setvbuf(stdout, buf, _IOFBF, 5120);
	int i;
	printf("333333");
	for (i = 0; i < 3; ++i)
	{
		printf("1");
		/** fflush(stdout); */
		fprintf(stderr, "2");
	}
	/** int print(void) */
	/** { */
	/**     printf("\nnkihao\n"); */
	/** } */
	/** int (*pf)(); */
	/** pf = &print; */
	/** char *first; */
	/** char tc[] = "nihao"; */
	/** printf("\n%p, %p\n", &first, first); */
	/** first = tc; */
	/** printf("%p, %p", &first, first); */

	return 0;
}
