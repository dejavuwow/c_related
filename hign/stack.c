#include <stdio.h>
#include "stack.h"
void showMenu(void)
{
	printf("Enter your option:\n ");
	printf("a) add			d) delete\n");
}
void showList(Stack *plist)
{
	Item *scan;
	for (scan = plist->top; scan != NULL; scan = scan->next)
		printf("name: %s, age: %d\n", scan->name, scan->age);
	printf("size: %d\n", plist->size);
}
int main(void)
{
	Item new = { "Lipi", 24, NULL};
	Stack plist = {NULL, NULL, 0};
	char inp;

	showMenu();
	while ((inp = getchar()) != '#')
	{
		while (getchar() != '\n')
			continue;

		switch (inp)
		{
			case 'a':
				pushItem(new, &plist);
				break;
			case 'd':
				popItem(&plist);
				break;
			default: break;
		}
		showList(&plist);
		showMenu();
	}

	return 0;
}

