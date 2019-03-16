#include <stdio.h>
void say1(void)
{
	puts("sorry");
}

void say2(void)
{
	puts("good bye");
}
void say3(void)
{
	puts("just for fun");
}
void say4(void)
{
	puts("keep it in your eyes");
}

void run(void(*ptr)(void))
{
	(*ptr)();
}

int main(void)
{
	int s;
	void (*ptr[4])(void) = {say1, say2, say3, say4};
	printf("a) one\n"
		   "b) two\n"
		   "c) three\n"
		   "d) five");
	while ((s = getchar()) != '#')
	{
		switch (s)
		{
			case 'a':
				run(ptr[0]);
				break;
			case 'b':
				run(ptr[1]);
				break;
			case 'c':
				run(ptr[2]);
				break;
			case 'd':
				run(ptr[3]);
				break;
		}
	}

	return 0;

}


