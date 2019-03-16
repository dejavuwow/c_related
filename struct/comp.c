#include <stdio.h>
#define SIZE 10
struct book {
	char name[SIZE];
	char arr[SIZE];
};

int main(void)
{
	struct book reader;
	struct book slim;
	printf("%p\n%p", &reader, &slim);
	reader = (struct book) {
		"yes",
		"right"	
	};
	slim = (struct book) {
		.arr = "just be",
		.name = "john"
	};
	printf("%p\n%p\n", &reader, &slim);
	printf("%s", slim.name);
	getchar();

	return 0;
}
