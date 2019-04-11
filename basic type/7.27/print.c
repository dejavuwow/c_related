#include <stdio.h>
#include <inttypes.h>
int main(void)
{
	int32_t me32;
	float f1 = 4.2312;
	me32 = 45933945;
	printf("First,assume int32_t is int: ");
	printf("me32 = %d\n",me32 );
	printf("Next,let's not make any assumptions.\n");
	printf("Instead,use a \"macro\" from inttypes.h: ");
	printf("f1 = %-8.2f" "d" "\n", f1);
	getchar();
	return 0;

}