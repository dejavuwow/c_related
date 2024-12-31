
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *               CL  RC
 *               U    U
 *
 *			     D    D
 *				 CL  RC
 *
 **/             

int check(char **grid, int n, int m) {

#define TEST_BOUNDARY(x, y) (x < 0 || x >= n || y < 0 || y >= m)
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
char **grid;
char fiveSquare[][5] = {
	{ 'C', 'L', 'C', 'L', '.' },
	{ 'U', 'D', 'U', 'R', 'C' },
	{ 'R', 'C', 'R', 'C', 'U' },
	{ 'D', 'R', 'C', 'U', 'D' },
	{ 'C', 'L', 'U', 'R', 'C' }
};
#define LEFT_RIGHT_TRANSFORM(c) (c == 'L' ? 'R' : c == 'R' ? 'L' : c)
#define UP_BOTTOM_TRANSFORM(c) (c == 'D' ? 'U' : c == 'U' ? 'D' : c)
#define CHESS_HOLE_SQUARE(x, y, holeX, holeY) {\
	if (holeY == y) {\
		if (holeX == x) {\
			grid[x][y + 1] = 'D';\
			grid[x + 1][y + 1] = 'C';\
			grid[x + 1][y] = 'R';\
		} else {\
			grid[x][y] = 'R';\
			grid[x][y + 1] = 'C';\
			grid[x + 1][y + 1] = 'U';\
		}\
	}\
	else {\
		if (holeX == x) {\
			grid[x][holeY - 1] = 'D';\
			grid[x + 1][holeY - 1] = 'C';\
			grid[x + 1][holeY] = 'L';\
		} else {\
			grid[x][holeY - 1] = 'C';\
			grid[x][holeY] = 'L';\
			grid[x + 1][holeY - 1] = 'U';\
		}\
	}\
}

void CHESS_SIX(int x, int y, int length1, int xEquql2) {
	int length = length1;
	if (xEquql2) {
		while (length >= 3) {
			grid[x][y] = 'D';
			grid[x + 1][y] = 'C';
			grid[x + 1][y + 1] = 'L';
			grid[x][y + 1] = 'R';
			grid[x][y + 2] = 'C';
			grid[x + 1][y + 2] = 'U';
			y += 3;
			length -= 3;
		}
	} else {
		while (length >= 3) {
			grid[x][y] = 'C';
			grid[x][y + 1] = 'L';
			grid[x + 1][y] = 'U';
			grid[x + 1][y + 1] = 'D';
			grid[x + 2][y] = 'R';
			grid[x + 2][y + 1] = 'C';
			x += 3;
			length -= 3;
		}
	}
}

