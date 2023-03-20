//dfs
void inOrder(struct TreeNode *root, int value, int *sum) {
	value = value * 10 + root->val;
	if (!root->left && !root->right) {
		*sum = *sum += value;
		return;
	}
	else {
		if (root->left) {
			inOrder(root->left, value, sum);
		}
		if (root->right) {
			inOrder(root->right, value, sum);
		}
	}
}
int sumNumbers(struct TreeNode* root){
	int sum = 0;
	inOrder(root, 0, &sum);
	return sum;
}
//bfs
//2 + 4 + 8 + 16 + 32。。。1000
//210 = 1024
//512

int sumNumbers(struct TreeNode* root){
	struct TreeNode *nodeQueue[0x200];
	int valQueue[0x200];
	int head = 0;
	int end = -1;
	int sum = 0;

#define ENQUEUE(node, val) {\
	end++;\
	nodeQueue[end % 0x200] = node;\
	valQueue[end % 0x200] = val;\
}

#define DEQUEUE(ptr, var) {\
	*ptr = nodeQueue[head % 0x200];\
	*var = valQueue[head % 0x200];\
	head++;\
}

	ENQUEUE(root, root->val);
	while (head <= end) {
		struct TreeNode *temp;
		int val;
		DEQUEUE(&temp, &val);
		if (!temp->left && !temp->right) {
			sum += val;
		}
		else {
			if (temp->left) {
				ENQUEUE(temp->left, val * 10 + temp->left->val);
			}
			if (temp->right) {
				ENQUEUE(temp->right, val * 10 + temp->right->val);
			}
		}
	}
return sum;
}
/** ["O","X","X","O","X"], */
/** ["X","O","O","X","O"], */
/** ["X","O","X","O","X"], */
/** ["O","X","O","O","O"], */
/** ["X","X","O","X","O"] */
/**  */
/** ["O","X","X","O","X"], */
/** ["X","X","X","X","O"], */
/** ["X","X","X","X","X"], */
/** ["O","X","O","O","O"], */
/** ["X","X","O","X","O"]] */
/**  */
/** ["O","X","X","O","X"], */
/** ["X","X","X","X","O"], */
/** ["X","X","X","O","X"], */
/** ["O","X","O","O","O"], */
/** ["X","X","O","X","O"] */

int rowSize;
int colSize;
int dirs[][2] = {
	{1,0},
	{0,-1},
	{-1,0},
	{0,1}
};
//   O {
//		visited  + 1
//		unvisited  1 edge   return  2 unedge bfs()
//   }
//   X {
//   	visited + 1
//   	unvisited
//   }
void bfs(char **board, int row, int col, int map[rowSize][colSize]) {
	for (int i = 0; i < 4; i++) {
		int row_n = row + dirs[i][0];
		int col_n = col + dirs[i][1];
		if (row_n >= 0 && row_n < rowSize && col_n >= 0 && col_n < colSize && !map[row_n][col_n] && board[row_n][col_n] == 'O') {
			map[row_n][col_n] = 1;
			bfs(board, row_n, col_n, map);
		}
	}
}
void solve(char** board, int boardSize, int* boardColSize){
	rowSize = boardSize;
	colSize = boardColSize[0];
	int temp[rowSize][colSize];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (board[i][j] == 'O' && !temp[i][j] && (i == 0 || i == rowSize - 1 || j == 0 || j == colSize - 1))
			{
				map[i][j] = 1;		
			}
		}
	}

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (board[i][j] == 'O' && !map[i][j]) {
				board[i][j] = 'X';
			}
		}
	}
}
// find x node
// calculate x min
//
int calculateNodeNums(struct TreeNode *root) {
	if (root == NULL) return 0;
	return 1 + calculateNodeNums(root->left) + calculateNodeNums(root->right);
}
bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
	struct TreeNode *queue[0x40];
	struct TreeNode x_node = NULL;
	int head = 0,
		end = -1;
	queue[++end % 0x40] = root;
	while (head <= end) {
		x_node = queue[head++ % 0x40];
		if (x == x_node->val) break;
		if (x_node->left) queue[++end % 0x40] = x_node->left;
		if (x_node->right) queue[++end % 0x40] = x_node->right;
	}

	int nodeLeftNums = calculateNodeNums(x_node->left);
	int nodeRightNums = calculateNodeNums(x_node->right);
	int nodeParentNums = n - 1 - nodeLeftNums - nodeRightNums;
	return  nodeLeftNums > n - nodeLeftNums || nodeRightNums > n - nodeRightNums || nodeParentNums > n - nodeParentNums;
}


int l;
char *genString(char *s, int start, int end) {
	int size = end - start + 2;
	char *ret = malloc(sizeof(char) * size);
	ret[size - 1] = '\0';
	memcpy(ret, s, size);
	return ret;
}
void dfs(char *s, int index, int p[l][l], char *current[l], int size, char ***ret, int *returnSize, int **returnColumnSizes) {
	if (index == l) {
		ret[*returnSize] = current;
		(*returnColumnSizes)[*returnSize] = size;
		(*returnSize)++;
		return;
	}
	for (int i = index; i < l; i++) {
		if (p[index][i]) {
			current[size] = genString(s, index, i);
			dfs(s, index, p, current, size + 1, ret, returnSize, returnColumnSizes);
		}
	}
}
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
	l = strlen(s);
	int size = pow(2, n - 1);
	int p[l][l];
	char *current[l];
	char ***ret = malloc(sizeof(char**) * size);
	*returnSize = 0;
	*returnColumnSizes = malloc(sizeof(int) * size);
	for (int i = 0; i < l; i++) {
		p[i][i] = 1;
	}

	for (int i = l - 1; i >= 0; i--) {
		for (int j = i; j < l; j++) {
			if (i == j) {
				p[i][j] = 1;
			}
			else {
				p[i][j] = s[i] == s[j] ? p[i - 1][j - 1] : 1;
			}
		}
	}

	dfs(s, 0, p, current, 0, ret, returnSize, returnColumnSizes);
	return ret;

}
//msmmm
//长度为l的字符串s, 分割次数为res
//如果s[0][l - 1]为回文串，则结果为1，显然是最少的分割次数
//如否，遍历i从 1 ~ l - 1, 直到s[i][l - 1]为回文串
//如果s[0][i - 1]为回文串则 res = 2; 否则 res[] =
/*
 *
 j > i
 ***a[0, i], [i + 1, l - 1], m[i] + 1
 a[0, j], [j + 1, l - 1], m[j] + 1
 * */
int minCut(char * s){
	int l = strlen(s);
	int p[l][l];
	int min[l];

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			p[i][j] = 1;
		}
	}

	for (int i = l - 1; i >= 0; i--) {
		for (int j = i + 1; j < l; j++) {
			p[i][j] = s[i] == s[j] && s[i + 1][j - 1];
		}
	}

	for (int i = 0; i < l; i++) {
		min[i] = INT_MAX;
		if (p[0][i]) {
			min[i] = 1;
		}
		else {
			for (int j = 1; j <= i; j++) {
				if (p[j][i]) {
					min[i] = fmin(min[i], min[j - 1] + 1);
				}
			}
		}
	}
	return min[l - 1];
}
int candy(int* ratings, int ratingsSize){
	int incline = 0;
	for (int i = 0; i < ratingsSize; i++) {
		
	}
}
