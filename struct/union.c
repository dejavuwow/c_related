#include <stdio.h>

int main(void)
{
	union item {
		char temp[18];
		float f1;
		double b3;
	};

	union item book = {.b3 = 34.23};
	union item book2 = {"do"}; 
	union item book3;
	book3.f1 = 34.2;

	printf("%p\n%p\n%p",&book, &book2, &book3);
	getchar();
	return 0;
}
