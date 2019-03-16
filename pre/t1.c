//#组合字符串，##把记号组合成标识符
#include <stdio.h>
#define SQUARE(X) (X * X)
#define PR(X) printf("The result " #X " is %d.\n",X)
#define XNAME(n) "a" #n "nihao"
#define PRINT(x, ...) printf(#x " "__VA_ARGS__)
#define MUL(x)  (x * x)
int sq(int x)
{
	return ++x * ++x;
}
int main(void)
{
	int a = 9;
	while (scanf("%d", &a) != 1)
	{
		scanf("%*s");
		printf("next");
	}
	int x = 5;
	puts(XNAME(2));
	printf("%d\n", x);
	PR(5);
	PR(x);
	PRINT(6,"%s is %d", "56", MUL(6));

	return 0;
}
