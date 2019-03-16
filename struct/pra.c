#include <stdio.h>
#include <string.h>
#include "source.h"

extern struct month months[];
int days(char name[]);
char *s_gets(char *str, int n);
void sumDays(void);
void eatline(void);
int checkLeapYear(int year);

int main(void)
{
	sumDays();

	getchar();
	return 0;
}
void sumDays(void)
{
	
	int year, month, day;
	int sums = 0;
	printf("Enter day: ");
	scanf("%d", &day);
	eatline();
	printf("Enter month: ");
	scanf("%d", &month);
	eatline();
	printf("Enter year: ");
	scanf("%d", &year);
	eatline();
	
	if (checkLeapYear(year))
		months[1].days = 29;
	
	for (int i = 0; i < month - 1; i++)
		sums += months[i].days;
	
	sums += day;

	printf("days_sum: %d", sums);
}

int checkLeapYear(int year)
{
	int i = ((year % 4 == 0 && year % 100 != 0) ||
		year % 400 == 0) ? 1 : 0;

	return i;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
char *s_gets(char *str, int n)
{
	char *ret_val,
		 *find;

	ret_val = fgets(str,n,stdin);
	if (ret_val)
	{
		find = strchr(ret_val,'\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int days(char name[])
{
	int sums = 0,
		find = 0;
	for (int i = 0; i < 12; i++)
	{
		sums += months[i].days;

		if (!strcmp(name,months[i].name))
		{
			find = 1;
			break;
		}
	}
	
	if (find)
		return sums;

	return 0;
}
