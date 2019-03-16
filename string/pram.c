#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 10
char *get_str(char str_arr[], int n);
char *get_word(char word[], int n);
char *sch_str(char *str, char tar);
bool is_within(char *str, char tar);
char *mystrncpy(char *des, const char *src, size_t n);
char *string_in(const char *str, const char *tar);
char *str_reverse(char *str);
char *no_space(char *str);
char *s_gets(char *inp, int n);
int main(void)
{
	char tar[20];
	while (true) {
		s_gets(tar, 19);
		printf("%s", no_space(tar));
		getchar();
	}
	getchar();

	return 0;
}
char *s_gets(char *inp, int n)
{
	char *ret_val;
	ret_val = fgets(inp, n, stdin);
	if (ret_val)
	{
		char *find = strchr(inp, '\n');
		if (find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
char *get_str(char str_arr[], int n)
{
	int i = 0;
	char inp;
	while(i <= n && (inp = getchar()) != ' ')
	{
		str_arr[i] = inp;
		i++;
	}
	return str_arr;
}
//3,4
char *get_word(char word[], int n)
{
	int i = 0;
	char inp;
	while (isspace(inp = getchar()))
		continue;
	do {
		word[i] = inp;
		i++;
	}
	while (!isspace(inp = getchar()) && i < n);
	while (inp != '\n')
	{
		inp = getchar();
		continue;
	}
	word[i] = '\0';
	return word;
}
//5
char *sch_str(char *str, char tar)
{
	while (*str && tar != *str)
	{
		str++;
		continue;
	}
	if(!*str)
		return NULL;
	else
		return str;

}
bool is_within(char *str, char tar)
{
	while (*str && tar != *str)
	{
		str++;
		continue;
	}
	if(!*str)
		return false;
	else
		return true;

}
//7
char *mystrncpy(char *des, const char *src, size_t n)
{
	char *origin = des;
	while (n && *src)
	{
		*des = *src;
		des++;
		src++;
		n--;
	}
	do {
		*des = '\0';
		des++;
	} while (n--);

	return origin;
	
}
//8
char *string_in(const char *str, const char *tar)
{
	char *first = strchr(str, *tar);
	char *const origin = first;
	if (!first)
		return NULL;
	while (*tar)
	{
		if (*tar++ != *first++)
			return NULL;
	}
	return origin;
	
}
//9
char *str_reverse(char *str)
{
	int SIZE = strlen(str);
	for (int i = 0; i < SIZE / 2; i++)
	{
		char temp = str[i];
		str[i] = str[SIZE - i - 1];
		str[SIZE - i- 1] = temp;
	}
	return str;
}
//10
char *no_space(char *str)
{
	char *find;
	while (find = strchr(str, ' '))
		strcpy(find,find + 1);
	return str;
}
//11
void sort_by(char option, char **str_arr)
{
	switch (option)
	{
		case 'a':
			for (int i = 0; i < SIZE; i++)
				printf("%s", str_arr[i]);
			break;
		case 'b':
			for (int i = 0; i < SIZE; i++)
			{
				if (strcmp(str_arr[i], str_arr[i+1]) > 0)
				{

						char *temp = str_arr[i] = 
				}
			}

	}
}

