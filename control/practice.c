#include <stdio.h>
#include <string.h>
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
void p1(void);
void p2(void);
void p3(void);
void p4(void);
void p5(void);
void p6(void);
void p7(void);
int p8(void);
void p9(void);
void pa(void);
void pb(void);
int main(void)
{
	pb();
	getchar();
	return 0;
}

void p1(void)
{
	char inp;
	int letter = 0,  space = 0, line = 0;
	while ((inp = getchar()) != '#')
	{
		if (inp == ' ')
			space++;
		else if (inp == '\n')
			line++;
		else
			letter++;
	}
	getchar();
	printf("space:%d, line:%d, letter:%d", space, line, letter);
}

void p2(void)
{
	char inp;
	int counts = 0;
	while ((inp = getchar()) != '#')
	{	
		if (inp == '\n')
			continue;
		counts++;
		printf("%c-%d\n", inp, inp);
		if (counts % 8 == 0) {
			putchar('\n');
		}
	}
}
void p3(void)
{
	int even_letters = 0,
	inp = 0,
	odd_letters = 0;

	float even_sum = 0.f,		
	odd_sum =0.f;

	while(scanf("%d", &inp) == 1 && inp != 0)
	{
		if (inp % 2 == 0) {
			even_letters++;
			even_sum += inp;
		} else {
			odd_letters++;
			odd_sum += inp;
		}
	}
	getchar();
	printf("even_letters:%d, even_average:%f. "
		"odd_letters:%d, odd_average:%f. \n", even_letters, even_sum / even_letters,
		odd_letters, odd_sum / odd_letters);
}

void p4(void)
{
	int replace = 0;
	char inp;
	while ((inp = getchar()) != '#')
	{
		if ('.' == inp) {
			putchar('!');
			replace++;
		} 
		else if ('!' == inp) {
			putchar('!');
			putchar('!');
			replace++;
		} 
		else {
			putchar(inp);
		}
	}
	getchar();
	printf("replace_counts:%d\n", replace);
}

void p5(void)
{
	int replace = 0;
	char inp;
	while ((inp = getchar()) != '#')
	{
		switch (inp) {
			case '.':
			putchar('!');
			replace++;
			break;

			case '!':
			putchar('!');
			putchar('!');
			replace++;
			break;

			default:
			putchar(inp);
		}
	}
	getchar();
	printf("replace_counts:%d\n", replace);
}
void p6(void)
{
	int counts = 0;
	char inp, inp_pre;
	while ((inp = getchar()) != '#')
	{
		if (inp == 'i' && inp_pre == 'e') {
			counts++;
		}
		inp_pre = inp;
	}
	getchar();
	printf("%d\n", counts);
}

void p7(void)
{
	int hours = 0;
	double pay = 10.00, total = 0, tax = 0, income = 0;
	printf("Please enter hours:");
	while (scanf("%d", &hours) == 1)
	{
		if (hours <= 40) {
			total = pay * hours;
			tax = total <= 300
			? total * RATE1
			: 300 * RATE1 + (total - 300) * RATE2;
		}
		else {
			total = 400 + (hours - 40) * 1.5 * pay;
			tax = total <= 450
			? 300 * RATE1 + (total - 300) * RATE2
			: 300 * RATE1 + 150 * RATE2 + (total - 450) * RATE3;
		}
		income = total - tax;
		getchar();
		printf("total:%.2f$, tax:%.2f$, income:%.2f$\n", total, tax, income);
		printf("Please enter hours:");
	}

}
int p8(void)
{
	int hours = 0, option = 0;
	double pay = 0, total = 0, tax = 0, income = 0;
	printf("*********************************************************\n\n");
	printf("Enter the number correspponding to the desired pay rate to action:\n\n");
	printf("1) $5.75/hr                            2) $9.33/hr\n\n");
	printf("3) $10.00/hr                           4) $11.20/hr\n\n");
	printf("5) quit\n\n");
	printf("*********************************************************\n\n");
	printf("you pick:");
	scanf("%d", &option);
	getchar();

	switch (option) {

		case 1:
		pay = 5.75;
		break;

		case 2:
		pay = 9.33;
		break;

		case 3:
		pay = 10.00;
		break;

		case 4:
		pay = 11.20;
		break;

		case 5:
		return 0;
	}

	printf("ok,please enter hours now:");

	while (scanf("%d", &hours) == 1)
	{
		hours = hours <= 40 ? hours : 40 + (hours - 40) * 1.5;
		total = hours * pay;
		if (total <= 300)
			tax = total * RATE1;
		else if (total <= 450)
			tax = 300 * RATE1 + (total - 300) * RATE2;
		else 
			tax = 300 * RATE1 + 150 * RATE2 + (total - 450) * RATE3;
		income = total - tax;
		getchar();
		printf("total:%.2f$, tax:%.2f$, income:%.2f$\n", total, tax, income);
		printf("Please enter hours:");
	}
	return 0;
}

