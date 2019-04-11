#include <stdio.h>
#define ROWS 3
#define COLS 5
void copy_arr(double arr[][COLS], int n);
void print_arr(double arr[][COLS], int rows);
void get_average(double * average, double arr[], int rows);
void get_all_average(double * average, double arr[][COLS], int rows);
void get_max(double * max , double arr[][COLS], int rows);
int main(void)
{
	double arr[ROWS][COLS];
	int n = 0;
	double average_line1, average_line2, average_line3, all_average ,max;
	printf("Plese enter 5 double numbers for group1:");
	copy_arr(arr, n);
	n++;
	printf("Plese enter 5 double numbers for group2:");
	copy_arr(arr, n);
	n++;
	printf("Plese enter 5 double numbers for group3:");
	copy_arr(arr, n);
	get_average(&average_line1, arr[0], COLS);
	get_average(&average_line2, arr[1], COLS);
	get_average(&average_line3, arr[2], COLS);
	get_all_average(&all_average, arr, ROWS);
	get_max(&max , arr, ROWS);
	print_arr(arr, ROWS);
	printf("%f , %f, %f \n", average_line1, average_line2, average_line3);
	printf("%f , %f", all_average, max);
	getchar();
	return 0;
}
void copy_arr(double arr[][COLS], int n)
{
	char inp;
	int i = 0;
	while (i < COLS)
		scanf("%lf", &arr[n][i++]);
	while (getchar() != '\n')
		continue;
}
void print_arr(double arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%-4.2f ", arr[i][j]);
		printf("\n");
	}

}
void get_average(double * average, double arr[], int cols)
{
	double sum = 0;
	int i = -1;
	while (++i < cols)
		sum += arr[i];
	*average = sum / cols;
}
void get_all_average(double * average, double arr[][COLS], int rows)
{
	double sum =0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
			sum += arr[i][j];
	}
	*average = sum / (rows * COLS);
}
void get_max(double * max , double arr[][COLS], int rows)
{
	 *max = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
			*max = *max < arr[i][j] ? arr[i][j] : *max;
	}
	
}
