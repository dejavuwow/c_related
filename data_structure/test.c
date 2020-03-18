#include <stdio.h>
typedef struct people {
	char name;
	int age;
	char is;
} People;

int abc(int x)
{
	int y = x >> 31;
	printf("&&%d\n", y);
	printf("^^%d\n",(x + y) ^ y);
	return  (x ^ y) - y;
}
int getMaxLength()
{
	
}
int main(void)
{
	int b = 25;
	char age = 0x61;
	char age2 = 13;
	int test[] = {1,2,3,4};
	int *current = test;
	/* printf("%d", ((People*)(&age))->age); */
	/* printf("\n %p, %p ,%p", &b, &age, &age2); */
	/* printf("\n %p, %p, %p", &((People*)(&age))->name, &((People*)(&age))->age, &((People*)(&age))->is); */
	/* printf("\n%d", sizeof(NULL)); */
	/* printf("%#p", *current); */
	/* printf("\n%#p", *++current); */
	printf("**%d", abc(-230));
	return 0;
}
// 115  1
//  57  1
//  28  0
//  14  0
//  7  1
//  3	1
//  1  1
I//1111 1111
//1111 1111
