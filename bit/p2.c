#include <stdio.h>

int main(void)
{

}

int switchBits(int num, int bits)
{
	int mask = 0;
	int util = 1;
	while (bits--);
	{
		mask |= util;
		util <<= 1;
	}
}
