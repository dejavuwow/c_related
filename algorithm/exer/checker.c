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
int main() {
	int x;
	int n, m;
	scanf("%d", &x);
	char **grid;
	while(x) {
		scanf("%d %d", &n, &m);
		grid = malloc(sizeof(char*) * n);
		for (int i = 0; i < n; i++) {
			grid[i] = (char*)malloc(sizeof(char) * m);
			scanf("%s", grid[i]);
		}
		if (check(grid, n, m)) {
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
		/** for (int i = 0; i < n; i++) { */
		/** for (int j = 0; j < m; j++) { */
		/**     printf("%c ", grid[i][j]); */
		/** } */
		/** putchar('\n'); */
		/** } */
		x--;
	}
}
