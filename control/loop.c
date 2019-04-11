#include <stdio.h>
int main(void)
{
	unsigned inp;
	while (scanf("%u", &inp) == 1)
	{
		getchar();
		if (inp < 10) {
			printf("0~10");
		} 
		else if (inp < 20) {
			printf("10~20");
		}
		else {
			printf("20+");
		}
	}
}