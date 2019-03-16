#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main(void)
{
	char words[] = "god is a girl";
	for (int i = 0; i < strlen(words); i++)
	{
		putchar(words[i]);
		/* Sleep(100); */
	}
	scanf("%s", words);

	getchar();
	return 0;
}
