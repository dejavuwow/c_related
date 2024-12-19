#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1
//4 4
/*
 *               CL  RC
 *               U    U
 *
 *			     D    D
 *				 CL  RC
 **/             
#define TEST_BOUNDARY(x, y) (!(x == 0 && y == currentM - 1) && x >= 0 && x < currentN && y >= 0 && y < currentM)
#define TEST_PASSED(x, y) (grid[x][y] > 0 && grid[x][y] <= 90)
int **grid;
int currentM, currentN;
int count;
int d[][2] = {
	{1, 0},
	{0, -1},
	{-1, 0},
	{0, 1}
};
int scheme[][2][2] = {
	{{0, -1}, {1, 0}},
	{{0, 1}, {1, 1}},
	{{-1, -1}, {-1, 0}},

	{{-1, 0}, {0, -1}},
	{{1, 0}, {1, -1}},
	{{-1, 1}, {0, 1}},

	{{-1, 0}, {0, 1}},
	{{1, 0}, {1, 1}},
	{{-1, -1}, {0, -1}},

	{{0, 1}, {1, 0}},
	{{0, -1}, {1, -1}},
	{{-1, 1}, {-1, 0}}

};
char word[][3] = {
	{'C', 'R', 'U'},
	{'R', 'C', 'U'},
	{'U', 'R', 'C'},

	{'C', 'D', 'R'},
	{'D', 'C', 'R'},
	{'R', 'D', 'C'},

	{'C', 'D', 'L'},
	{'D', 'C', 'L'},
	{'L', 'D', 'C'},

	{'C', 'L', 'U'},
	{'L', 'C', 'U'},
	{'U', 'L', 'C'}
};
int dfs(int x, int y) {
	/** printf("**%d %d\n", x, y); */
	for (int i = 0; i < 4; i++) {
		int newX = x + d[i][0];
		int newY = y + d[i][1];

		if (!TEST_BOUNDARY(newX, newY) || TEST_PASSED(newX, newY)) {
			continue;
		}
		if (grid[newX][newY] > 90) {
			grid[newX][newY] -= 32;
			count++;
			if (!dfs(newX, newY)) {
				grid[newX][newY] += 32;
				count--;
				continue;
			}
			return 1;
		}

		for (int j = 0; j < 12; j++) {
			int aX = newX + scheme[j][0][0];
			int aY = newY + scheme[j][0][1];

			int bX = newX + scheme[j][1][0];
			int bY = newY + scheme[j][1][1];

			if (!TEST_BOUNDARY(aX, aY) || !TEST_BOUNDARY(bX, bY) || grid[aX][aY] != 0 || grid[bX][bY] != 0) continue;

			grid[newX][newY] = word[j][0];
			grid[aX][aY] = word[j][1] + 32;
			grid[bX][bY] = word[j][2] + 32;
			count++;
			if (dfs(newX, newY)) {
				return 1;
			}
			count--;
			grid[newX][newY] = 0;
			grid[aX][aY] = 0;
			grid[bX][bY] = 0;
		}
	}
	return count == currentM * currentN - 1 ? 1 : 0;
}
int main(void) {
	int x;
	scanf("%d", &x);
	int l = x;
	int temp[l][2];
	while(x) {
		scanf("%d %d", &temp[l - x][0], &temp[l - x][1]);
		x--;
	}
	for (int i = 0; i < l; i++) {
		int n = currentN = temp[i][0];
		int m = currentM = temp[i][1];
		count = 0;
		grid = malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			grid[i] = (int*)malloc(sizeof(int) * m);
			memset(grid[i], 0, sizeof(int) * m);
		}
		grid[0][m - 1] = '.';
		if ((m * n - 1) % 3 != 0 || !dfs(0, m - 1)) {
		    	puts("No");
		} else {
			puts("Yes");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					printf("%c", grid[i][j]);
				}
				putchar('\n');
			}
		}
		for (int i = 0; i < n; i++) {
			free(grid[i]);
			grid[i] = NULL;
		}
		free(grid);
		grid = NULL;

	}

}
