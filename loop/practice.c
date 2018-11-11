#include <stdio.h>
#include <string.h>
//函数声明
void p1(void);
void p2(void);
void p3(void);
void p4(void);
void p5(void);
void p6(void);
void p7(void);
void p8(void);
void p9(void);
void pa(void);
void pb(void);
void pc(void);
void pd(void);
void pe(void);
void pf(void);
void p10(void);
void p11(void);

int main(void)
{
	p11();
	getchar();
	return 0;
}

//函数定义
void p1(void)
{
	char charc[26];
	int index;
	for (index = 0; index < 26; index++)
	{
		charc[index] = index + 97;
		
	}
	charc[index] = '\0';
	printf("%s", charc);
}
//test:
void p2(void)
{
	int a,b;
	for (a = 1; a<= 4; a++)
	{
		for (b = 1; b <= a; b++)
		{
			printf("$ ");
		}
		printf("\n");
	}
}

void p3 (void)
{
	int a;
	char b;
	for (a = 0;a <= 5; a++)
	{
		for(b = '\x46';b >= '\x46' - a; b--)
		{
			printf("%c ", b);
		}
		printf("\n");
	}
}
void p4(void)
{
	int a;
	int b;
	char c = 'A';

	for (a = 0;a<=5;a++)
	{
		for(b = 0;b <= a ; b++)
		{
			printf("%c ", c++);
		}
		printf("\n");
	}
}

void p5(void)
{
	int row,space,up,low;
	char letter;
	char origin;

	printf("Please enter a letter:");
	scanf("%c", &letter);

	getchar();
	for (row = 0 ;row <= letter - 'A';row ++)
	{
		origin = 'A'-1;
		for (space = 1; space <= letter - 'A' - row; space++) {
			printf(" ");
		}
		for (up = 0; up <= row; up++) {
			printf("%c", ++origin);
		}
		for (low = 0; low < row; low++) {
			printf("%c", --origin);
		}
		printf("\n");
	}
}

void p6(void)
{
	int min, max, origin;
	printf("Please enter two integers as min and max:");
	scanf("%d %d",&min, &max);
	getchar();

	for (origin = min; origin <= max; origin++)
	{
		printf("%d %d %d\n",origin, origin * origin, origin * origin *origin);
	}

}

void p7(void)
{
	char arr[20];
	int origin;

	printf("Please enter a string:");
	scanf("%s",arr);

	getchar();

	for (origin = strlen(arr) - 1; origin >= 0; origin--)
	{
		printf("%c", arr[origin]);
	}
}

void pa(void)
{
	int max, min, origin, sum;
	printf("Please enter an integer as min:");
	scanf("%d", &min);
	getchar();
	printf("Please enter an integer as max:");
	scanf("%d", &max);
	getchar();

	while (min < max)
	{
		for (origin = min, sum = 0; origin <= max; origin++)
			sum += origin * origin;

		printf("sum is %d\n", sum);
		printf("Please enter an integer as min:");
		scanf("%d", &min);
		getchar();
		printf("Please enter an integer as max:");
		scanf("%d", &max);
		getchar();
	}

}

void pb(void)
{
	int array[8] = {0};
	printf("Please enter eight integers:\n");
	for (int index = 0; index <= 7; index++)

		scanf("%d", &array[index]);
	
	getchar();

	for (int index = 0; index <= 7; index++)

		printf("%d ", array[7 - index]);
	
}

void pc(void)
{
	int times, origin, sign;
	float sum1 = 0;
	float sum2 = 0;
	printf("Please enter time:");
	scanf("%d", &times);
	getchar();
	while (times > 0) 
	{
		for (origin = 1, sign = 1; origin <= times; origin++, sign *= -1)
		{
			sum1 += 1.0 / origin;
			sum2 += sign * (1.0 / origin);
		}
		printf("%f,%f\n", sum1, sum2);
		sum1 = 0;
		sum2 = 0;
		printf("Please enter time:");
		scanf("%d", &times);
		getchar();
	}

}
// void pd(void)
// {

// 	int cube[8];
// 	int origin;
// 	for (origin = 0; origin < 8; origin++)
// 	{
// 		cube[origin] = 2
// 	}
// }

void pe(void)
{
	double arr1[8], arr2[8], sum = 0;
	int origin;
	printf("Please enter eight integers:");
	for (origin = 0; origin < 8; origin++)
	{
		scanf("%lf", &arr1[origin]);
		sum += arr1[origin];
		arr2[origin] = sum;
	}
	getchar();

	for  (origin = 0; origin < 8; origin++)
	{
		printf("%5g ", arr1[origin]);
	}
	printf("\n");

	for  (origin = 0; origin < 8; origin++)
	{
		printf("%5g ", arr2[origin]);
	}
}

void pf(void)
{
	double sum1 = 100,
	sum2 = 100;
	int count = 0;
	const double PROB1 = 0.1;
	const double PROB2 = 0.05;

	do {
		sum1 += 10;
		sum2 += sum2 * PROB2;
		count++;
	}
	while (sum1 > sum2);

	printf("%d", count);


}

void p10(void)
{
	double origin = 100;
	int count = 0;
	do {
		origin *= 1.08;
		origin -= 10;
		count++;
	}
	while (origin > 0);
	printf("%d", count);
}

void p11(void)
{
	int friends = 5,
	week = 0;
	do {
		week++;
		friends -= week;
		friends *= 2;
	}
	while (friends <= 150);
	printf("%d\n", week);
}
