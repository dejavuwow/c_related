#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#define PI 3.14159265


struct coor {
	double length;
	double	angle;
};
struct angle {
	double x;
	double y;
};

struct name {char first[10]; char last[10];};
struct angle *getAngle(struct coor);
void singleLoop(double time);
_Bool include(const int arr[], int n, int num);
void printLottery(const int arr[], int n, int times);
int myComp(const void *v1, const void *v2);
void show_array(const double ar[], int n);
double *new_d_array(int n, ...);

int main(void)
{
	double *p1, *p2;
	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
	show_array(p1, 5);
	putchar('\n');
	show_array(p2, 4);
	free(p1);
	free(p2);


	return 0;
}
void show_array(const double ar[], int n)
{
	for (int i=0; i<n; i++)
		printf("%f ", ar[i]);
}

double *new_d_array(int n, ...)
{
	va_list ap;
	double *ptr = (double*)malloc(sizeof(double)*n);
	va_start(ap,n);
	for (int i=0; i < n; i++)
		ptr[i] = va_arg(ap, double);

	va_end(ap);

	return ptr;
}

int myComp(const void *v1, const void *v2)
{
	return strcmp(((const struct name *)v1)->first, ((const struct name *)v2)->first);
}

struct angle *getAngle(struct coor c1)
{
	struct angle *pt1 = (struct angle*)malloc(sizeof(struct angle));
	pt1->x = c1.length * cos(c1.angle);
	pt1->y = c1.length * sin(c1.angle);

	return pt1;
}
//1010
//10000
void singleLoop(double time)
{
	clock_t end = clock() + time * CLOCKS_PER_SEC;
	/* while (((double)(clock() - start) / CLOCKS_PER_SEC) <= time) */
	while (clock() <= end)
			continue;

	printf("Done !");
}

void printLottery(const int arr[], int n, int times)
{
	const int num = 5;
	int select[5];
	int index;

	srand((unsigned int)time(0));
	while (times--)
	{
		for (int i = 0; i < num; i++)
		{
			while (include(select, i, index = arr[rand() % n]))
				continue;
			select[i] = index;
		}
		for (int i = 0; i < num; i++)
			printf("%d ", select[i]);
		putchar('\n');
	}
}

_Bool include(const int arr[], int n, int num)
{
	while (n--)
		if (num == arr[n])
			return 1;
	return 0;
}