void p9(void)
{
	unsigned inp, prime, origin;
	_Bool flag;
	while (scanf("%u", &inp) == 1)
	{
		if (0 == inp)
			continue;
		for (prime = 2; prime <= inp; prime++)
		{
			flag = 0;
			for (origin = 1; origin <= prime; origin++)
			{
				if (prime % origin == 0 &&
					origin != 1 		&&
					origin != prime
					)
				{
					flag = 1;
					break;
				}
			}
			if (!flag) {
				printf("%u ", prime);
			}
		}
	}
}

void pa(void)
{
	unsigned long income = 0, origin = 0;
	int type = 0;
	double tax; 
	const float TAX_MIN = 0.15f, TAX_MAX = 0.28f;

	printf("*********************************************************\n\n");
	printf("Enter the number correspponding to the desired pay rate to action:\n\n");
	printf("1) 单身                            	   2) 户主\n\n");
	printf("3) 已婚，共有                           4) 已婚，离异\n\n");
	printf("*********************************************************\n\n");
	scanf("%d", &type);
	switch (type) {
		case 1:
		origin = 17850;
		break;

		case 2:
		origin = 23900;
		break;

		case 3:
		origin = 29750;
		break;

		case 4:
		origin = 14785;
		break;

		default:
		printf("Please enter suitable integer:");
		getchar();
	}
	getchar();
	printf("Please enter income:");
	scanf("%lu", &income);
	getchar();
	tax = income <= origin 
	? income * TAX_MIN 
	: origin * TAX_MIN + (income - origin) * TAX_MAX;
	printf("your tax are %f\n", tax);
}

void pb(void)
{
	double unit_price, pounds, total_pounds = 0, total_price = 0, discount = 0, carriage = 0, net_price = 0;
	char kind;
	char kind_name[20];
	double artichoke_price = 0, artichoke_pounds = 0,
	sugarbeet_price = 0, sugarbeet_pounds = 0,
	carrot_price = 0, carrot_pounds = 0;

	printf("Please enter kind of vegetables:\n\n");
	printf("a) artichoke                     b) sugarbeet\n\n");
	printf("c) carrot                     	 q) quit\n\n");
	while (1) {
		switch (kind = getchar())
		{
			case 'a':
			unit_price = 2.05;
			getchar();
			printf("Please enter pounds of artichoke:");
			scanf("%lf", &artichoke_pounds);
			total_pounds += artichoke_pounds;
			artichoke_price += artichoke_pounds * unit_price;
			break;

			case 'b':
			unit_price = 1.15;
			getchar();
			printf("Please enter pounds of sugarbeet:");
			scanf("%lf", &sugarbeet_pounds);
			total_pounds += sugarbeet_pounds;
			sugarbeet_price += sugarbeet_pounds * unit_price;
			break;

			case 'c':
			unit_price = 1.09;
			getchar();
			printf("Please enter pounds of carrot:");
			scanf("%lf", &carrot_pounds);
			total_pounds += carrot_pounds;
			carrot_price += carrot_pounds * unit_price;
			break;

			case 'q':
			getchar();
			goto complete;

			default:
			continue;
		}
		printf("Please enter kind of vegetables:");
	}
	complete:
	total_price = artichoke_price + sugarbeet_price + carrot_price;
	discount = total_price >= 100 ? total_price * 0.05 : 0;
	if (total_pounds <= 5)
		carriage = 6.5;
	else if (total_pounds <= 20)
		carriage = 14;
	else
		carriage = 14 + (total_pounds - 20) * 0.5;
	net_price = total_price - discount + carriage;
	printf("************************************************************************************\n");
	printf("*                                                                                  *\n");
	printf("*         artichoke                      sugarbeet                          carrot *\n");
	printf("* pounds: %-9g                      %-9g                          %-5g  *\n",
	 artichoke_pounds, sugarbeet_pounds, carrot_pounds);
	printf("* price:  %-9g                      %-9g                          %-5g  *\n",
	 artichoke_price, sugarbeet_price, carrot_price);
	printf("* total price:%-6.4g                                                               *\n"
		   "* discount:%-6.4g                                                                  *\n"
		   "* carriage:%-6.4g                                                                  *\n"
		   "* net_price:%-6.4g                                                                 *\n",
	 total_price, discount, carriage, net_price);
	printf("*                                                                                  *\n");
	printf("************************************************************************************\n");
}
//单价* 数量 => 总价 
//总价大于100美元享有 5%优惠
//计算运费