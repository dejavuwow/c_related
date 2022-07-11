#include <time.h>
#include <stdio.h>
extern int a;
static unsigned long next = 1;
static void srand(unsigned seed);
unsigned int rand0(void)
{
	srand((unsigned int)time(0));
	next = next * 1103515245 + 12345;
	return (unsigned)(next /65536) % 32768;
}
static void srand(unsigned seed)
{
	next = seed;
}
