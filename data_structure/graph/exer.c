#include <stddio.h>
//   *
//	***
// *****
//*******
// *****
// 	***
// 	 *
//1 3  98 + 2
//4 8
#define SIZE 200
//[["+",".","+","+","+","+","+"],
//["+",".","+",".",".",".","+"],
//["+",".","+",".","+",".","+"],
//["+",".",".",".","+",".","+"],
//["+","+","+","+","+",".","+"]]
const int dirs[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize){
	int m = matSize;
	int n = matColSize[0];
	int queue[200][2];
	int head = 0;
	int end = -1;

	queue[++end%SIZE][0] = entrance[0];
	queue[end%SIZE][1] = entrance[1];
	maze[entrance[0]][entrance[1]] = 0;

	while (head <= end) {
		int *item = queue[head--%SIZE];
		for (int i = 0; i < 4; i++) {
			int r = item[0] + dirs[i][0];
			int c = item[1] + dirs[i][1];
			if (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == '.') {
				maze[r][c] = maze[item[0]][item[1]] + 1;
			}
			if (r == 0 || r == mazeSize - 1 || c == 0 || c == mazeColSize - 1) {
				return maze[r][c];
			}
		}
	}
	return -1;
}
/** a3-b3=a3-b3+a2b-a2b */
/** =a2(a-b)+b(a2-b2) */
/** =a2(a-b)+b(a+b)(a-b) */
/** =[a2+b(a+b)](a-b) */
/** =(a-b)(a2+ab+b2) */
//[[1,2,3,4], [2,3,4],[3,4], [4], []]
//01234
//01 34
//012 4
//01  4
//0 234
//0 2 4
//034
//04
//=======
//0     4
//0 1   4
//0  2  4
//0	12  4	
//0   3 4
//0 1 3 4
//0  23 4
//0 123 4
//输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
//输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
//
void func(int **graph, int *graphColSize, int ***ret, int *curSize, int **returnColumnSizes, int *row, int rowSize, int targetIndex, int targetSize) {
	if (rowSize == 0) return;
	int lastIndex = *curSize - 1;
	*curSize = *curSize + rowSize - 1;
	*returnColumnSizes = realloc(*returnColumnSizes, sizeof(int*) * *curSize);

	if (rowSize > 1) {
		(*ret) = realloc(*ret, sizeof(int*) * *curSize);
		for (int i = 1; i < rowSize; i++) {
			memcpy((*ret)[lastIndex + i], (*ret)[targetIndex], targetSize * sizeof(int));
		}
	}

	for (int i = 0; i < rowSize; i++) {
		(*returnColumnSizes)[lastIndex + i] = targetSize + 1;
		(*ret)[lastIndex + i] = realloc((*ret)[lastIndex + i], sizeof(int) * (targetSize + 1));
		(*ret)[lastIndex + i][targetSize] = row[i];
		func(graph, graphColSize, ret, curSize, returnColumnSizes, graph[row[i]], graphColSize[row[i]], lastIndex + i, targetSize + 1);
	}
}
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
	int **ret = NULL;
	*returnSize = 0;
	*returnColumnSizes = NULL;

	(*returnColumnSizes) = realloc(*returnColumnSizes, sizeof(int));
	returnColumnSizes[(*returnSize)++] = 1;
	ret = realloc(ret, returnSize * sizeof(int*));
	ret[0] = malloc(sizeof(int));
	ret[0][0] = 0;

	func(graph, graphColSize, &ret, *returnSize, int **returnColumnSizes, graph[0], graphColSize[0], 0, 1);
	return ret;
	
}
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
	

}
#define SIZE 1001
int visited[SIZE] = {0};
int n;
int num;
bool ret;
void dfs(int **rooms, int *roomsColSize, int j) {
	if (num == n) {
		ret = true;
		return;
	}
	for (int i = 0; i < roomsColSize[i]; i++) {
		if (!visited[rooms[j][i]]) {
			num++;
			stack[++top] = rooms[j][i];
			visited[rooms[j][i]] = 1;
			dfs(rooms, roomsColSize, rooms[j][i]);
			top--;
		}
	}
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
	n = roomsSize - 1;
	num = 0;
	ret = false;
	num++;
	stack[++top] = 0;
	visited[0] = 1;
	dfs(rooms, roomsColSize, 0);
	
	return ret;
}
void dfs(int **isConnected, int isConnectedSize, int *isConnectedColSize, int m, int n) {
	isConnected[m][n] = 2;
	isConnected[n][m] = 2;
	for (int i = 0; i < isConnected[n]; i++) {
		if (i != n && (isConnected[n][i] == 1)) {
			dfs(isConnected, isConnectedSize, isConnectedColSize, n, i);
		}
	}
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
	int num = 0;
	for (int i = 0; i < isConnectedSize; i++) {
		for (int j = 0; j < isConnectedColSize[i]; j++) {
			if (i != j && isConnected[i][j] == 1) {
				num++;
				dfs(isConnected, isConnectedSize, isConnectedColSize, i, j);
			}
		}
	}
	return num;
}
void dfs() {

}
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
	if (connectionsSize < n - 1) return -1;
	for (int i = 0; i < connectionsSize; i++) {
		
	}
}

int main(void) {

	return 0;
}
