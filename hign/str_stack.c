#include <stdio.h>
typedef struct {
	int size;
	char st[21];
} Stack;
int main(void)
{
	int index = 0;
	char temp[21] = {'\0'};
	char inp;
	Stack item = {0, {'\0'}};
	puts("pease enter a string:");

	while ((inp = getchar()) != '#')
	{
		ungetc(inp, stdin);
		scanf("%20s", temp);
		while (getchar() != '\n')
			continue;
		while (temp[index] != '\0')
			index++;
		for (int i = 0; i < index; i++)
			item.st[item.size++] = temp[i];
		item.size--;
		while (item.size >= 0)
		{
			putchar(item.st[item.size]);
			item.size--;
		}
		puts("\npease enter a string:");
	}
	return 0;

}
