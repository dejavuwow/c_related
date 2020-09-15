#include <stdio.h>


int main(void)
{
	struct mpl {
		int age;
		void *data;
	};

	struct mpl test;
	test.age = 10;
	test.data = 123;

	return 0;
}
