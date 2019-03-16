#ifndef STACK_H_
#define STACK_H_
#define SIZE 20
#include <stdbool.h>
#include <stdlib.h>
typedef struct item {
	char name[SIZE];
	int age;
	struct item *next;
} Item;
typedef struct stack {
	Item *bottom;
	Item *top;
	int size;
} Stack;
bool stackIsFull(void)
{
	Item *item;
	bool full;
	item = (Item *)malloc(sizeof(Item));
	if (item == NULL)
		full = true;
	else
		full = false;
	free(item);

	return full;
}
bool stackIsEmpty(const Stack *plist)
{
	return !plist->size;
}
bool pushItem(Item n_item,	Stack *plist)
{
	Item *item;
	Item *scan;
	scan = plist->bottom;
	item = (Item *)malloc(sizeof(Item));
	if (item == NULL)
		return false;
	*item = n_item;
	if (stackIsEmpty(plist))
		plist->top = plist->bottom = item;
	else
		plist->bottom = scan->next = item;
	plist->size++;

	return true;
}
bool popItem(Stack *plist)
{
	Item *tail;
	Item *pre;
	if (stackIsEmpty(plist))
		return false;
	if (plist->size == 1)
	{
		tail = plist->bottom;
		plist->top = plist->bottom = NULL;
	}
	else {
		for (pre = plist->top, tail = pre->next; tail != plist->bottom; pre = tail, tail = tail->next)
			continue;

		pre->next = NULL;
		plist->bottom = pre;
	}
	free(tail);
	plist->size--;

	return true;
}
#endif
