#include <stdio.h>
#include <ctype.h>
int position(int x);
void to_base_n(int x, int y);
void Fibonacci(int x);
void fibonacci(unsigned int n);
int main(void)
{	
	int inp;
	while (scanf("%d", &inp) == 1)
		fibonacci(inp);
	getchar();
	return 0;
}
int position(int x)
{
	if (isalpha(x))
	{
		int index = tolower(x);
		index = index - 0x60;
		return index;
	}
	else
		return -1;
}
void to_base_n(int x, int y)
{
	int quotient = x / y;
	int remainder = x % y;
	if (quotient != 0)
		to_base_n(quotient, y);
	printf("%d", remainder);
}

void Fibonacci(int x)
{
	int o = 1;
	int s = 1;
	int sum = 1;
	while (x > 2 )
	{
		sum = o + s;
		o = s;
		s = sum;
		x--;
	}
	printf("%d",sum);

}

void fibonacci(unsigned int n)
{
    int fib1 = 1;
    int fib2 = 1;

    printf("%d, %d", fib1, fib2);

    for (size_t i = 0; (i = (fib1 + fib2)) < n;)
    {
        printf(", %d", i);
        fib1 = fib2;
        fib2 = i;
    }

    putchar('\n');
    return;
}
