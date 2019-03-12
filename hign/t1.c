#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t1.h"
void showMovies(Item item);
char *s_gets(char *st, int n);
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
int main(void)
{
	List movies;
	Item temp;

	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available Bye!\n");
		exit(1);
	}

	puts("Enter first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		eatline();

		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Problem allocation memory\n");
			break;
		}

		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title(empty line to stop):");
	}


	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else
	{
		puts("Here is the movies list:");
		Traverse(&movies,showMovies);
	}
	printf("Your entered %d movies.\n", ListItemCount(&movies));
	EmptyTheList(&movies);
	puts("Bye!\n");

	return 0;
}

void showMovies(Item item)
{
	printf("Movies: %s Rating %d\n", item.title, item.rating);
}

char *s_gets(char *st, int n)
{
	char *ret_val, *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;

	}

	return ret_val;
}

