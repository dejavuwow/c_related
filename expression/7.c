#include <stdio.h>
int cube(int a);
int main(void)
{
	int target;
	printf("Please enter an integer:");
	scanf("%d", &target);
	getchar();

	cube(target);
	getchar();
	return 0;
}

int cube(int a)
{
	printf("the number's cube is %d\n", a * a * a);
	return 1;
}
