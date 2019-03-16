#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TSIZE 45
struct film {
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
typedef struct node {
	Item item;
	struct node *next;
} Node;
typedef struct list {
	Node *head;
	int size;
} List;

void init(int *item)
{
	*item = 0;
}
int newCustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return 1;

	return 0;
}
int main(void)
{
	srand((unsigned int)4414073325);
	for (int i=0; i<10; i++)
		printf("%d ",rand());

	return 0;
}
