#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);
int main(void)
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	puts(bin_str);
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numberic input terminates program.");
	while (scanf("%d", &number) == 1)
	{
		itobs(number, bin_str);
		printf("%d is %s\n", number, bin_str);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Bye!");

	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	
	puts(ps);
	return ps;
}

void show_bstr(const char * str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');

	}
}
//00001111
//10110110
//10111001 138  -118
//				128+64+32+2
//				-30
