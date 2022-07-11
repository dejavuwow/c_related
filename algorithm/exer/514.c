//1234567
//
//123
//234
//345
int size,
	max;
int total = 0;
void gen(int **ret, int *temp, int index, int start) {
	if (start > max) return;
	if (size == index) {
		for (int i = 0; i < size; i++) {
			printf("%d ", temp[i]);
		}
		putchar('\n');
		int list = malloc(sizeof(int) * size);
		memcpy(list, temp, size * sizeof(int));
		ret[total++] = list;
		return;
	}
	for (int i = 0; i <= max - size; i++) {
		temp[index + i] = start + i;
		gen(ret, temp, index + i + 1, start + i + 1);
	}
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
	size = k;
	max = n;
	int l = 1;
	for (int i = 0; i < k; i++) {
		l *= n--;
	}
	int temp[size];
	int **ret = malloc(sizeof(int*) *  (l / 2));
	gen(ret, temp, 0, 1);
	*returnColumnSizes = malloc(sizeof(int) * total);
	for (int i = 0; i < total; i++) {
		(*returnColumnSizes)[i] = k;
	}
	*returnSize = total;
	return ret;
}
//[1,2,3]
int total;
int l;
int *getSet(int *temp, int size) {
	int *list = malloc(sizeof(int) * size);
	memcpy(list, temp, size * sizeof(int));
	return list;
}
void gen(int *nums, int **ret, int *temp, int index, int start, int *size) {
	for (int i = start; i < l; i++) {
		temp[index] = nums[i];
		ret[total] = getSet(temp, index + 1);
		size[total++] = index + 1;
		gen(nums, ret, temp, index + 1, i + 1, size);
	}
}

#define MAX 0x3ff
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int temp[numsSize];
	l = numsSize;
	total = 0;
	int **ret = malloc(sizeof(int*) * );
	int *size = malloc(sizeof(int) * 1000);
	size[total++] = 0; 
	gen(nums, ret, temp, 0, 0, size);
	*returnSize = total;
	*returnColumnSizes = size;

	return ret;
}
//[
//[ABCE]
//[SFES]
//[ADEE]
//]
//ABCESEEEFS
int direction[][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};
int m, n, l;
bool find;
void dfs(char **board, char *word, int map[m][n], int x, int y, int index) {
	if (index == l) {
		find = true;	
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x1 = direction[i][0] + x,
			y1 = direction[i][1] + y;

		// if (x1 == 2 && y1 == 2) {
		//     printf("%c %d %c \n",board[x1][y1], map[x1][y1], word[index]);
		// }

		if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !map[x1][y1] && word[index] == board[x1][y1]) {
			map[x1][y1] = 1;
			if (dfs(board, word, map, x1, y1, index + 1)) return true;
			map[x1][y1] = 0;
		}
	}
	return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
	m = boardSize,
	  n = boardColSize[0];
	int total = m * n;
	l = strlen(word);
	int list[l];
	int map[boardSize][boardColSize[0]];
	find = false;
#define MEMSET {\
	for (int i = 0; i < boardSize; i++) {\
		for (int j = 0; j < boardColSize[i]; j++) {   \
			map[i][j] = 0;\
		}\
	}\
}
	MEMSET;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardColSize[i]; j++) {
			if (board[i][j] == word[0]) {
				map[i][j] = 1;
				dfs(board, word, map, i, j, 1);  
				map[i][j] = 0;    
				if (find) return true;	
			}
		}
	}
return false;
}
//11122233334444 2 2 1
//11122233334444 2 3 1 
//11222233334444 3 4 1
//11222233334444 4 5 2
//11222233334444 4 6 2
//11223
int removeDuplicates(int* nums, int numsSize){
	int p1 = 2,
		p2 = 2;

	while (p2 < numsSize) {
		if (nums[p2] != nums[p1 - 2]) {
			nums[p1] = nums[p2];
			p1++;
		}
		p2++;
	}
	return p1 - 1;
}


bool search(int* nums, int numsSize, int target){
	int left = 0,
		right = numsSize - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] == target) return true;
		else {
			if (nums[mid] >= nums[left]) {
				if (nums[mid] > target && nums[left] <= target) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && nums[right] >= target) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
	}
	return false;
}
// 1/2   x + 3/2x = 1
// 2/3 + (1 - 2/3) * /
