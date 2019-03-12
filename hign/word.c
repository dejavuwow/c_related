#include <stdio.h>
#include <stdlib.h>
#define LEN 20
typedef struct item {
	char words[LEN];
	struct item *left;
	struct item *right;
} Node;
typedef struct tree {
	Node *root;
	int size;
} Tree;

_Bool addItem(Tree *plist, char words[]);
Node *makeNode(void);

int main(void)
{
	Tree tree = {NULL, 0};
	Node first = {{'\0'}, NULL, NULL};

	return 0;
}

_Bool addItem(Tree *plist, char words[])
{
	Node *new = makeNode();
	strcpy(new->words, words);
	Node *scan;
	scan = plist = root;

	if (plist->root == NULL)
		plist->root = new;

	else
		while (scan != NULL)
		{
			while (toLeft(scan,new))
		}
}
static _Bool toLeft(const Node *n1, const Node *n2)
{
	int comp1;
	if (comp1 = strcmp(n1->words, n2->words) <  0)
		return true;

	return false;
}
static _Bool toRight(const Node *n1, const Node *n2)
{
	int comp1;
	if (comp1 = strcmp(n1->words, n2->words) >  0)
		return true;

	return false;
}

Node *makeNode(void)
{
	Node *new;
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	{
		fprint(stderr, "can't allow memory\n.");
		exit(EXIT_FAILURE);
	}
	new->left = NULL;
	new->right = NULL;
	return new;
}
