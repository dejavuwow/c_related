#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** int check(int x, int y, int row, int col, int board[row][col]) { */
/** int c = 0; */
/** for (int i = 1; x - i >= 0; i++) { */
/**     c |= board[x - i][y]; */
/**     if (y - i >= 0) { */
/**         c |= board[x - i][y - i]; */
/**     } */
/**     if (y + i < col) { */
/**         c |= board[x - i][y + i]; */
/**     } */
/** } */
/** return !c; */
/** } */
void update(int row, int col, int map[row][col], char board[row][col], int x, int y, int isAdd) {
	board[x][y] = isAdd ? 'Q' : '.';
	for (int i = 1; x + i < row; i++) {
		if (isAdd) map[x + i][y]++;
		else map[x + i][y]--;
		if (y - i >= 0) {
			if (isAdd) map[x + i][y - i]++;
			else map[x + i][y - i]--;
		}
		if (y + i < col) {
			if (isAdd) map[x + i][y + i]++;
			else map[x + i][y + i]--;
		}
	}
}
char **addBoard(int row, int col, char board[row][col]) {
	char *p;
	char **r = malloc(sizeof(char*) * row);
	for (int i = 0; i < row; i++) {
		p = malloc(sizeof(char) * col);
		memcpy(p, board[i], col * sizeof(char));
		r[i] = p;
	}
	return r;
}
void dfs(char ****ret, int **returnColumnSizes, int *returnSize, int row, int col, char board[row][col], int map[row][col], int x) {
	if (x >= row) {
		*ret = realloc(*ret, sizeof(char**) * (*returnSize + 1));
		*returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
		(*ret)[*returnSize] = addBoard(row, col, board);
		(*returnColumnSizes)[*returnSize] = row;
		(*returnSize)++;
		return;
	}
	for (int i = 0; i < col; i++) {
		if (map[x][i] == 0) {
			update(row, col, map, board, x, i, 1);
			dfs(ret, returnColumnSizes, returnSize, row, col, board, map, x + 1);
			update(row, col, map, board, x, i, 0);
		}
	}
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
	char board[n][n];
	int map[n][n];
	char ***ret = NULL;
	*returnSize = 0;
	*returnColumnSizes = NULL;
	memset(map, 0, sizeof(int) * n * n);
	memset(board, '.', sizeof(char) * n * n);
	dfs(&ret, returnColumnSizes, returnSize, n, n, board, map, 0);
	return ret;

}
void printBoard(char ***ret, int n, int returnSize, int *returnColumnSizes) {
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < returnColumnSizes[i]; j++) {
			for (int k = 0; k < n; k++) {
				putchar(ret[i][j][k]);
				putchar('\t');
			}
			putchar('\n');
		}
		printf("\n\n");
	}
}
int main(void) {
	int returnSize;
	int *returnColumnSizes;
	char ***ret = solveNQueens(4, &returnSize, &returnColumnSizes);
	printBoard(ret, 4, returnSize, returnColumnSizes);
	return 0;
}
