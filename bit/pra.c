#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct info {
	unsigned int id: 8;
	unsigned int size: 7;
	unsigned int: 1;
	unsigned int align: 2;
	unsigned int bold: 1;
	unsigned int italic: 1;
	unsigned int: 4;
};

enum {left, center, right};
enum {off, on};
static char *align[] = {"left", "center", "right"},
			*switchs[] = {"on", "off"};

int strToNum(const char *str);
int strToNum1(const char *str);
int openSize(int num);
char *toBit(int num);
_Bool checkBit(int value, int addr);
int rotateNum(unsigned int value ,int size);
void print(unsigned long info);
char getOptions(void);

int main(int argc, char *argv[])
{
	printf("this ju\
st for me.\n");
	struct info stuff;
	char option;
	// unsigned int size;
	char inp;

	unsigned long item = 0x27efc;
	unsigned short id = 0;
	unsigned short size = 0;
	enum {left = 0x00000, center = 0x10000, right = 0x20000};
	// enum bold  {off = 0x00000, on = 0x40000};
	// enum italic {off =0x00000, on = 0x80000};
	int mask = 0x000007F00;

	// stuff = (struct info) {1, 12, left, off, off};
	// printf("%u, %u\n", sizeof(stuff.bold), sizeof(stuff.italic));

	print(item);
	while ((option = getOptions()) != 'q')
	{
		switch(option)
		{
			case 'f':
				printf("Enter font size (0-127):");
				scanf("%hu", &size);
				item &= 0xFFFFFFFFFFFF80FF;
				size <<= 8;
				size &= mask;
				item |= size;
				getchar();
				break;
			case 'a':
				printf("Select alignment:\n");
				printf("l) left   c) center   r)right\n");
				item &= 0xFFFFFFFFFFFCFFFF;
				switch((inp = getchar()))
				{
					case 'l':
						item |= left;
						break;
					case 'c':
						item |= center;
						break;
					case 'r':
						item |= right;
						break;
				}
				getchar();
				break;
			case 'i':
				item ^= 0x80000;
				break;

		}	
		print(item);
	}

	return 0;
}
void print(unsigned long info)
{
	printf("%4s %4s %8s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", " B ", " I ");
	printf("%4u %4u %8s %3s %3s\n", 0xFF & info, (0x7F00 & info) >> 8, align[(0x30000 & info) >> 16], switchs[(0x40000 & info) >> 18], switchs[(0x80000 & info) >> 19]);

}
char getOptions(void)
{
	printf("Please enter key to choose an option:\n");
	printf("f) change font    s) change size    a) change alignment\n");
	printf("b) toggle bold    i) toggle italic  q) quit");
	char inp = getchar();
	getchar();
	return inp;
}

int rotateNum(unsigned int value ,int size)
{
	int bit_value;
	while (size--)
	{
		bit_value = checkBit(value, 31);
		value <<= 1;
		value |= bit_value;
	}
	return value;
}

int strToNum(const char *str)
{
	int num = 0;
	while (*str)
	{
		num <<= 1;
		num |= *str++ - '0';
	}
	return num;
}
_Bool checkBit(int value, int addr)
{
	return value & (1 << addr);
}

int openSize(int num)
{
	int i = 1;
	int sizeInt = 8 * sizeof(int);
	int size = 0;
	for (int j = 0; j < sizeInt - 1; j++, num >>= 1)
		if ((i & num ))
			size++;

	return size;

}
int strToNum1(const char *str)
{

	int val = 0;
	while (*str != '\0')
	{
		val = 2 * val + (*str++ - '0');
	}
	return val;
}

char *toBit(int num)
{
	char *bits = (char *)malloc(sizeof(char) * 9);
	for (int i = 7; i >= 0; i--, num >>= 1)
		bits[i] = (01 & num) + '0';
	bits[8] = '\0';
	return bits;
}
/* struct { */
/* unsigned int disk: 2; */
/* unsigned int: 1; */
/* unsigned int cr: 2; */
/* unsigned int: 1; */
/* unsigned int sd: 2; */
/* } stuff; */

