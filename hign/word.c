#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define MAX 100
typedef struct item {
	int size;
	char words[LEN];
	struct item *left;
	struct item *right;
} Node;
typedef struct tree {
	Node *root;
	int size;
} Tree;
typedef struct {
	Node *parent;
	Node *child;
} Pair;
typedef struct {
	Node *arr[MAX];
	int top;
} Stack;
void push(Stack *st, Node *item)
{
	if (st->top == MAX - 1)
		return;
	st->arr[st->top++] = item;
}
Node *pop(Stack *st, void(*fun)(const Node *item))
{
	if (st->top == 0)
		return NULL;
	Node *temp = st->arr[--st->top];
	(*fun)(temp);
	return temp;
}
void showWord(const Node *item)
{
	printf("%s: %d\n", item->words, item->size);
}
static _Bool toLeft(const Node *n1, const Node *n2);
static _Bool toRight(const Node *n1, const Node *n2);
void addItem(Tree *plist, char words[]);
void showItem(const Node *item);
void showStatistic(Tree *plist);
Node *makeNode(void);

int main(void)
{
	FILE *fp;
	char word[LEN];
	Tree tree = {NULL, 0};
	puts("Please enter file name:");
	scanf("%s", word);
	getchar();
	fp = fopen(word, "r+");
	int n;
	while ((n = fscanf(fp,"%20s",word)) == 1)
		addItem(&tree, word);

	/* showItem(tree.root); */
	showStatistic(&tree);

	return 0;
}
void showStatistic(Tree *plist)
{
	Node *scan = plist->root;
	Stack stack;
	stack.top = 0;

	while (1)
	{
		while (scan != NULL)
		{
			push(&stack, scan);
			scan = scan->left;
		}
		do {
			if (stack.top == 0) return;
			scan = pop(&stack, showWord)->right;
		} while (scan == NULL);
		
	}
}
void showItem(const Node *item)
{
	if (item == NULL)
		return;
	printf("%s: %d\n", item->words, item->size);

	showItem(item->left);
	showItem(item->right);
}

void addItem(Tree *plist, char words[])
{
	Pair pair;
	pair.parent = NULL;
	Node *new = makeNode();
	strcpy(new->words, words);
	pair.child = plist->root;

	if (plist->root == NULL)
		plist->root = new;

	else
		while (pair.child != NULL)
		{
			if (toLeft(new, pair.child))
			{
				pair.parent = pair.child;
				if (pair.child->left == NULL)
				{
					pair.child->left = new;
					break;
				}
				pair.child = pair.child->left;
			}
			else if (toRight(new, pair.child))
			{
				pair.parent = pair.child;
				if (pair.child->right == NULL)
				{
					pair.child->right = new;
					break;
				}
				pair.child = pair.child->right;
			}
			else
			{
				pair.child->size++;
				break;
			}
		}

}
static _Bool toLeft(const Node *n1, const Node *n2)
{
	int comp1;
	if (comp1 = strcmp(n1->words, n2->words) <  0)
		return 1;

	return 0;
}
static _Bool toRight(const Node *n1, const Node *n2)
{
	int comp1;
	if (comp1 = strcmp(n1->words, n2->words) >  0)
		return 1;

	return 0;
}

Node *makeNode(void)
{
	Node *new;
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	{
		fprintf(stderr, "can't allow memory\n.");
		exit(EXIT_FAILURE);
	}
	new->size = 1;
	new->left = NULL;
	new->right = NULL;
	return new;
}
