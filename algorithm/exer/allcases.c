
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
int currentM, currentN;
int count;
int scheme[][2][2] = {
	{{0, 1}, {1, 1}},
	{{0, 1}, {1, 0}},
	{{1, -1}, {1, 0}},
	{{1, 0}, {1, 1}}
};
char fiveSquare[][5] = {
	{ 'C', 'L', 'C', 'L', '.' },
	{ 'U', 'D', 'U', 'R', 'C' },
	{ 'R', 'C', 'R', 'C', 'U' },
	{ 'D', 'R', 'C', 'U', 'D' },
	{ 'C', 'L', 'U', 'R', 'C' }
};
#define LEFT_RIGHT_TRANSFORM(c) (c == 'L' ? 'R' : c == 'R' ? 'L' : c)
#define UP_BOTTOM_TRANSFORM(c) (c == 'D' ? 'U' : c == 'U' ? 'D' : c)
char rotate(char c) {
	if (c == 'R') return 'D';
	if (c == 'U') return 'R';
	if (c == 'L') return 'U';
	if (c == 'D') return 'L';
	return '.';
}
char word[][3] = {
	{'R', 'C', 'U'},
	{'C', 'L', 'U'},
	{'D', 'R', 'C'},
	{'D', 'C', 'L'}
};
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
		if (holeY == y) {
			if (holeX == x) {
				grid[x][y + 1] = 'D';
				grid[x + 1][y + 1] = 'C';
				grid[x + 1][y] = 'R';
			} else {

				grid[x][y] = 'R';
				grid[x][y + 1] = 'C';
				grid[x + 1][y + 1] = 'U';
			}
			CHESS_SIX(x, y + 2, m - 2, 1);
		}
		else {
			if (holeX == x) {
				grid[x][y + m - 2] = 'D';
				grid[x + 1][y + m - 2] = 'C';
				grid[x + 1][y + m - 1] = 'L';
			} else {
				grid[x][y + m - 2] = 'C';
				grid[x][y + m - 1] = 'L';
				grid[x + 1][y + m - 2] = 'U';
			}
			CHESS_SIX(x, y, m - 2, 1);
		}
	} else if (m == 2) {

		if (holeX == x) {
			if (holeY == y) {
				grid[x][y + 1] = 'D';
				grid[x + 1][y + 1] = 'C';
				grid[x + 1][y] = 'R';
			} else {

				grid[x][y] = 'D';
				grid[x + 1][y] = 'C';
				grid[x + 1][y + 1] = 'L';
			}
			CHESS_SIX(x + 2, y, n - 2, 0);
		}
		else {
			if (holeY == y) {
				grid[x + n - 2][y + 1] = 'D';
				grid[x + n - 1][y] = 'R';
				grid[x + n - 1][y + 1] = 'C';
			} else {
				grid[x + n - 2][y] = 'D';
				grid[x + n - 1][y] = 'C';
				grid[x + n - 1][y + 1] = 'L';
			}
			CHESS_SIX(x, y, n - 2, 0);
		}
	} else if (n == 5 || m == 5) {
		if (n == 5 && m == 5) {
			int temp;
			if (holeX == x) {
				if (holeY != y) {
					temp = grid[x][y + m - 1];
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							grid[x + i][y + j] = fiveSquare[i][j];
						}
					}
					grid[x][y + m - 1] = temp;
				} else {
					temp = grid[x][y];
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							grid[x + i][y + j] = LEFT_RIGHT_TRANSFORM(fiveSquare[i][m - j - 1]);
						}
					}
					grid[x][y] = temp;
				}
			} else {
				if (holeY != y) {
					temp = grid[x + n - 1][y + m - 1];
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							grid[x + i][y + j] = UP_BOTTOM_TRANSFORM(fiveSquare[n - i - 1][j]);
						}
					}
					grid[x + n - 1][y + m - 1] = temp;

				} else {
					temp = grid[x + n - 1][y];
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							grid[x + i][y + j] = LEFT_RIGHT_TRANSFORM(UP_BOTTOM_TRANSFORM(fiveSquare[n - i - 1][m - j -1]));
						}
					}
					grid[x + n - 1][y + m - 1] = temp;
				}
			}

		} else {

			if (n > 5) {
				if (holeX == x) {
					if (holeY == y) {
						grid[x][y + 1] = 'D';
						grid[x + 1][y] = 'R';
						grid[x + 1][y + 1] = 'C';
						CHESS_SIX(x, y + 2, m - 2, 1);
					} else {
						grid[x][y + m - 2] = 'D';
						grid[x + 1][y + m - 2] = 'C';
						grid[x + 1][y + m - 1] = 'L';
						CHESS_SIX(x, y, m - 2, 1);
					}
					for (int i = n - 2; i >= 6; i -= 6) {
						CHESS_SIX(x + 2, y, 3, 1);
						CHESS_SIX(x + 4, y, 3, 1);
						CHESS_SIX(x + 6, y, 3, 1);
						CHESS_SIX(x + 2, y + 3, 6, 0);
					}
				}
				else {
					if (holeY == y) {
						grid[x + n - 2][y] = 'R';
						grid[x + n - 2][y + 1] = 'C';
						grid[x + n - 1][y + 1] = 'U';
						CHESS_SIX(x + n - 2, y + 2, m - 2, 1);
					} else {
						grid[x + n - 2][y + m - 2] = 'C';
						grid[x + n - 2][y + m - 1] = 'L';
						grid[x + n - 1][y + m - 2] = 'U';
						CHESS_SIX(x + n - 2, y, m - 2, 1);
					}
					for (int i = n - 2; i >= 6; i -= 6) {
						CHESS_SIX(x, y, 3, 1);
						CHESS_SIX(x + 2, y, 3, 1);
						CHESS_SIX(x + 4, y, 3, 1);
						CHESS_SIX(x, y + 3, 6, 0);
					}
				}
			} else {

				if (holeY == y) {
					if (holeX == x) {
						grid[x][y + 1] = 'D';
						grid[x + 1][y] = 'R';
						grid[x + 1][y + 1] = 'C';
						CHESS_SIX(x + 2, y, n - 2, 0);
					} else {
						grid[x + n - 2][y] = 'R';
						grid[x + n - 2][y + 1] = 'C';
						grid[x + n - 1][y + 1] = 'U';
						CHESS_SIX(x, y, m - 2, 0);
					}


					for (int i = m - 2; i >= 6; i -= 6) {
						CHESS_SIX(x + 2, y + 2, 3, 0);
						CHESS_SIX(x + 2, y + 4, 3, 0);
						CHESS_SIX(x + 2, y + 6, 3, 0);
						CHESS_SIX(x, y + 2, 6, 1);
					}
				}
				else {
					if (holeX == x) {
						grid[x][y + m - 2] = 'D';
						grid[x + 1][y + m - 2] = 'C';
						grid[x + 1][y + m - 1] = 'L';
						CHESS_SIX(x + 2, y + m - 2, n - 2, 0);
						/** for (int i = 0; i < 5; i++) { */
						/** for (int j = 0; j < 8; j++) { */
						/**     printf("%c ", grid[i][j]); */
						/** } */
						/** putchar('\n'); */
						/** } */
					} else {
						grid[x + n - 2][y + m - 2] = 'C';
						grid[x + n - 2][y + m - 1] = 'L';
						grid[x + n - 1][y + m - 2] = 'U';
						CHESS_SIX(x, y + m - 2, m - 2, 0);
					}
					for (int i = m - 2; i >= 6; i -= 6) {
						CHESS_SIX(x + 2, y, 3, 0);
						CHESS_SIX(x + 2, y + 2, 3, 0);
						CHESS_SIX(x + 2, y + 4, 3, 0);
						CHESS_SIX(x, y, 6, 1);
					}
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
