#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char dTs[][10] = {
	"",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};
enum Bill {
	MILLION = 1000000,
	THOUSAND = 1000,
	HUNDRED = 100,
	NINETY = 90,
	EIGHTY = 80,
	SEVENTY = 70,
	SIXTY = 60,
	FIFTY = 50,
	FORTY = 40,
	THIRTY = 30,
	TWENTY = 20,
	NIGHTEEN = 19,
	EIGHTEEN = 18,
	SEVENTEEN = 17,
	SIXTEEN = 16,
	FIFTEEN = 15,
	FOURTEEN = 14,
	THIRTEEN = 13,
	TWELVE = 12,
	ELEVEN = 11,
	TEN = 10,
	NINE = 9,
	EIGHT = 8,
	SEVENT = 7,
	SIX = 6,
	FIVE = 5,
	FOUR = 4,
	THREE = 3,
	TWO = 2,
	ONE = 1

};
void written_amount(unsigned int amount, char *buffer);
void hundredToStr(unsigned int number, char *temp);
void dozenToStr(unsigned int number, char *temp);

int main(void)
{
	unsigned int value;
	char inp;
	char buffer[80] = {'\0'};

	printf("Enter you number: ");
	while (scanf("%d", &value) == 1)
	{
		getchar();
		memset(buffer,'\0', 80);
		written_amount(value, buffer);
		printf("%s\n", buffer);
		printf("Enter you number(enter # to end): ");
	}
}
void dozenToStr(unsigned int number, char *tail)
{
	int digit;
	if (number > 99)
	{
		fputs("number cant be greater than 99", stderr);
		return;
	}
	else
	{
		if (number >= 20)
		{
			digit = number / TEN;
			switch (digit)
			{
				case 9:
					strcpy(tail, "NINETY");
					break;
				case 8:
					strcpy(tail, "EIGHTY");
					break;
				case 7:
					strcpy(tail, "SEVENTY");
					break;
				case 6:
					strcpy(tail, "SIXTY");
					break;
				case 5:
					strcpy(tail, "FIFTY");
					break;
				case 4:
					strcpy(tail, "FORTY");
					break;
				case 3:
					strcpy(tail, "THIRTY");
					break;
				case 2:
					strcpy(tail, "TWENTY");
					break;
			}
			digit = number % TEN;
			switch (digit)
			{
				case 9:
					strcat(tail, "-NINE");
					break;
				case 8:
					strcat(tail, "-EIGHT");
					break;
				case 7:
					strcat(tail, "-SEVEN");
					break;
				case 6:
					strcat(tail, "-SIX");
					break;
				case 5:
					strcat(tail, "-FIVE");
					break;
				case 4:
					strcat(tail, "-FOUR");
					break;
				case 3:
					strcat(tail, "-THREE");
					break;
				case 2:
					strcat(tail, "-TWO");
					break;
				case 1:
					strcat(tail, "-ONE");
					break;
			}

		}
		else {
			switch (number)
			{
				case 19:
					strcpy(tail, "NIGHTEEN");
					break;
				case 18:
					strcpy(tail, "EIGHTEEN");
					break;
				case 17:
					strcpy(tail, "SEVENTEEN");
					break;
				case 16:
					strcpy(tail, "SIXTEEN");
					break;
				case 15:
					strcpy(tail, "FIFTEEN");
					break;
				case 14:
					strcpy(tail, "FOURTEEN");
					break;
				case 13:
					strcpy(tail, "THIRTEEN");
					break;
				case 12:
					strcpy(tail, "TWELVE");
					break;
				case 11:
					strcpy(tail, "ELEVEN");
					break;
				case 10:
					strcpy(tail, "TEN");
					break;
				case 9:
					strcpy(tail, "NINE");
					break;
				case 8:
					strcpy(tail, "EIGHT");
					break;
				case 7:
					strcpy(tail, "SEVEN");
					break;
				case 6:
					strcpy(tail, "SIX");
					break;
				case 5:
					strcpy(tail, "FIVE");
					break;
				case 4:
					strcpy(tail, "FOUR");
					break;
				case 3:
					strcpy(tail, "THREE");
					break;
				case 2:
					strcpy(tail, "TWO");
					break;
				case 1:
					strcpy(tail, "ONE");
					break;
			}
		}

	}
}
void hundredToStr(unsigned int number, char *temp)
{
	if (number > 999)
	{
		fputs("number cant be greater than 999", stderr);
		return;
	}
	int hundredDigit = number / 100;
	int remain = number % 100;
	char tail[20] = {'\0'};
	char front[20] = {'\0'};
	if (hundredDigit)
	{
		strcpy(front, dTs[hundredDigit]);
		strcat(front, " HUNDRED ");
	}
	dozenToStr(remain, tail);
	strcpy(temp, front);
	strcat(temp, tail);

}
void written_amount(unsigned int amount, char *buffer)
{
	int million,
		thousand,
		hundred,
		dozen,
		digit;

	char tail[20] = {'\0'};
	char mil_txt[50] = {'\0'};
	char th_txt[30] = {'\0'};
	char hun_txt[20] = {'\0'};

	int remain;

	million = amount / MILLION;
	thousand = (remain = amount % MILLION) / THOUSAND;
	hundred =  (remain = remain % THOUSAND) / HUNDRED;
	remain = remain % HUNDRED;
	hundredToStr(million, mil_txt);
	hundredToStr(thousand, th_txt);
	hundredToStr(hundred, hun_txt);
	dozenToStr(remain, tail);

	if (mil_txt[0] != '\0')
	{
		strcpy(buffer, mil_txt);
		strcat(buffer, " MILLION ");
	}
	if (th_txt[0] != '\0')
	{
		strcat(buffer, th_txt);
		strcat(buffer, " THOUSAND ");
	}
	if (hun_txt[0] != '\0')
	{
		strcat(buffer, hun_txt);
		strcat(buffer, " HUNDRED ");
	}
	if (tail[0] != '\0')
	{
		strcat(buffer, tail);
	}
}
