#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct char_item{
	char value;
	struct char_item *next;
} char_pt;

typedef struct {
	int n_value;
	char_pt *start;
	char_pt *end;
} char_chain;

static int pushItem(char_chain *chain, char_pt *new)
{
	if (chain->n_value == 0)
		chain->start = new;
	else
		chain->end->next = new;
	chain->end = new;
	chain->n_value++;

	return 0;
}

int fun1(int a)
{
	return ++a;
}
float fun2(float b)
{
	return ++b;
}
#define MUL(x) _Generic((x),\
int: fun1,\
float: fun2,\
default: fun2\
)(x)
int fibonacci(int index)
{
	int pre = 1,
		ppre = 1;
	int temp;
	while (index-- > 2)
	{
		temp = ppre;
		ppre = pre;
		pre = pre + temp;
	}
	return pre;
}

int cb(const char a)
{
	return a;
}
int find_max(int array[10])
{
	int i;
	int max = array[0];
	for (i = 1; i < 10; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
void my_printf(const char *format,...)
{

	char_chain origin = {0, NULL, NULL};

	va_list var_arg;
	int count;
	char_pt *temp;

	for (const char *start = format; *start != '\0'; start++)
	{
		if (*start == '%')
		{
			temp = (char_pt*)malloc(sizeof(char_pt));
			temp->next = NULL;

			switch (*(start+1))
			{
				case 'd':
					temp->value = 'd';
					pushItem(&origin, temp);
					break;
				case 'f':
					temp->value = 'f';
					pushItem(&origin, temp);
					break;
				case 's':
					temp->value = 's';
					pushItem(&origin, temp);
					break;
				case 'c':
					temp->value = 'c';
					pushItem(&origin, temp);
					break;
				default:
					free(temp);
					break;
			}
		}
	}
	va_start(var_arg, format);
	char *temp1;
	const char *c_start;
	char_pt *start;
	for (c_start = format, start = origin.start; *c_start != '\0'; c_start++)
	{
		if (*c_start != '%')
			putchar(*c_start);
		else
		{
			switch(start->value)
			{
				case 'd':
					printf("%d", va_arg(var_arg, int));
					break;
				case 'f':
					printf("%f", va_arg(var_arg, double));
					break;
				case 's':
					for (temp1 = va_arg(var_arg, char*); *temp1 != '\0'; temp1++)
					{
						putchar(*temp1);
					}
					break;
				case 'c':
					putchar(va_arg(var_arg, int));
					break;

			}
			c_start++;
			start = start->next;
		}

	}

}
int main(void)
{
	enum unique {OFF, ON};
	enum unique d;
	printf("%d, %f\n", MUL(2), MUL(2.5));
	for (int i = 3; i < 10; i++)
		printf("%d\n", fibonacci(i));
	printf("%d\n", find_max((int[]){1,2,3,4,5,6,7,8,9,10}));
	my_printf("%d i am you %s  dont %c  %f", 89, "just", 'P', 89.23);
	return 0;
}

