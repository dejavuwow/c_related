#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define COLS 20
#define LIMIT 3
size_t get_word(char *str);
_Bool sort_by(char option, char *str[], int rows);
void print_str(char *str[], int n);
char *s_gets(char *st, int n);
int main(void)
{
	char str_arr[LIMIT][COLS];
	char *ptstr[LIMIT];
	char option;
	int i = 0;
	while ( i < LIMIT && s_gets(str_arr[i], 20) != NULL && str_arr[i][0] != '\0' )
	{
		ptstr[i] = str_arr[i];
		i++;
	}
	do {
		printf("\nchoose you sort type:\n"
				"a): print normally					b): by asc\n"
				"c): by string length					 d): by first word length\n"
				"q): quit\n");
		while (scanf("%c",&option) != 1)
			continue;
		getchar();
	} while (sort_by(option, ptstr, LIMIT));
	getchar();

	return 0;
}

_Bool sort_by(char option, char *str[], int rows)
{
	_Bool is_continue = 1;
	switch (option) {
		case 'a':
			print_str(str, rows);
			break;

		case 'b':
			for (int i = 0; i < rows - 1; i++)
			{
				for (int j = 0; j < rows - i - 1; j++)
				{
					if (strcmp(str[j], str[j+1]) > 0)
					{
						char *temp = str[j];
						str[j] = str[j+1];
						str[j+1] = temp;
					}
				}
			}
			print_str(str, rows);
			break;

		case 'c':
			for (int i = 0; i < rows - 1; i++)
			{
				for (int j = 0; j < rows - i - 1; j++)
				{
					if (strlen(str[j]) > strlen(str[j+1]))
					{
						char *temp = str[j];
						str[j] = str[j+1];
						str[j+1] = temp;
					}
				}
			}
			print_str(str, rows);
			break;

		case 'd':
			for (int i = 0; i < rows - 1; i++)
			{
				for (int j = 0; j < rows - i - 1; j++)
				{
					if (get_word(str[j]) > get_word(str[j+1]))
					{
						char *temp = str[j];
						str[j] = str[j+1];
						str[j+1] = temp;
					}
				}
			}
			print_str(str, rows);
			break;

		case 'q':
			is_continue = 0;
			break;

		default:
			is_continue = 0;
			break;
	}

	return is_continue;
}
void print_str(char *str[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%s\n",str[i]);
}

size_t get_word(char *str)
{
	size_t i = 0;
	while (isspace(*str))
	{
		str++;
		continue;
	}
	do {
		i++;
	} while (!isspace(*++str));
	return i;
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(*st != '\n' && *st != '\0')
			st++;
		if(*st == '\n')
			*st = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
