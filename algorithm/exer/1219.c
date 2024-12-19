#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST_BOUNDARY(x, y) (x < 0 || x >= n || y < 0 || y >= m)
int check(char **grid, int n, int m) {
	int count = 0;
	int cCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			switch (grid[i][j]) {
				case 'C':
					if ((!TEST_BOUNDARY(i, j -1) && !TEST_BOUNDARY(i, j + 1) && grid[i][j - 1] == 'R' && grid[i][j + 1] == 'L') ||(!TEST_BOUNDARY(i - 1, j) && !TEST_BOUNDARY(i + 1, j) && grid[i - 1][j] == 'D' && grid[i + 1][j] == 'U')) {
						return 0;
					}
					count++;
					cCount++;
					break;
				case 'U':
					if (TEST_BOUNDARY(i - 1, j) || grid[i - 1][j] != 'C') return 0;
					count++;
					break;
				case 'L':
					if (TEST_BOUNDARY(i, j - 1) || grid[i][j - 1] != 'C') return 0;
					count++;
					break;
				case 'D':
					if (TEST_BOUNDARY(i + 1, j) || grid[i + 1][j] != 'C') return 0;
					count++;
					break;
				case 'R':
					if (TEST_BOUNDARY(i, j + 1) || grid[i][j + 1] != 'C') return 0;
					count++;
					break;
				case '.':
					if (i != 0 || j != m - 1) return 0;
					break;
			}
		}
	}
	return count == m * n - 1 && cCount == (m * n - 1) / 3;
}
#define TO_POINT(c) (c == 'R' ? 1 : c == 'U' ? 2 : c == 'C' ? '3': c == 'L' ? '4' : c == 'D' ? 5)
int check(int **grid, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
		}
	}
}
int main() {
	int x;
	int n, m;
	scanf("%d", &x);
	char **grid;
	while(x--) {
		scanf("%d %d", &n, &m);
		grid = malloc(sizeof(char*) * n);
		/** printf("%d %d\n", n, m); */
		for (int i = 0; i < n; i++) {
			grid[i] = (char*)malloc(sizeof(char) * (m + 1));
			scanf("%s", grid[i]);
		}
		if ((m * n - 1) % 3 == 0 && check(grid, n, m)) {
			puts("Yes");
		} else {
			puts("No");
		}

		for (int i = 0; i < n; i++) {
			free(grid[i]);
			grid[i] = NULL;
		}
		free(grid);
		grid = NULL;
	}
	return 0;
}
