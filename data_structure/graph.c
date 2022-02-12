#include <stdio.h>
int dfs(int **grid, int i, int j, int gridSize, int *gridColSize, int *count) {
	grid[i][j] = 1;
	(*count)++;
	if (i == 0 || i == gridSize -1 || j == 0 || j == gridColSize[i] - 1) return 0;
	int closed = 1;
	if (grid[i - 1][j] == 0)  closed &= dfs(grid, i - 1, j, gridSize, gridColSize, count);
	if (grid[i][j + 1] == 0) closed &= dfs(grid, i, j + 1, gridSize, gridColSize, count);
	if (grid[i + 1][j] == 0) closed &= dfs(grid, i + 1, j, gridSize, gridColSize, count);
	if (grid[i][j - 1] == 0) closed &= dfs(grid, i, j - 1, gridSize, gridColSize, count);
	return closed;
}
int closedIsland(int** grid, int gridSize, int* gridColSize){
	int count;
	int total = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			if (grid[i][j] == 0 && i > 0 && i < gridSize - 1 && j > 0 && j < gridColSize[i] - 1) {
				count = 0;
				if (dfs(grid, i, j, gridSize, gridColSize, &count)) total += count;
			}
		}
	}
	return count;
}
/** [0,0,1,1,0,1,0,0,1,0] */
/** [1,1,0,1,1,0,1,1,1,0] */
/** [1,0,1,1,1,0,0,1,1,0] */
/** [0,1,1,0,0,0,0,1,0,1] */
/** [0,0,0,0,0,0,1,1,1,0] */
/** [0,1,0,1,0,1,0,1,1,1] */
/** [1,0,1,0,1,1,0,0,0,1] */
/** [1,1,1,1,1,1,0,0,0,0] */
/** [1,1,1,0,0,1,0,1,0,1] */
/** [1,1,1,0,1,1,0,1,1,0] */
int dfs(int **grid1, int **grid2, int i, int j, int grid2Size, int *grid2ColSize) {
	grid[i][j] = 1;
	(*count)++;
	if (i == 0 || i == gridSize -1 || j == 0 || j == gridColSize[i] - 1) return 0;
	int closed = 1;
	if (grid[i - 1][j] == 0)  closed &= dfs(grid, i - 1, j, gridSize, gridColSize, count);
	if (grid[i][j + 1] == 0) closed &= dfs(grid, i, j + 1, gridSize, gridColSize, count);
	if (grid[i + 1][j] == 0) closed &= dfs(grid, i + 1, j, gridSize, gridColSize, count);
	if (grid[i][j - 1] == 0) closed &= dfs(grid, i, j - 1, gridSize, gridColSize, count);
	return closed;
}
int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize){
	int count = 0;
	for (int i = 0; i < grid2Size; i++) {
		for (int j = 0; j < grid2ColSize[i]; j++) {
			if (grid2[i][j] == 1) {
				if (dfs(grid1, grid2, i, j, grid2Size, grid2ColSize)) count++;
			}
		}
	}
}
int main(void) {
	int grid[][8] = {
		{1,1,1,1,1,1,1,0}, 
		{1,0,0,0,0,1,1,0},
		{1,0,1,0,1,1,1,0},
		{1,0,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,0}
	};
	printf("%d ", closedIsland((int**)grid, 5, (int []){8,8,8,8,8}));
}
