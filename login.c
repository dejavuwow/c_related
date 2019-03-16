#include <stdio.h>
#define NUMBER 20
int main(void)
{
	char username[] = "dejavu007",
		 password[] = "bemyword";
	char your_username[NUMBER],your_password[NUMBER];
	char inp;
	int i = 0;
	printf("Please enter your username:");
	while(i < NUMBER)
	{
		if ((inp = getchar()) == '\n' && i == 0)
			continue;
		if (inp == '\n')
			break;
		your_username[i] = inp;
		i++;
	}
	i = 0;
	printf("Please enter your password:");
	while(i < NUMBER)
	{
		if ((inp = getchar()) == '\n' && i == 0)
			continue;
		if (inp == '\n')
			break;
		your_password[i] = inp;
		i++;
	}
	for (int j = 0; j < 9; j++)
	{
		if (username[j] != your_username[j])
		{
			printf("username is wrong!");
			getchar();
			return 0;
		}
	}
	for (int j = 0; j < 8; j++)
	{
		if (password[j] != your_password[j])
		{
			printf("password is wrong!");
			getchar();
			return 0;
		}
	}
	printf("yes!");
	getchar();
	return 0;

}