void chess(int x, int y, int n, int m, int holeX, int holeY) {
	if (n == 2) {
		CHESS_HOLE_SQUARE(x, y, holeX, holeY);
		CHESS_SIX(x, holeY == y ? y + 2 : y, m - 2, 1);
	} else if (m == 2) {
		CHESS_HOLE_SQUARE(x, y, holeX, holeY);
		CHESS_SIX(holeX == x ? x + 2 : x, y, n - 2, 0);
	} else if (n == 5 || m == 5) {
		if (n == 5 && m == 5) {
			int temp = grid[holeX][holeY];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					grid[x + i][y + j] = (holeX == x && holeY != y) ? fiveSquare[i][j] : holeX == x ? LEFT_RIGHT_TRANSFORM(fiveSquare[i][m - j - 1]) : (holeX != x && holeY != y) ? UP_BOTTOM_TRANSFORM(fiveSquare[n - i - 1][j]) : LEFT_RIGHT_TRANSFORM(UP_BOTTOM_TRANSFORM(fiveSquare[n - i - 1][m - j -1]));
				}
			}
			grid[holeX][holeY] = temp;

		} else {

			if (n > 5) {
				int carry = n % 6;
				int newX = holeX == x ? x : x + n - carry;
				int value = holeX == x ? carry : 0;
				chess(newX, y, carry, m, holeX, holeY);
				for (int i = n - carry; i >= 6; i -= 6, x += 6) {
					CHESS_SIX(x + value, y, 6, 0);
					CHESS_SIX(x + value, y + 2, 3, 1);
					CHESS_SIX(x + 2 + value, y + 2, 3, 1);
					CHESS_SIX(x + 4 + value, y + 2, 3, 1);
				}
			} else {
				int carry = m % 6;
				int newY = holeY == y ? y : y + m - carry;
				int value = holeY == y ? carry : 0;
				chess(x, newY, n, carry, holeX, holeY);
				for (int i = m - carry; i >= 6; i -= 6, y += 6) {
					CHESS_SIX(x, y + value, 6, 1);
					CHESS_SIX(x + 2, y + value, 3, 0);
					CHESS_SIX(x + 2, y + 2 + value, 3, 0);
					CHESS_SIX(x + 2, y + 4 + value, 3, 0);
				}
			} 
		} 

	} else if (n % 3 == 1) {
		if (holeX == x) {
			if (holeY == y) {
				grid[x + 1][y + 2] = 'D';
				grid[x + 2][y + 1] = 'R';
				grid[x + 2][y + 2] = 'C';
				chess(x, y, 2, 2, x, y);
				chess(x, y + 2, 2, m - 2, x + 1, y + 2);
				chess(x + 2, y, n - 2, 2, x + 2, y + 1);
				chess(x + 2, y + 2, n - 2, m - 2, x + 2, y + 2);
			} else {
				grid[x + 1][y + 1] = 'D';
				grid[x + 2][y + 1] = 'C';
				grid[x + 2][y + 2] = 'L';
				chess(x, y, 2, 2, x + 1, y + 1);
				chess(x, y + 2, 2, m - 2, x, y + m - 1);
				chess(x + 2, y, n - 2, 2, x + 2, y + 1);
				chess(x + 2, y + 2, n - 2, m - 2, x + 2, y + 2);
			}
		} else {
			if (holeY == y) {
				grid[x + 1][y + 1] = 'R';
				grid[x + 1][y + 2] = 'C';
				grid[x + 2][y + 2] = 'U';
				chess(x, y, 2, 2, x + 1, y + 1);
				chess(x, y + 2, 2, m - 2, x + 1, y + 2);
				chess(x + 2, y, n - 2, 2, x + n - 1, y);
				chess(x + 2, y + 2, n - 2, m - 2, x + 2, y + 2);
			} else {
				grid[x + 1][y + 1] = 'C';
				grid[x + 1][y + 2] = 'L';
				grid[x + 2][y + 1] = 'U';
				chess(x, y, 2, 2, x + 1, y + 1);
				chess(x, y + 2, 2, m - 2, x + 1, y + 2);
				chess(x + 2, y, n - 2, 2, x + 2, y + 1);
				chess(x + 2, y + 2, n - 2, m - 2, x + n - 1, y + m - 1);
			}
		}
	} else if (n % 3 == 2) {
		if (holeX == x) {
			if (holeY == y) {
				grid[x + 3][y + 4] = 'D';
				grid[x + 4][y + 3] = 'R';
				grid[x + 4][y + 4] = 'C';
				chess(x, y, 4, 4, x, y);
				chess(x, y + 4, 4, m - 4, x + 3, y + 4);
				chess(x + 4, y, n - 4, 4, x + 4, y + 3);
				chess(x + 4, y + 4, n - 4, m - 4, x + 4, y + 4);
			} else {
				grid[x + 3][y + 3] = 'D';
				grid[x + 4][y + 3] = 'C';
				grid[x + 4][y + 4] = 'L';
				chess(x, y, 4, 4, x + 3, y + 3);
				chess(x, y + 4, 4, m - 4, x, y + m - 1);
				chess(x + 4, y, n - 4, 4, x + 4, y + 3);
				chess(x + 4, y + 4, n - 4, m - 4, x + 4, y + 4);
			}
		} else {
			if (holeY == y) {
				grid[x + 3][y + 3] = 'R';
				grid[x + 3][y + 4] = 'C';
				grid[x + 4][y + 4] = 'U';
				chess(x, y, 4, 4, x + 3, y + 3);
				chess(x, y + 4, 4, m - 4, x + 3, y + 4);
				chess(x + 4, y, n - 4, 4, x + n - 1, y);
				chess(x + 4, y + 4, n - 4, m - 4, x + 4, y + 4);
			} else {
				grid[x + 3][y + 3] = 'C';
				grid[x + 3][y + 4] = 'L';
				grid[x + 4][y + 3] = 'U';
				chess(x, y, 4, 4, x + 3, y + 3);
				chess(x, y + 4, 4, m - 4, x + 3, y + 4);
				chess(x + 4, y, n - 4, 4, x + 4, y + 3);
				chess(x + 4, y + 4, n - 4, m - 4, x + n - 1, y + m - 1);
			}
		}
	}
}
void solve() {

	for (int n = 2; n <= 500; n++) {
		for (int m = 2; m <= 500; m++) {
			grid = malloc(sizeof(char*) * n);
			for (int i = 0; i < n; i++) {
				grid[i] = (char*)malloc(sizeof(char) * m);
				memset(grid[i], 0, sizeof(char) * m);
			}
			grid[0][m - 1] = '.';
			if ((m * n - 1) % 3 != 0) {
				//puts("No");
			}
			else {
				//puts("Yes");
				chess(0, 0, n, m, 0, m -1);
				if (!check(grid, n, m)) {
					printf("err case: **%d %d\n", n, m);
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							printf("%c", grid[i][j]);
						}
						putchar('\n');
					}
					return;
				} else {
					printf("%d %d\n", n, m);
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

}

int main() {
	solve();
	return 0;
}
