#include <stdlib.h>
#include <string.h>
#include <graph.h>
#include  "../list.h"
#include  "../set.h"

/** graph init */

void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
	graph->vcount = 0;
	graph->ecount = 0;
	graph->match = match;
	graph->destroy = destroy;

	list_init(&graph->adjlist, NULL);

	return;
}

void graph_destroy(Graph *graph)
{
	adjlist *adjlist;
	while (list_size(&graph->adjlists) > 0)
	{
		if (list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0)
		{
			set_destroy
		}
	}
}
typedef struct {
	int x;
	int y;
	int step;
} Rect;
[
	[1,0,0],
	[1,1,0],
	[1,1,0]
]
#define SIZE 400
#define ADD_QUEUE(val) (queue[++queue_end % SIZE] = val)
#define OUT_QUEUE (queue[(queue_head++) % SIZE])
#define IS_EMPTY (queue_head > queue_end)
#define FLUSH_QUEUE {\
	while (!IS_EMPTY) {\
		free(OUT_QUEUE);\
	}\
	queue_head = 0;\
	queue_end = -1;\
}
#define CREATE_ITEM(a,b,c) {\
	item = (Rect*)malloc(sizeof(Rect));\
	item->x = a;\
	item->y = b;\
	item->step = c;\
}
#define MEM_SET {\
	for (int i = 0; i < gridSize; i++) {\
		for (int j = 0; j < gridColSize[i]; j++) {\
			map[i][j] = 0;\
		}\
	}\
}
// ***
// ***
// ***
const int direction[][2] = {
	{1, 1},
	{1, 0},
	{0, 1},
	{1, -1},
	{-1, 1},
	{0, -1},
	{-1, 0},
	{-1, -1}
};

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
	Rect *queue[SIZE];
	int queue_head = 0;
	int queue_end = -1;
	Rect *item;
	int map[gridSize][gridColSize[0]];

	CREATE_ITEM(0, 0, 1);
	ADD_QUEUE(item);
	MEM_SET;

	while (!IS_EMPTY) {
		item = OUT_QUEUE;
		int step = item->step;
		int x = item->x;
		int y = item->y;
		for (i = 0; i < 8; i++) {
			int m = x + direction[i][0];
			int n = y + direction[i][1];
			if (m >= 0 && m < gridSize && n >= 0 && n < gridColSize[m] && grid[m][n] == 0 && !map[m][n]) {
				if (m == gridSize - 1 && n === gridSize - 1) {
					return step + 1;
				}
				CREATE_ITEM(m, n,step + 1);
				ADD_QUEUE(item);
				map[item->x][item->y] = 1;
			}
		}
	}
	return -1
}
int dir[8][2] = {{1,0},{0,1},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};
struct Node{
	int r;
	int c;
};
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
	if (grid[0][0] != 0)
		return -1;
	if(gridSize == 1)
		return 1;
	int m = gridSize;
	int n = gridColSize[0];
	if (grid[m-1][n-1] != 0)
		return -1;  

	struct Node *que = (struct Node *)malloc(sizeof(struct Node)*m*n);
	int left = 0;
	int right = 0;
	que[right].r = 0;
	que[right].c = 0; right++;
	grid[0][0] = 1;
	while (left < right) {
		/** int num = right - left; */
		/** for (int i = 0; i < num; i++) { */
		int r = que[left].r;
		int c = que[left].c; left++;
		for (int j = 0; j < 8; j++) {
			int nr = r + dir[j][0];
			int nc = c + dir[j][1];
			if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 0) {
				continue;
			}

			if (nr == m -1 && nc == n -1) {
				return grid[r][c] + 1;
			}
			grid[nr][nc] = grid[r][c] + 1;
			que[right].r = nr;
			que[right].c = nc; right++;
		}
		/** } */
	}

	return -1;
}
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
	int m = matSize;
	int n = matColSize[0];
	int visited[m][n];
	const dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	int **ret = malloc(sizeof(int*) * m);
	*returnSize = m;
	*returnColumnSizes = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		ret[i] = malloc(sizeof(int) * n);
	}

	int queue[400][2];
	int head = 0;
	int end = -1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!mat[i][j]) {
				queue[++end][0] = i;
				queue[end][1] = j;
				ret[i][j] = 0;
				visited[i][j] = 1;
			}
		}
	}

	while (end >= head) {
		int *item = queue[head++];

		for (int i = 0; i < 4; i++) {
			int m1 = item[0] + dirs[i][0];
			int m2 = item[1] + dirs[i][1];

			if (m1 >= 0 && m1 < m && m2 >= 0 && m2 < n && mat[m][n] && !visited[m][n]) {
				queue[++end][0] = m1;
				queue[end][1] = m2;
				ret[m1][m2] = ret[item[0]][item[1]];
				visited[m1][m2] = 1;
			}
		}
	}
	return ret;
}
//[[0,1]
//[1,0]]
//
//[[0,1,0],
//[0,0,0],
//[0,0,1]]
//
//[[1,1,1,1,1],
//[1,0,0,0,1],
//[1,0,1,0,1],
//[1,0,0,0,1],
//[1,1,1,1,1]]
//
//[[0,0,0,0,0,0],
//[0,1,0,0,0,0],
//[1,1,0,0,0,0],
//[1,1,0,0,0,0],
//[0,0,0,0,0,0],
//[0,0,1,1,0,0]]
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){

	int m = matSize;
	int n = matColSize[0];

	int **ret = malloc(sizeof(int*) * m);
	*returnSize = m;
	*returnColumnSizes = malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) {
		ret[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			ret[i][j] = !mat[i][j] ? : 0 : INT_MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ( i > 0) {
				ret[i][j] = MIN(ret[i][j], ret[i - 1][j] + 1);
			}
			if (j > 0) {
				ret[i][j] = MIN(ret[i][j], ret[i][j-1] + 1);
			}
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i < m - 1) {
				ret[i][j] = MIN(ret[i][j], ret[i + 1][j] + 1);
			}
			if (j < n - 1) {
				ret[i][j] = MIN(ret[i][j], ret[i][j + 1] + 1);
			}
		}
	}

	return ret;
}
#define SIZE 10000
const dirs[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int **grid, int gridSize, int gridColSize, int x, int y, int **visited, int island_num) {
	if (grid[i][j] == island_num) return;
	for (int i = 0; i < 4; i++) {
		int i1 = x + dirs[i][0];
		int j1 = y + dirs[i][1];
		if (i1 >= 0 && i1 < gridSize && j1 >= 0 && j1 < gridColSize && grid[i1][j1] == 1) {
			grid[i][j] = island_num;
			dfs(grid, gridSize, gridColSize, i1, j1, visited, island_num);
		}
	}
}

int shortestBridge(int** grid, int gridSize, int* gridColSize){
	int m = gridSize;
	int n = gridColSize[0];
	queue[SIZE][2];
	int head = 0;
	int end = -1;

	int island_num = 1;
	int distance = 0;

	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				++island_num;
				dfs(grid, m, n, i, j, visited, island_num);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 2) {
				queue[++end][0] = i;
				queue[end][1] = j;
			}
		}
	}

	while (head <= end) {
		int *item = queue[head++%SIZE];
		for (int i = 0; i < 4; i++) {
			int i1 = item[0] + dirs[i][0];
			int j1 = item[1] + dirs[i][1];
			if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && grid[i1][j1] != 2) {
				if (grid[i1][j1] == 0) {
					gird[i1][j2] = grid[item[0]][item[1]] + 2;
				}
				else if (grid[i1][j1] >= 4) continue;
				else {
					return distance = (grid[item[0][item[1]]] + 2) / 2;
				}
			}
		}
	}
	return distance;
}

int main() {
}


