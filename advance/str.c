#include <stdio.h>
#include <string.h>
extern int stra;
struct BITMAP {
	int first: 5;
	int second: 31;
	int: 0;
} item;

struct type {
	enum {YES, NO} order;
	union {
		int age;
		char first;
	} item;
};
union {
	int a;
	float b;
	char c[4];
} x = {5};
int main(void)
{
	char dest[] = "0123this me";
	printf("%s", strncat(dest, "eth",2));
	printf("\n %u", sizeof(struct BITMAP));
	struct type test;
	test.order = 3;
	test.item.age = 110;

	printf("\n%d, %d, %c", test.order, test.item.age, test.item.first);
	x.b = 34.2;
	int stra;
	printf("%d, %d", stra, 19);

	return 0;
}
