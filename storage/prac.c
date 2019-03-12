#include <stdio.h>
int Global;
void print(void);
int main(void)
{
	/* extern int Global; */
	/* Global = 979; */
	int i1 = 2147483647;
	i1 = i1 + 2L;
	printf("%ld", i1);
	getchar();
	return 0;
}
void print(void)
{

	Global = 439;
	printf("%10d", Global);

}
