#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./child.h"

extern void pt(void);
typedef struct node {
	int value;
	struct node *next;
} Node;

int insertNode(Node **linkp, int value);
extern int b;
int main(void)
{
	FILE *fp;
	fp = fopen("ay.txt", "w+x");
	if (!fp)
	{
		printf("error");
		return 0;
	}
	
	pt();
	printf("%d",b);
	int **abc(int n)
	{
		int **s;

		return s;
	}
	int **(*cbd)(int);
	printf("%d ", b);
	cbd = &abc;
	Node *root = NULL;
	insertNode(&root, 2);
	insertNode(&root, 3);
	insertNode(&root, 0);
	char test[] = "ni";
	char st[] = "haobuhao";
	printf("%d, %d, %d", root->value, root->next->value, root->next->next->value);
	/* fflush(stdout); */
	printf("%s\n", strncpy(test,st,4));
	/* print(); */

	
}

//插入节点
int insertNode(Node **linkp, int value)
{
	Node *new, *current;

	while ((current = *linkp) != NULL &&
			value > current->value)
		linkp = &current->next;

	new = (Node*)malloc(sizeof(Node));
	if (!new)
		return 0;

	new->value = value;
	new->next = current;
	*linkp = new;

	return 1;

}
