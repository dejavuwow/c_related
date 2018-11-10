#include <stdio.h>
int main(void)
{
	int test = 212;
	int urn[5] = {100, 20, 23, 23, 23};
	int * ptr1 = urn;
	printf("%#p, %#p, %#p, %#p, %#p, %#p",urn + 1, urn + 2, ptr1, urn, &ptr1, urn+4);

	int urns[7] = {1,23,4};
	urns[7] = {2,3,4}
	printf(" %d, %d", urns, urns+2);
	getchar();
	return 0;
}
