//找出该坐标所属的横、竖和所属的方块中的集合的并集p, 继而得出p在集合 {1~9}中的补集q
//遍历集合q,如果集合q不为空, 顺序选择集合中的一个元素,记为i,跳转下一个坐标重复上述步骤。
//如果集合q为空,则回溯到上一步, 选择该坐标上的集合q中的下一个元素i+1,跳转下一个坐标重复上述步骤
//直到最后一个坐标集合q不为空, 完成
1
3 4 
int verStore[9][9] = {0},
	horStore[9][9] = {0},
	squareStore[9][9] = {0};

int func(char **board, int r, int c) {
	if (r == 9) return 1;
	int temp = board[r][c] - 0x31;
	if (temp != -3) {
		verStore[r][temp] = 1;
		horStore[c][temp] = 1;
		squareStore[(r / 3) * 3 + c / 3][temp] = 1;
		return func(board, (c + 1) % 9 == 0 ? r + 1 : r, (c + 1) % 9);
	} 
	int p[9] = {0};
	int t;
	for (int i = 0; i < 9; i++) {
		if (verStore[r][i] || horStore[c][i] || squareStore[(r / 3) * 3 + c / 3][i]){
			p[i] = 1;
		} 
	}
	for (t = 0; t < 9;) {
		if (!p[t]) {
			board[r][c] = t + 0x31; 
			verStore[r][t] = 1;
			horStore[c][t] = 1;
			squareStore[(r / 3) * 3 + c / 3][t] = 1;
			if (func(board, (c + 1) % 9 == 0 ? r + 1 : r, (c + 1) % 9)) return 1;
		}
	}
	return 0;
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
	int temp;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardColSize[i]; j++) {
			temp = board[i][j] - 0x31;
			if (temp != -3) {
				verStore[i][temp] = 1;
				horStore[j][temp] = 1;
				squareStore[(r/3) * 3 + c /3][temp] = 1;
			}
		}
	}
	func(board, 0, 0);
}

/** 输入：candidates = [2,3,6,7], target = 7 */
/** 输出：[[2,2,3],[7]] */
int arr[500];

void dfs(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes, int ***ret, int j, int total, int idx) {
	if (j >= candidatesSize) return;
	if (target == total) {
		for (int k = 0; k <= idx; k++) {
			printf("%d %d %d -> ",total, arr[k], idx);
		}
		printf("** ", idx + 1);
		int *p = malloc(sizeof(int) * (idx + 1));
		memcpy(p, arr, (idx + 1) * sizeof(int));
		*ret = realloc(*ret, (*returnSize + 1) * sizeof(int*));
		*returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
		(*ret)[*returnSize] = p;
		(*returnColumnSizes)[*returnSize] = idx + 1;
		(*returnSize)++;
		printf("** %d\n", total);
		return;
	}
	for (int i = 0; candidates[j] * i <= target - total; i++) {
		if (i > 0 ) arr[idx++] = candidates[j];
		dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, j + 1, total + candidates[j] * i, idx);
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	int **ret = NULL;
	*returnSize = 0;
	dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, &ret, 0, 0, 0);
	return ret;
}
int arr[100];

