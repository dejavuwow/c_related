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
int rowSize;
int colSize;
int dirs[][2] = {
	{1,0},
	{0,-1},
	{-1,0},
	{0,1}
};
void bfs(char **board, int row, int col, int map[row][col]) {
	int closeSides = 0;
	for (int i = 0; i < 4; i++) {
		int row_n = row + dirs[i][0];
		int col_n = col + dirs[i][1];
		if (row_n <= 0 || row_n >= rowSize || col_n <= 0 || col_n >= colSize) continue;
		else if (board[row_n][col_n] == 'X' || map[row_n][col_n]) {
			closeSides++;
		}
		else if (board)
		map[row_n][col_n] = 1;
		bfs(board, row_n, col_n, map);

	}
}
void solve(char** board, int boardSize, int* boardColSize){
	rowSize = boardSize;
	colSize = boardColSize[0];
	int temp[rowSize][colSize];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (i <= 0 || i >= rowSize - 1 || j <= 0 || j >= colSize - 1 || temp[i][j] || board[i][j] == 'X') continue;
			bfs

		}
	}

}
