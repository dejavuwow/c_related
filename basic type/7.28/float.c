#include <stdio.h>
int main(void)
{
	float aboat = 1.21;
	double abet = 2.14e9;
	double dip = 5.32e-5;
	double com = 1.11111112345;

	printf("%f can be written %e\n",aboat,aboat);

	printf("And it is %a in hexadecimal,powers of 2 notation\n",aboat);

	printf("%f can be written %e\n",abet,abet);

	printf("%Lf can be written %Le\n",dip,dip);
	printf("%.14Lf\n",com );
	printf("%6g\n", aboat);
	printf("%-6g\n", aboat);
	getchar();
	return 0;
} 