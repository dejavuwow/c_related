#include <stdio.h>
#define X 2
#define Y 3
#define Z 2
void matrix_multipl(int *m1, int *m2, int *r, int x, int y, int z)
{
	int m = 2;
	printf("%p", &x);
	for (int row = 0; row < x; row++)
	{
		for (int col =0; col < z; col++)
		{
			r[row * z + col] = 0;
			for (int i = 0; i < y; i++)
			{
				r[row * z + col] += m1[row * y + i] * m2[col + i * z];
			}
		}
	}
}
int main(void)
{

	int m1[X][Y] = {
		{1,2,3},
		{3,2,1}
	},
		m2[Y][Z] = {
			{1, 2},
			{3, 2},
			{1, 2}
		};
	int x = 2, y = 2;
	int r[X][Z];
	int a = 2;
	int test[x][y];
	int b = 3;
	matrix_multipl(m1[0], m2[0], r[0], X, Y, Z);
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Z; j++)
		{
			printf("%d ", r[i][j]);
		}
		putchar('\n');
	}
	int c = 23;
	printf("%p  %p  %p  %p %p", &a, &b, &test, m1, &c);
}
