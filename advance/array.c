#include <stdio.h>
void strcpy1(char *target, const char *source);
int main(void)
{
	int b = 123;
	char source[] = "yes you do";
	char target[10] = {'\0'};
	auto int arr[] = {10,20,30};
	int test[3][3] = {
		{1,2,8},
		{3,4},
		{5,6}
	};
	char *keyword[] = {
		"yes",
		"do",
		"something"
	};
	int matrix[][2][2] = {
		{
			{1}
		}
	};

	int *ap = arr + 2;
	/* printf("%p, %p, %p, %d, %d, %d", &b, arr, &arr, *ap, ap[-2],(-2)[ap]); */
	strcpy1(target, source);
	puts(target);
	printf("%d, %d\n", test[1][2], **(test + 1));
	/* printf("%d, %d, %d", matrix[0][0][0], matrix[0][1][1]); */
	printf("%u, %u\n", sizeof(keyword), sizeof(&b));
	int *pt = &arr[0];
	printf("%p, %c, %p ", &b, source[-2], &target[8] );
	/* printf("%p, %p, %p", arr, keyword[0], source); */
	return 0;
}
void strcpy1(char *target, const char *source)
{
	while ((*target++ = *source++) != '\0')
		;
}
