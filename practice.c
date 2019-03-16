#include <stdio.h>
void p8(void);
float tips(float number, char no_number);
int main(void)
{
	p8();
	getchar();
	return 0;
}
void p8(void)
{
	char option, no_number;
	float f_number, s_number;
	printf("Enter the operation of your choice:\n");
	printf("a. add                      s. substract\n"
			"m. multily                  d. divide\n"
			"q. quit\n");
start:while(option = getchar())
	   {
		   while(getchar() != '\n')	
			   continue;
		   switch(option) {
			   case 'a':
				   printf("enter first number:");
				   f_number = tips(f_number, no_number);
				   printf("enter second number:");
				   s_number = tips(s_number, no_number);
				   printf("%f", f_number + s_number);
				   break;
			   case 's':
				   printf("enter first number:");
				   f_number = tips(f_number, no_number);
				   printf("enter second number:");
				   s_number = tips(s_number, no_number);
				   printf("%f", f_number - s_number);
				   break;
			   case 'm':
				   printf("enter first number:");
				   f_number = tips(f_number, no_number);
				   printf("enter second number:");
				   s_number = tips(s_number, no_number);

				   printf("%f", f_number * s_number);
				   break;
			   case 'd':
				   printf("enter first number:");
				   f_number = tips(f_number, no_number);
				   printf("enter second number:");
				   s_number = tips(s_number, no_number);
				   while(s_number == 0) {
					   printf("0 can\'t be divsor, please enter an number other than 0:");
					   while(scanf("%f", &s_number) != 1)
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
		   printf("\nEnter the operation of your choice:\n");
	   }
}
float tips(float number, char no_number)
{
	while(scanf("%f", &number) != 1)
	{
		while((no_number = getchar()) != '\n')
			putchar(no_number);
		printf(" is not an number \n");
		printf("please enter a number, such as 2.5, -1.7231, or 5:");
	}
	while(getchar() != '\n')
		continue;
	return number;
}
