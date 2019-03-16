#include <stdio.h>
#define FUNDLEN 19
struct funds {
	char bank[FUNDLEN];
	double bankfund;
};

void change_fund(struct funds *item);

int main(void)
{
	struct funds stan = {
		"just do it",
		999.92
	};
	struct funds *item = &stan;

	change_fund(item);
	printf("%f", stan.bankfund);

	getchar();
	return 0;
}

void change_fund(struct funds *item)
{
	item->bankfund += 1;
	printf("%f\n", item->bankfund);
}
