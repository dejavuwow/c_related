#include <stdio.h>
void show(const double ar[], int n);
void show2(const double ar2[][3],int n);
int main(void)
{
	/* show2((double [][3]) {{1,23,7},{2,3,2}},2); */
	double arr[][3] = {{1,2,3},{2,2,2}};
	show2(arr,2);
	double d = 2222;
	printf("\n%g, %6.3g",d,d);
	getchar();
	return 0;
}
void show(const double ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%f ", ar[i]);
}
void show2(const double ar2[][3], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%f ", ar2[i][1]);
}
//&grid[22][56] &grid[22][0] &(*grid[22]+0)
//&grid[0][0] *(grid[0]+0)  *grid
//int digits[10]
//float rates[6]
//int mat[3][5]
//int *psa[20]
//char (*pstr)[20] 指向内含20个字符的数组的指针，pstr为变量，指向数组，地址字节+20
//char *pstr[20] 内含20个指针的数组，pstr为数组名，是常量，指向char类型值，地址字节+1
//void (double trots[],int n) void(double trots[clos],int n)
//show((int []){8,3,9,2},4); show2((int [2][3]){{8,3,9},{5,4,1}},2);
=======
double getDiffrence(double arr[], int n);
void reverse_arr(double arr[], int n);
int main(void)
{
	reverse_arr((double []){2.1, 2.56, 8.9, 19.2}, 4);
	getchar();
	return 0;
}
double getDiffrence(double arr[], int n)
{
	double min = arr[0], max = arr[0];
	int i = 0;
	while (++i < n)
	{
		max = max < arr[i] ? arr[i] : max;
		min = min > arr[i] ? arr[i] : min;
	}
	return max - min;
}
void reverse_arr(double arr[], int n)
{
	double temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;

	}
	for (int i = 0; i < n; i++)
		printf("%7.2f ", arr[i]);
}
