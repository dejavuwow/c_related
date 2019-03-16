#include <stdio.h>
#define SIZE 9
typedef struct annular {
	int arr[SIZE];
	int head;
	int tail;
} anl;
void show_array(const struct annular *item);
_Bool add_array(struct annular *item);
_Bool shift_array(struct annular *item);

int main(void)
{
	scanf("%*d");
	fflush(stdout);
	printf("%c\n",getchar());

	anl item = {{0},0,0};
	char inp;
	show_array(&item);
	puts("Please select an option(enter [#] to quit:)");
	printf("a) add         s) shift\n");
	while ((inp = getchar()) != '#')
	{
		while (getchar() != '\n')
			continue;

		switch (inp)
		{
			case 'a': add_array(&item);break;
			case 's': shift_array(&item);break;
			default: break;
		}
		show_array(&item);
		puts("Please select an option(enter [#] to quit:)");
		printf("a) add         s) shift\n");
	}

	return 0;
}
void show_array(const struct annular *item)
{
	if (!item->head && !item->tail)
	{
		fprintf(stderr,"nothing to show.\n");
		return;
	}
	if (item->head <= item->tail)
		for (int i = item->head; i <= item->tail; i++)
			printf("%d ", item->arr[i-1]);
	else
		for (int i = item->head; i <= SIZE + item->tail; i++)
			printf("%d ", item->arr[(i-1) % SIZE]);

	putchar('\n');
}

_Bool add_array(struct annular *item)
{
	int inp;
	if (item->tail % SIZE + 1 == item->head)
	{
		fprintf(stderr,"full of queue! can't add.\n");
		return 0;
	}
	puts("Please enter an integer.");
	while (!scanf("%d",&inp))
	{
		while(getchar() != '\n')
			continue;
		puts("Please enter an integer.");
	}
	while (getchar() != '\n')
		continue;

	if (!item->tail && !item->head)
	{
		item->arr[item->head++] = inp;
		item->tail++;
	}
	else
	{
		item->tail = item->tail % SIZE + 1;
		item->arr[item->tail - 1] = inp;
	}

	printf("head: %d   tail: %d\n", item->head, item->tail);


	return 1;
}

_Bool shift_array(struct annular *item)
{
	if (!item->tail && !item->head)
	{
		fprintf(stderr,"nothing of queue!.\n");
		return 0;
	}
	item->arr[item->head - 1] = 0;

	if (item->tail == item->head)
		item->head = item->tail = 0;
	else
		item->head = item->head % SIZE + 1;

	printf("head: %d   tail: %d\n", item->head, item->tail);
	return 0;
}
