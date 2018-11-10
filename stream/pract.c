#include <stdio.h>
void p8(void);
void tips(float number, char no_number);
int main(void)
{
	float number;
	char no_number;
	while (scanf("%f", &number) == 1);
	{
		printf("%f", number);
		getchar();
		getchar();
		printf("please enter a number, such as 2.5, -1.7231, or 5:");
	}
	getchar();
	printf("%f", number);
	while((no_number = getchar()) != '\n')
		continue;

	/*float number;
	  char opt;
	  tips(number, opt);
	  getchar();
	  return 0;
	  */
}
void p8(void)
{
	char option, no_number;
	float f_number, s_number;
	printf("Enter the operation of your choice:\n");
	printf("a. add                      s. substract\n"
			"m. multily                  d. divide\n"
			"q. quit\n");
start: while(option = getchar())
	   {
		   while(getchar() != '\n')	
			   continue;
		   printf("enter first number:");
		   tips(f_number, no_number);
		   printf("enter second number:");
		   tips(s_number, no_number);
		   switch(option) {
			   case 'a':
				   printf("%f", f_number + s_number);
				   break;
			   case 's':
				   printf("%f", f_number - s_number);
				   break;
			   case 'm':
				   printf("%f", f_number * s_number);
				   break;
			   case 'd':
				   while(s_number == 0) {
					   printf("0 can\'t be divsor, please enter an number other than 0:");
					   while(scanf("%f", &s_number) != 1);
					   {
						   while(getchar() != '\n')
							   continue;
						   printf("please enter an number other than 0:");
					   }
				   }
				   printf("%f", f_number / s_number);
				   break;
			   case 'q':
				   return;
			   default:
				   printf("please enter corret option:");
				   goto start;
		   }
		   printf("Enter the operation of your choice:\n");
	   }
}
void tips(float number, char no_number)
{
	while (scanf("%f", &number) != 1);
	{
		while((no_number = getchar()) != '\n')
			putchar(no_number);
		printf(" is not an number \n");
		printf("please enter a number, such as 2.5, -1.7231, or 5:");
	}
	while((no_number = getchar()) != '\n')
		continue;
}
