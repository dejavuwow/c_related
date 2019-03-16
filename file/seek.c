#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *s_gets(char *str, int size);

int main(void)
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	char name[40];
	s_gets(name, 40);
	if ((fp = fopen(name,"rb")) == NULL)
	{
		fprintf(stderr,"Cant't open %s", name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", name, count);

	getchar();
	return 0;
}

char *s_gets(char *str, int size)
{
	char *find;
	char *ret_val;
	ret_val = fgets(str,size,stdin);
	if (ret_val) 
	{
		if (find = strchr(ret_val,'\n'))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
/* int main(int argc, char *argv[]) */
// {
// FILE *fp;
// char str[257];

// if (argc < 3) //没有参数则中断程序
// {
// puts("No parameters!");
// exit(EXIT_FAILURE);
// }

// if ((fp = fopen(argv[2],"r")) == NULL) //打开文件错误处理
// {
// fprintf(stderr,"Can't open %s.\n", argv[2]);
// exit(EXIT_FAILURE);
// }

// while (fgets(str,257,fp))
// if (strchr(str, argv[1][0]))
// fputs(str,stdout);
// fclose(fp);
// getchar();
// return 0;
/* } */
//默认标准输出，可以将输出到文件，无缓冲，标准错误输出不受输出重定向影响
