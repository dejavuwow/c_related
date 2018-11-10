#include <stdio.h>
int main(void)
{
	float megabit,megabyte,time_second;

	printf("Please enter the download speed as megabits and the file size as megabytes:");
	scanf("%f%f", &megabit, &megabyte);
	getchar();

	time_second = megabyte * 8 / megabit;
	
	printf("%f megabits per seconds,file size is %f megabytes\n", megabit, megabyte);
	printf("%f seconds download\n", time_second);
	getchar();
	return 0;

}