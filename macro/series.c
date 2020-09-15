#include <stdio.h>
#define STATEMENT(fun1, fun2) \
	if (0) \
{\
	fun1();\
	fun2();\
}\
else {\
puts("yes you do");\
}

void p1(void)
{
	puts("fun1");
}
void p2(void)
{
	puts("fun2");
}
int main(void)
{
	if (1)
		STATEMENT(p1, p2);
	return 0;
}
