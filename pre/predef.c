//预定义宏和预定义标识符
#include <stdio.h>
#define SIZE "nihao"
void why_me(void);
#pragma message("nihao")
struct Test1
{
    char  c1;
    char  c2;
    short s;
};

struct Test2
{
    char  c1;
    short s;
    char  c2;
    int   i; 
};
int main(void)
{
	printf("%d, %d\n", sizeof(struct Test1), sizeof(struct Test2));
	printf("This function is %s.\n", __func__);
	why_me();
	
	return 0;
}

void why_me(void)
{
	printf("This function is %s\n", __func__);
#line 1   "cool.c"


	printf("This is line %d %s.\n", __LINE__, __FILE__);
}
