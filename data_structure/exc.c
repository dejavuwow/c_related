//node ../../../node_modules/.bin/husky add .husky/commit-msg 'npx --no -- commitlint --edit "$1"'
typedef struct Node Node;
#define MAX 2048
#define log2(v) (log10(v) / log10(2))
#define ADD_QUEUE(queue, val) (queue[++end % 2047] = val)
#define OUT_QUEUE(queue) (queue[(head--) % 2047])
#define IS_EMPTY (head > end)
struct Node* connect(struct Node* root) {
	Node *queue[MAX];
	Node *node = root;
	Node *pre;
	int head = 0;
	int end = -1;
	int size = 0;
	double ex;
	ADD_QUEUE(queue, root);
	while (!IS_EMPTY) {
		size++;
		ex = log2((double)(size+1));
		node = OUT_QUEUE(queue);
		if (ex == (double)(int)ex) {
			node->next = NULL;
		} else {
			if (!IS_EMPTY) {
				node->next = queue[head];
			}
		}
		if (node->left) {
			ADD_QUEUE(queue, node->left);
		}
		if (node->right) {
			ADD_QUEUE(queue, node->right);
		}
	}
	return root;
}
typedef struct TreeNode TreeNode;
int countNodes(TreeNode node) {
	if (node == NULL) return 0;
	return countNodes(node->left) + countNodes(node->right) + 1;
}
int kthSmallest(struct TreeNode* root, int k){
	int count = countNodes(root->left);
	if (count + 1 > k) {
		return kthSmallest(root->left, k);
	}
	else if (count + 1 == k) return root->val;
	return kthSmallest(root->right, k-count0);
}
/** ["1","1","1"] */
/** ["0","1","0"] */
/** ["1","1","1"] */
int is_new_island(char **grid, int i, int j) {
	while
}

/** [1,1,1] */
/** [1,1,0] */
/** [1,0,1] */

/** [2,2,2] */
/** [2,2,0] */
/** [2,0,1] */

/** [0,0,0] */
/** [0,1,1] */

