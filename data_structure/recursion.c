#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 256
#define LINK(x) m##x
/*
 * 伪代码
 *1、 参数 n, 用来装n的质因数的数组， i为尝试的最小质因数
 *2、 先从最小质数2试，若取余不为0，则2不是n的最小质因数，n++
 *3、 若取余为0，则将n赋值为i，跳转至第一步
 * */
void getPrimeFactor(int n, int *array, int index);
int fibonacci(int n);

int fibonacci2(int n, int first, int second)
{
	if (n < 3) return second;
	int temp = second;
	second += first;
	first = temp;
	return fibonacci2(--n, first, second);
	
	
}

int main(int argc, char **argv)
{
	int array[10] = {0};
	getPrimeFactor(2409, array, 0);
	/* int n = 2409, index = 0; */
	/* for (int i = 2; n >= i; i++) */
	/* { */
		/* if (n % i == 0) */
			/* array[index++] = i, */
			/* n /= i, */
			/* i--  ; */

	/* } */
	/* for (int *i = array; i < array + 10; i++) */
		/* printf("%d ", *i); */
	int LINK(5) = 16;
	/* printf("%d", m5); */
	for (int i = 1; i < 11; i++)
		printf("%d ", fibonacci2(i, 1, 1));
	return 0;
}
// 9 + 5 + 3 + 1
// 1 +  1/2 + 1/2
// 
void getPrimeFactor(int n, int *array, int index)
{
	int i = 2;
	while (n % i != 0 && i < n) i++;
	array[index++] = i;
	if (n == i) {
		return;
	}
	return getPrimeFactor(n /= i, array, index);
}

int fibonacci(int n)
{
	int first = 1,
		second = 1;
	int temp;
	if (n < 3) return 1;

	for (int i = 3; i <= n; i++)
	{
		temp = second;
		second += first;
		first = temp;
	}
	return second;
}

