#include <stdio.h>
#include <string.h>
struct plane_info {
	char serial_number[20];
	_Bool is_ordered;
	struct {
		char first_name[20];
		char last_name[20];
	};
};
struct flight {
	char f_number[4];
	struct plane_info seats[12];
};

static char *f_numbers[4] = {"102","311","444","519"};
void showMenu(void);
int showEmptySeatNumber(const struct plane_info item[], int cols, char mode);
int showOrderedSeatNumber(const struct plane_info item[], int cols);
void sortByAlpha(const struct plane_info item[], int cols);
void eatline(void);
void assignSeat(struct plane_info item[], int cols);
void emptyStr(char *str);
void deleteSeat(struct plane_info item[], int cols);
void showFlightNumber(struct flight items[], int size);
void oprateFlight(struct flight *item, struct flight items[]);

int main(void)
{
	 struct flight item = {
		"000",
		{
			{"M1",0,{{'\0'},{'\0'}}},
			{"A2",0,{{'\0'},{'\0'}}},
			{"J3",0,{{'\0'},{'\0'}}},
			{"L4",0,{{'\0'},{'\0'}}},
			{"P5",0,{{'\0'},{'\0'}}},
			{"K6",0,{{'\0'},{'\0'}}},
			{"G7",0,{{'\0'},{'\0'}}},
			{"U8",1,{"Jason","Siver"}},
			{"F9",1,{"Male","Loer"}},
			{"H10",1,{"Ierw","Jier"}},
			{"S11",1,{"Machael","Miliis"}},
			{"D12",1,{"Ken","Tompson"}}

		}
	};

	struct flight fitems[4];
	for (int i = 0; i < 4; i++)
	{
		fitems[i] = item;
		strcpy(fitems[i].f_number,f_numbers[i]);
	}
	showFlightNumber(fitems, 4);
	return 0;
}
void showFlightNumber(struct flight items[], int size)
{
	int inp;
	char select[4];
reset:
	puts("Please select a flight number to operate(or enter [#] to quit)");
	for (int i = 0; i < size; i++)
		printf("%s\n", f_numbers[i]);
	if ((inp = getchar()) == '#')
		return;
	ungetc(inp, stdin);
	scanf("%s",select);
	eatline();

	if (!strcmp("102",select))
		oprateFlight(&items[0],items);
	else if (!strcmp("102",select))
		oprateFlight(&items[1],items);
	else if (!strcmp("311",select))
		oprateFlight(&items[2],items);
	else if (!strcmp("444",select))
		oprateFlight(&items[3],items);
	else
	{
		puts("Invalid flight number");
		goto reset;
	}

}

void oprateFlight(struct flight *item, struct flight items[])
{
	int inp;
	showMenu();
	while ((inp = getchar()) != 'f')
	{
		getchar();
		switch (inp) 
		{
			case 'a': showEmptySeatNumber(item->seats, 12, 'a'); break;
			case 'b': showEmptySeatNumber(item->seats, 12, 'b'); break;
			case 'c': sortByAlpha(item->seats, 12); break;
			case 'd': assignSeat(item->seats, 12); break;
			case 'e': deleteSeat(item->seats, 12); break;
		}
		showMenu();
	}
	showFlightNumber(items, 4);

}

void showMenu(void)
{
	printf("To choose a function,enter its letter label:\n");
	printf("a) Show number of empty seats\n"
			"b) Show list of empty seats\n"
			"c) Show alphabetical list of seats\n"
			"d) Assign a customer to a seat assignment\n"
			"e) Delete a seat assignment\n"
			"f) Quit\n");

}

int showOrderedSeatNumber(const struct plane_info item[], int cols)
{
	_Bool haveSeat = 0;
	puts("These are numbers of ordered seats:");
	for (int i = 0; i < cols; i++)
		if (item[i].is_ordered)
		{
			haveSeat = 1;
			printf("%-10s %-1d %-10s %-s\n",
					item[i].serial_number,
					item[i].is_ordered,
					item[i].first_name,
					item[i].last_name);
		}

	if (!haveSeat)
	{
		printf("There is all empty seat.\n");
		return 0;
	}
	return 1;
}

int showEmptySeatNumber(const struct plane_info item[], int cols, char mode)
{
	int haveSeat = 0;
	puts("These are numbers of empty seats:");

	for (int i = 0; i < cols; i++)
		if (!item[i].is_ordered)
		{
			haveSeat++;
			if (mode == 'a')
				printf("%s\n", item[i].serial_number);
			else
				printf("%-10s %-1d %-10s %-s\n",
						item[i].serial_number,
						item[i].is_ordered,
						item[i].first_name,
						item[i].last_name);
		}

	if (haveSeat == cols)
	{
		printf("There is no empty seat.\n");
		return 0;
	}
	return 1;
}

void sortByAlpha(const struct plane_info item[], int cols)
{
	const struct plane_info *ptrs[cols];
	const struct plane_info *temp;

	//initial pointers
	for (int i = 0; i < cols; i++)
		ptrs[i] = &item[i];

	for (int i = 0; i < cols - 1; i++)
		for (int j = i + 1; j < cols; j++)
			if (strcmp(ptrs[i]->serial_number, ptrs[j]->serial_number) > 0)
			{
				temp = ptrs[i];
				ptrs[i] = ptrs[j];
				ptrs[j] = temp;
			}

	for (int i = 0; i < cols; i++)
		printf("%-10s %-1d %-10s %-s\n",
				ptrs[i]->serial_number,
				ptrs[i]->is_ordered,
				ptrs[i]->first_name,
				ptrs[i]->last_name);

}

void assignSeat(struct plane_info item[], int cols)
{
	char serial_number[10] = {'\0'};
	if (!showEmptySeatNumber(item, cols, 'a'))
		return;

	puts("Please select a number to assign:");

	while (scanf("%s", serial_number) == 1 && serial_number[0] != '#')
	{
		eatline();
		for (int i = 0; i < cols; i++)
			if (!strcmp(serial_number,item[i].serial_number) && !item[i].is_ordered)
			{
				item[i].is_ordered = 1;
				puts("Please enter the customer first name:");
				scanf("%s", item[i].first_name);
				eatline();
				puts("Please enter the customer last name:");
				scanf("%s", item[i].last_name);
				eatline();
			}

		if (!showEmptySeatNumber(item, cols, 'a'))
			break;

		puts("Please select a number to assign(or enter [#] to back menu):");
	}
}

void deleteSeat(struct plane_info item[], int cols)
{
	char serial_number[10] = {'\0'};
	if(!showOrderedSeatNumber(item,cols))
		return;

	puts("Please select a number to delete:");

	while (scanf("%s", serial_number) == 1 && serial_number[0] != '#')
	{
		eatline();
		for (int i = 0; i < cols; i++)
			if (!strcmp(serial_number,item[i].serial_number) && item[i].is_ordered)
			{
				item[i].is_ordered = 0;
				emptyStr(item[i].first_name);
				emptyStr(item[i].last_name);
			}

		if(!showOrderedSeatNumber(item,cols))
			break;
		puts("Please select a number to delete(or enter [#] to back menu):");
	}

}
void emptyStr(char *str)
{
	int l = strlen(str);
	for (int i = 0; i < l; i++)
		str[i] = '\0';
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
