#include <stdio.h>
#include <math.h>
#include <stdarg.h>
/* #define NEW(X) ((X) + 5) */
#define EVEN_GT(x, y) (((x) % 2 == 0 && (x) > (y)) ? 1 : 0)
#define PR(x,y) printf(#x" is %d and " #y " is %d", x, y)
#define HL(x)\
{if ((x) > 2)\
	printf ("%d",x);\
}

#define CONS 25
#define SPACE ' '
#define PS() putchar(SPACE)
#define BIG ((x) + 3)
#define SUMSQ(x, y) ((x)*(x) + (y)*(y))
#define INFO(x) printf(#x" is %d at %#p", x, &x)
#define VAL(x) _Generic((x),\
_Bool:1,\
default:2)

int comp(const int *, const int *);
double sum(int n, ...);

int main(void)
{
	HL(10);
	PS();
	PS();
#ifndef NEW
	int a = 45;
	INFO(a);
#endif
	return 0;
}

double sum(int n, ...)
{
	va_list ap;
	va_list cp_ap;
	double sum = 0;
	
	printf("%d\n", sizeof(ap));
	va_start(ap, n);
	va_copy(cp_ap, ap);
	
	return sum;
}

int comp(const int *left, const int *right)
{
	return *left - *right;
}
// 5280 * miles
// 4 *  4 + 4
// invalid
// y = y +5
// berg = berg  + 5 * lob
// est = berg + 5 * lob + 5 / y + 5
// nilp = lob *  -(berg + 5 * lob) + 5
// #define Min(x,y) ((x) < (y) ? (x) : (y))
// (int)强制类型转换 被截断
