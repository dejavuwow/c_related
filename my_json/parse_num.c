#include <stdio.h>
#include <math.h>

double parse_num(const char *num)
{
	double n = 0; //数字结果
	int sign = 1, //正负
		scale = 0, //小数点位数
		ex_sign = 1, //指数正负
		ex_scale = 1; //指数大小

	if (*num++ == '-') sign = -1;
	if (*num >= '1' && *num <= '9') 
	{
		do {
			n = n * 10.0 + *num++ - '0';
		} 
		while (*num >= '0' && *num <= '9');
	}
	if (*num == '.' && num[1] >= '0' && num[1] <= '9'>)
	{
		num++;
		do {
			n = n * 10.0 + *num
		}
	}
}
