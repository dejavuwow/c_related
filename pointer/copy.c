#include <stdio.h>
void copy_arr(double target[], double source[], int n);
void copy_ptr(double *target, double *source, int n);
void copy_ptrs(double *target, double *source, double *end);
int max(int *origin, int *end);
int index(double arr[], int n);
void print_arr(double arr[], int n);
void copy_num(double *target, double *source, int n);
void copy_vla(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void print_vla(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void add_arr(int arr1[], int arr2[], int target[], int n);
#define ROWS 2
#define COLS 3
#define CL 5
void mul_two(int rows, int cols, int arr[rows][cols]);
void print_int_arr(int rows, int cols, int arr[rows][cols]);
int main(void)
{
	int arr[3][CL] = {
		{3,4,56,32,21},
		{3,4,56,32,21},
		{3,4,56,32,41}
	};
	mul_two(3, 5, arr);
	print_int_arr(3, 5, arr);
	getchar();
	return 0;
}
void mul_two(int rows, int cols, int arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for( int j = 0; j < CL; j++)
			arr[i][j] = 2 * arr[i][j];
	}
}
void print_int_arr(int rows, int cols, int arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for( int j = 0; j < CL; j++)
			printf("%.2d ", arr[i][j]);
		printf("\n");
	}

}
void add_arr(int arr1[], int arr2[], int target[], int n)
{
	for (int i = 0; i < n; i++)
		target[i] = arr1[i] + arr2[i];
}
void copy_vla(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			target[i][j] = source[i][j];
	}
}
void print_vla(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%f, %f", target[i][j], source[i][j]);
	}
}
void copy_num(double *target, double *source, int n)
{
	int i = 0;
	while (i++ < n)
		*target++ = *source++;
}
void print_arr(double arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%5.2f ", arr[i]);
	putchar('\n');
}
void copy_arr(double target[], double source[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		target[i] = source[i];
}
void copy_ptr(double *target, double *source, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(target+i) = *(source + i);
}
void copy_ptrs(double *target, double *source, double *end)
{
	for (double *i = source; i < end; i++)
		*(target++) = *i;
}
int max(int *origin, int *end)
{
	int max_value = *origin;
	while (++origin < end)
	{
		if (max_value < *origin)
			max_value = *origin;
	}
	return max_value;
}
int index(double arr[], int n)
{
	int j = 0;
	double max = arr[j];
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			j = i;
		}
	}
	return j;
}
