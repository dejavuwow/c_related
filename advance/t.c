#include <float.h>
#include <stdio.h>
static int *b;
int main(void)
{
	int *a;
	printf("%d, %d , %d, %d\n", a, b, NULL, b == NULL);
	/* enum {PENNY = 1, NICKL = 5}; */
	/* double df = 2.23411232; */
	/* float f1 = df; */
	/* printf("%d\n", FLT_MANT_DIG); */
	/* printf("%f\n", FLT_MAX); */
	// printf("%f\n", FLT_MIN);
	int as = 123;
	enum Liquid { OUNCE = 1, CUP = 8, PINT = 16, QUART = 32, GALLON
	 = 128 };
	enum Liquid jar;
	jar = QUART;
	struct box_propx {
		unsigned long long int opque: 33;
		unsigned long long int: 0;
	};
	char *somedday;
	printf("%d, %d\n", (int)(as >= 123)+(int)(as < 123), somedday);
	/* switch (as) */
	/* { */
		/* case (int)(as >= 100): */
			/* printf("greater than 100"); */
			/* break; */
		/* case (int)(as < 100): */
			/* printf("less than 100"); */
			/* break; */
	/* } */
	/* printf("%u \n %d", sizeof(struct box_propx), a); */
	// printf("%d\n", jar);
	// jar = as;
	// printf("%d\n", jar);

	return 0;
}