echo "#!/bin/sh\n\r . "$(dirname "$0")/_/husky.sh"\n\r npx --no-install commitlint --edit $1" > commitlint.config.js
int numIslands(char** grid, int gridSize, int* gridColSize){
	int t = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			if (IS_NEW_ISLAND(i, j)) t++;
		}
	}
	return t;
}
void draw(int **image, int imageSize, int* imageColSize, int i, int j, int oldColor int newColor) {
	if (i >= 0 && i < imageSize && j >= 0 && j < imageColSize[i] && image[i][j] == oldColor) {
		image[i][j] = newColor;
		draw(image, imageSize, imageColSize, i - 1, j);
		draw(image, imageSize, imageColSize, i, j+1);
		draw(image, imageSize, imageColSize, i + 1, j);
		draw(image, imageSize, imageColSize, i, j - 1);
	}
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){

	*returnSize = imageSize;
	*returnColumnSizes = imageColSize;
	draw(image, imageSize, imageColSize, sr, sc, image[sr][sc], newColor);

}
void dfs(char **grid, int i, int j, int gridSize, int *gridColSize, int *count) {
	(*count)++;
	grid[i][j] = '0';
	if (i - 1 >= 0 && grid[i][j] == '1') dfs(grid, i - 1, j, gridSize, gridColSize, count);
	if (j + 1 < gridColSize[i] && grid[i][j] == '1') dfs(grid, i, j + 1, gridSize, gridColSize, count);
	if (i + 1 < gridSize && grid[i][j] == '1') dfs(grid, i + 1, j, gridSize, gridColSize, count);
	if (j - 1 >= 0 && grid[i][j] == '1') dfs(grid, i, j - 1, gridSize, gridColSize, count);
}
int numIslands(char** grid, int gridSize, int* gridColSize){
	int *count = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			if (grid[i][j] == '1') {
				dfs(grid, i, j, gridSize, gridColSize, count);
			}
		}
	}
	return gri
}
void dfs(char **grid, int i, int j, int gridSize, int *gridColSize , int *current) {
	grid[i][j] = '0';
	(*current)++;
	if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j, gridSize, gridColSize, current);
	if (j + 1 < gridColSize[i] && grid[i][j + 1] == '1') dfs(grid, i, j + 1, gridSize, gridColSize, current);
	if (i + 1 < gridSize && grid[i + 1][j] == '1') dfs(grid, i + 1, j, gridSize, gridColSize, current);
	if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1, gridSize, gridColSize, current);
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int max = 0;
	int current;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			if (grid[i][j] == '1') {
				current = 0;
				dfs(grid, i, j, gridSize, gridColSize, &current);
				max = max < current ? current : max;
			}
		}
	}
	return max;
}
int dfs(char **grid, int i, int j, int gridSize, int *gridColSize) {
	grid[i][j] = 1;
	if (i == 0 || i == gridSize -1 || j == 0 || j == gridColSize[i] - 1) return 0;
	int closed = 1;
	if (grid[i - 1][j] == 0)  closed &= dfs(grid, i - 1, j, gridSize, gridColSize);
	if (!closed) return 0;
	if (grid[i][j + 1] == 0) closed &= dfs(grid, i, j + 1, gridSize, gridColSize);
	if (!closed) return 0;
	if (grid[i + 1][j] == 0) closed &= dfs(grid, i + 1, j, gridSize, gridColSize);
	if (!closed) return 0;
	if (grid[i][j - 1] == 0) closed &= dfs(grid, i, j - 1, gridSize, gridColSize);
	return closed;
}
int closedIsland(int** grid, int gridSize, int* gridColSize){
	int count = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			if (grid[i][j] == 0 && i > 0 && i < gridSize - 1 && j > 0 && j < gridColSize[i] - 1) {
				if (dfs(grid, i, j, gridSize, gridColSize)) count++;
			}
		}
	}
	return count;
}
#define MEM_SET {\
	for (int i = 0; i < heightsSize; i++) {\
		for (int j = 0; j < heightsColSize[i]; j++) {\
			map[i][j] = 0;\
		}\
	}\
}
void dfs(char **grid, int i, int j, int gridSize, int *gridColSize, int **map, int *pfind, int *afind) {
	map[i][j] = 1;
	if (i  == 0 || j == 0) {
		*pfind = 1;
	}
	if (i == gridSize - 1 || j == gridColSize[i] - 1) {
		*afind = 1;
	}
	if (i - 1 >= 0 && grid[i- 1][j] <= grid[i][j] && !map[i-1][j]) {
		dfs(grid, i - 1, j, gridSize, gridColSize, map, pfind, afind);
	}
	if (j + 1 < gridColSize[i] && grid[i][j + 1] <= grid[i][j] && !map[i][j + 1]) {
		dfs(grid, i, j + 1, gridSize, gridColSize, map, pfind, afind);
	}
	if (i + 1 < gridSize && grid[i+ 1][j] <= grid[i][j] && !map[i + 1][j]) {
		dfs(grid, i + 1, j, gridSize, gridColSize, map, pfind, afind);
	}
	if (j - 1 >= 0 && grid[i][j - 1] <= grid[i][j] && !map[i][j-1]) {
		dfs(grid, i , j - 1, gridSize, gridColSize, map, pfind, afind);
	}
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
	int map[heightsSize][heightsColSize[0]];
	int pfind;
	int afind;
	*returnSize = 0;
	int *temp;
	int **returnGrid = NULL;
	*returnColumnSizes = NULL;

	for (int i = 0; i < heightsSize; i++) {
		for (int j = 0; j < heightsColSize[i]; j++) {
			MEM_SET;
			pfind = 0;
			afind = 0;
			dfs(heights, i, j, heightsSize, heightsColSize, map, &pfind, &afind);
			if (pfind && afind) {
				returnGrid = (int**)realloc(returnGrid, (*returnSize + 1) * sizeof(int*));
				*returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
				(*returnColumnSizes)[*returnSize] = 2;
				temp = (int*)malloc(sizeof(int) * 2);
				temp[0] = i;
				temp[1] = j;
				returnGrid[*returnSize] = temp;
			}
		}
	}
	return returnGrid;
}
