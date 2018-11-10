#include <stdio.h>
#define SPACE ' '
int main(void)
{
	char arr[6];
	int origin;
	for (origin = 0; origin < 5; origin++)
	{
		scanf("%c", &arr[origin]);
	}
	arr[5] = '\0';
	getchar();
	printf("%s", arr);
	getchar();

}