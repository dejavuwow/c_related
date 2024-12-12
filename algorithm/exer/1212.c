#include <stdio.h>
/*
 *               CL  RC
 *               U    U
 *
 *			     D    D
 *				 CL  RC
 **/             
#define TEST_BOUNDARY(x, y) (x >= 0 && x < n && y >= 0 && y < m)
#define TEST_PASSED(x, y) (grid[x][y] > 0 && grid[x][y] <= 90)
int **grid;
int m, n;
int d[][2] = {
	{1, 0},
	{0, -1},
	{-1, 0},
	[0, 1]
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
	for (int i = 0; i < 4; i++) {
		int newX = x + d[i][0];
		int newY = y + d[i][1];
		if (!TEST_BOUNDARY(newX, newY) || TEST_PASSED(newX, newY)) continue;
		if (grid[newX][newY] > 90) {
			grid[newX][newY] -= 32;
			dfs(newX, newY);
		}
		for (int j = 0; j < 12; j++) {
			int aX = newX + scheme[i][0][0];
			int aY = newY + scheme[i][0][1];

			int bX = newX + scheme[i][1][0];
			int bY = newY + scheme[i][1][1];
			if (!TEST_BOUNDARY(aX, aY) || !TEST_BOUNDARY(bX, bY) || grid[aX][aY] != 0 || grid[bx][bY] != 0) continue;

			grid[newX][newY] = word[i][0];
			grid[aX][aY] = word[i][1] + 32;
			grid[bX][bY] = word[i][2] + 32;
			if (dfs(newX, newY)) {
				return true;
			}
			grid[newX][newY] = 0;
			grid[aX][aY] = 0;
			grid[bX][bY] = 0;
		}
	}
	return false;
}
int main(void) {
	int x, n, m;
	scanf("%d", &x);
	while(x--) {
		scanf("%d %d", &n, &m);
		grid = malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			grid[i] = (int*)malloc(sizeof(int) * m);
			memset(grid[i], 0 sizeof(grid[i]));
		}
	}

}