void dfs(int list[][2], int length, int target, int *returnSize, int **returnColumnSizes, int ***ret, int j, int total, int idx) {
	// for (int k = 0; k < idx; k++) {
	//         printf("%d %d %d -> ",total, arr[k], idx);
	//     }
	//     putchar('\n');	
	if (target == total) {
		//  for (int k = 0; k < idx; k++) {
		//     printf("%d %d %d -> ",total, arr[k], idx);
		// }
		// putchar('\n');
		int *p = malloc(sizeof(int) * idx);
		memcpy(p, arr, (idx) * sizeof(int));
		*ret = realloc(*ret, (*returnSize + 1) * sizeof(int*));
		*returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
		(*ret)[*returnSize] = p;
		(*returnColumnSizes)[*returnSize] = idx;
		(*returnSize)++;
		return;
	}
	if (j >= length) return;
	for (int i = 0; i <= list[j][1] && list[j][0] * i <= target - total; i++) {
		if (i > 0 ) arr[idx++] = list[j][0];
		dfs(list, length, target, returnSize, returnColumnSizes, ret, j + 1, total +  list[j][0] * i, idx);
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	int **ret = NULL;
	int map[50] = {0};
	int list[50][2];
	int l = 0;
	*returnColumnSizes = NULL;
	*returnSize = 0;
	for (int i = 0; i < candidatesSize; i++) {
		map[candidates[i]]++;
	}
	for (int i = 0; i < 50; i++) {
		if (map[i] != 0) {
			list[l++][0] = i; 
			list[l][1] = map[i];
		}
	}
	dfs(list, l, target, returnSize, returnColumnSizes, &ret, 0, 0, 0);
	return ret;
}
//求出底座总值q和整个梯形总值p，res = p - q
//
//
//1
int trap(int* height, int heightSize){
	int start,
		end,
		middle,
		valid = 0,
		total = 0,
		p = 0,
		max = 0;

	for (int i = 0; i < heightSize; i++) {
		max = height[i] > max ? height[i] : max;
		p += height[i];
	} 

	for (start = 0, end = 1; end < heightSize; end++) {
		if (!valid) {
			if (height[start] <= height[end]) {
				total += height[start];
				start = end;
				/** printf("%d\n", total); */
			}
			else {
				valid = 1;
			}
		}
		else {
			if (height[end] >= height[start]) {
				total += (end - start) * height[start];
				/** printf("%d %d %d\n", total, start, end); */
				start = end;
				valid = 0;  
			}	
		}
	}
	middle = start;

	for (start = heightSize - 1, end = heightSize - 2; end >= start; end--) {
		if (!valid) {
			if (height[start] <= height[end]) {
				total += height[start];
				start = end;
				/** printf("%d\n", total); */
			}
			else {
				valid = 1;
			}
		}
		else {
			if (height[end] >= height[start]) {
				total += (end - start) * height[start];
				printf("%d %d %d\n", total, start, end);
				start = end;
				valid = 0;  
			}	
		}
	}
	return total + max - p;
}
#define MIN(x,y)((x) < (y) ? (x) : (y))
#define MAX(x,y)((x) < (y) ? (y) : (x))
int trap(int* height, int heightSize){
	int leftMax[heightSize];
	int	rightMax[heightSize];
	int total = 0;

	leftMax[0] = 0;
	rightMax[heightSize - 1] = 0;

	for (int i = 1; i < heightSize; i++) {
		leftMax[i] = MAX(leftMax[i - 1], height[i]);
	}
	for (int i = heightSize - 2; i >= 0; i--) {
		rightMax[i] = MAX(rightMax[i + 1], height[i]);
	}
	for (int i = 0; i < heightSize; i++) {
		total += (MIN(leftMax[i], rightMax[i]) - height[i]);
	}
	return total;
}
#define MIN(x,y)((x) < (y) ? (x) : (y))
#define MAX(x,y)((x) < (y) ? (y) : (x))
int trap(int* height, int heightSize){
	int stack[heightSize];
	int top = -1;
	int total = 0;
	int left;

	for (int i = 0; i < heightSize; i++) {

		while (top > 0 && height[i] > height[stack[top]]) {
			// printf("***%d %d %d\n", stack[top], i, (MIN(height[i], height[stack[top - 1]]) - height[stack[top]]) * (i - stack[top - 1] - 1));
			total += (MIN(height[i], height[stack[top - 1]]) - height[stack[top]]) * (i - stack[top - 1] - 1);
			top--;
		}
		
		if (top == 0 && height[stack[top]] < height[i]){
			stack[top] = i;
		}
        else {
            stack[++top] = i;
        }
		//  printf("%d %d\n", stack[top], height[stack[top]]);
	}
	return total;
}
//
//
char * multiply(char * num1, char * num2){
	
}
