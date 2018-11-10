#include <stdio.h>
#include <ctype.h>
void p1(void);
void p2(void);
void p3(void);
void p4(void);
void p5(void);
void p6(void);
void p7(void);
void p8(void);
int main(void)
{
	p6();
	getchar();
	return 0;
}
void p1(void)
{
	int counts = 0;
	int inp;
	while((inp = getchar()) != EOF && ++counts)
		;
	printf("%d", counts);
	getchar();
}
void p2(void)
{
	signed char inp;
	int n_char = 0;
	while((inp = getchar()) != EOF)
	{
		n_char++;
		if (inp <= 0x20)
		{
			if (inp == 0xa)
			{
				putchar('\\');
				putchar('n');
				printf("\n");
			}
			else if (inp == 0x9)
			{
				putchar('\\');
				putchar('t');

			}
			else
			{
				putchar('^');
				putchar(inp+64);
			}
		}
		else
			putchar(inp);
		if (n_char % 10 == 0)
			printf("\n");
	}
}
void p3(void)
{
	int inp;
	int lower_counts = 0, upper_counts = 0;
	while((inp = getchar()) != EOF)
	{
		putchar(inp);
		if (islower(inp))
			lower_counts++;
		else if (isupper(inp))
			upper_counts++;
	}
	printf("lower:%d, upper:%d", lower_counts, upper_counts);
}
void p4(void)
{
	int inp,letter_counts = 0, total_counts = 0;
	char pre_char = ' ';
	_Bool symbol = 0;
	while((inp = getchar()) != EOF)
	{
		if (isalpha(inp))
			letter_counts++;
		else if (!isalpha(inp) && isalpha(pre_char))
			total_counts++;
		pre_char = inp;
	}
	printf("%d", letter_counts / total_counts);
}
void p5(void)
{
	int origin = 50;
	int user_inp = 52;
	char inp;
	int min = 0, max = 100;
	printf("is the number %d?", origin);
	while(origin != user_inp)
	{
		if (scanf("%c",&inp) == 1)
		{
			switch (inp)
			{
				case 'y':
					break;
				case 'm':
					max = origin;
					break;
				case 'l':
					min = origin;
					break;
				default:
					printf("please enter y(yes), m(more than), l(less than)):");
					continue;
			}
			getchar();
			origin = min + (max - min) / 2;
			printf("is the number %d?", origin);
		}
	}
	printf("yes!you get!");
}
void p6(void)
{

}
