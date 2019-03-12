#include <stdio.h>
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
