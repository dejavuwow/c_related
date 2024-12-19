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
#define TEST_COVERED(x, y) (grid[x][y] != 0)
int **grid;
int currentM, currentN;
int count;
/** int d[][2] = { */
	/** {1, 0}, */
	/** {0, -1}, */
	/** {-1, 0}, */
	/** {0, 1} */
/** }; */
int scheme[][2][2] = {
	{{0, 1}, {1, 1}},
	{{0, 1}, {1, 0}},
	{{1, -1}, {1, 0}},
	{{1, 0}, {1, 1}}
};
char word[][3] = {
	{'R', 'C', 'U'},
	{'C', 'L', 'U'},
	{'D', 'R', 'C'},
	{'D', 'C', 'L'}
};
int dfs(int x, int y) {
   /**  puts("==========================\n"); */
	/** for (int i = 0; i < currentN; i++) { */
	/**     for (int j = 0; j < currentM; j++) { */
	/**         printf("%c%c ", x == i && y == j ? '#' : 0,  !grid[i][j] ? '*' : grid[i][j]); */
	/**     } */
	/**     puts("\n"); */
	/** } */
	if (x == currentN - 1 && y >= currentM) return 1;
	if ((x == 0 && y == currentM - 1) || (x > 0 && y == currentM)) {
		x++;
		y = 0;
	}
	if (grid[x][y] != 0) {
		return dfs(x, y + 1);
	}
	for (int i = 0; i < 4; i++) {
		int aX = x + scheme[i][0][0];
		int aY = y + scheme[i][0][1];

		int bX = x + scheme[i][1][0];
		int bY = y + scheme[i][1][1];
		
		if (!TEST_BOUNDARY(aX, aY) || !TEST_BOUNDARY(bX, bY) || TEST_COVERED(aX, aY) || TEST_COVERED(bX, bY)) {
			continue;
		}
		grid[x][y] = word[i][0];
		grid[aX][aY] = word[i][1];
		grid[bX][bY] = word[i][2];
		if (!dfs(x, y + 1)) {
			grid[x][y] = 0;
			grid[aX][aY] = 0;
			grid[bX][bY] = 0;
			continue;
		} else return 1;
	}
	return 0;
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
	grid[0][m - 1] = '.';
	if (dfs(0, 0)) {
		puts("Yes");
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
