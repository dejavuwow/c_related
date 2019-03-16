#include <stdio.h>
int main(void)
{
	enum {
		red = 0x1F,
		blue = 0xFFFFF
	};
	printf("red is %d size: %d\n"
			"blue is %d size: %d\n",
			red, sizeof(red), blue, sizeof(blue));
	int b = 1;
	struct {
		unsigned int autfd: 1;
		unsigned int bldfc: 10;
		unsigned int	  : 0;
		unsigned int undln: 4;
		unsigned int itals: 1;
	} prnt;
	int a = 3;
	prnt.autfd = 1;
	prnt.bldfc = 23;
	prnt.undln = 2;
	prnt.itals = 0;
	
	printf("%p %p %p",&b, &prnt, &a);
	getchar();
	return 0;
}

