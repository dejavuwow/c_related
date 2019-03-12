#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book liabrary[MAXBKS];
	int count = 0;
	int index;
	printf("Please enter the book title.\n");
	printf("Please [enter] at the start of a line to stop.\n");

	while (count < MAXBKS && s_gets(liabrary[count].title, MAXTITL) != NULL &&
			liabrary[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(liabrary[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &liabrary[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s:$%.2f\n", liabrary[index].title,
					liabrary[index].author, liabrary[index].value);
	}
	else
		printf("No books? Too bad.\n");

	getchar();
	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st,'\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
