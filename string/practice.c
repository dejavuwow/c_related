#include <stdio.h>
#include <string.h>
unsigned get_size(char *str);
char *s_gets(char *inp, int n);
char *get_space(char *inp);
int main(void)
{
	char inp[] = "myfavouradehabbit";
	printf("%p", get_space(inp));
char *s_gets(char *st, int n);
int main(void)
{
	/* M3 = M1; */
	/* printf("%#p \n %p \n %p \n", M1, M2, M3); */
	/* getchar(); */
	char *inp;
	char *res;
	res = gets(inp);
	puts(res);
	puts(inp);
	getchar();

	return 0;
}
unsigned get_size(char *str)
{
	unsigned n = 0;
	while(*str++)
		n++;
	return n;
}
char *s_gets(char *inp, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(inp, n, stdin);
	if (ret_val)
	{
		/* while (inp[i] != '\0' && inp[i] != '\n') */
		/* i++; */
		/* if (inp[i] == '\n') */
		/* inp[i] = '\0'; */
		/* else */
		/* while(getchar() != '\n') */
		/* continue; */
		char *find = strchr(inp, '\n');
		if (find)
			*find = '\0';
char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(*st != '\n' && *st != '\0')
			st++;
		if(*st == '\n')
			*st = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
char *get_space(char *inp)
{
	return strchr(inp, ' ');
}
//70 65 84 69
//46   41   54   45
//0.8734
//         	
//y my mmy ummy Yummy
//I read part of it all the way through
// ho ho ho!
// oh oh oh
// char指针
// 首字符的地址
// 指针递减 值递减
// !oh oh oh
//测试是否为空字符 指针之差是否为0
//未定义，空字符前面一位的地址
//函数声明原型
//1 4 2
//
//How...
//How...
//Beat..
//eat...
//Beat the clock. win a toy
//Beat
//c h a t
//t a
// faavrhee
// f a v r h e
// *le*on*sm*
//9、_、5、_、_、_
//6 4
//9 5
