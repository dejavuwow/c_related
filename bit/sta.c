#include <stdio.h>
#include <stdlib.h>
char *toBit(int num)
{
	char *bits = (char *)malloc(sizeof(char) * 9);
	/** printf("%p\n", bits); */
	for (int i = 7; i >= 0; i--, num >>= 1)
		bits[i] = (01 & num) + '0';
	bits[8] = '\0';

	return bits;
}
_Bool checkBit(int value, int addr)
{
	return value & (1 << addr);
}
int main(void)
{
	printf("%s\n", toBit(254));
	printf("%d", checkBit(8,3));

	return 0;
}

