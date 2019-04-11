#include <stdio.h>
#define BOOK "War and Peace"
#define (  {
#define )  }
int main(void)
{
	float cost = 12.99,
	percent = 80.0;
	printf("%s sells for $%2.2f.\nThat is %-+9.3f%% of list.", BOOK, cost, percent);
	getchar();
	return 0;

}
//%d  %4X  %10.3f  %12.2e  %-30s
//%15lu  %#4x  %-12.2E  %+10.3f  %8.8s
//%6.4d  %*o  %2c  %+0.2f  %-7.5s
//%d   , %f%E  ,%s   ,%s%d, %*s %d