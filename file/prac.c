#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int arc, char *argv[])
{
	FILE *fp;
	float **arr;
	float in;
	float sum = 0;
	char ch[10];
	if (arc > 1)
	{
		if ((fp = fopen(argv[1], "rb")) == NULL)
		{
			fprintf(stderr,"Can't open %s.\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		int i = 0;
		while (fscanf(fp,"%f", &in)) 
		{
			printf("%f\n", in);
			arr[i] = (float *)malloc(sizeof(float));
			*arr[i] = in;
			printf("%f\n", *arr[i]);
			i++;
		} 
		fclose(fp);
		for (int j = 0; j < i; j++)
		{
			printf("%-5.f", *arr[j]);
			sum += *arr[j];
		}
		printf("%f", sum / i);
	}
	else {
		fp = fopen("test.txt", "w+");
		int i = 0;
		while (fscanf(stdin,"%f", &in))
		{
			arr[i] = (float *)malloc(sizeof(float));
			*arr[i] = in;
			printf("%f\n", *arr[i]);
			i++;
		}
		while (getchar() != '\n')
			continue;
		for (int j = 0; j < i; j++)
		{
			fprintf(fp,"%-5.f", *arr[j]);
			sum += *arr[j];
		}
		printf("%f", sum / i);

	}

	getchar();
	return 0;
}
//FILE 声明，文件打开模式，错误处理
//从一个文件中打印每一个整数字符
//a:fp1 	b:fp2,ch	 c:ch,fp2 	d:fp1
