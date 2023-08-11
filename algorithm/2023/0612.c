int averageValue(int* nums, int numsSize){
	int sum = 0;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 6 == 0) {
			sum += (nums[i] % 6 == 0 ? nums[i] : 0);
			count++;
		}
	}
	return sum / count;

}
//从末尾开始依次向前遍历
//int start = -1;
//int end = -1;
//length = 0;
// for (i:nums) {
//  int last = length == 0 ? nums[numsSie - 1] : i + length;
// 	for (int j = i, j <) {
// 		dp[j] = dp[j] + nums[i]
//		if (ap[j] >= target) {
//			length = j - i + 1;
//		}
// 	}
// 	return length;
// }
int find(int sum[], int l, int r, int target) {
	if (sum[r] < target)  return -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (sum[mid] >= target) {
			r = mid - 1;
		}
		else if (sum[mid] < target) {
			l = mid + 1;
		}
	}
	return l;
}
int minSubArrayLen(int target, int* nums, int numsSize){
	int length = INT_MAX;
	int sum[numsSize + 1];
	sum[0] = 0;
	for (int i = 1; i <= numsSize; i++) {
		sum[i] = sum[i - 1] + nums[i - 1];
	}
	for (int i = 1; i <= numsSize; i++) {
		int t = target + sum[i - 1];
		int res = find(sum, 1, numsSize, t);
		if (res != -1) {
			length = fmin(length, (res - i + 1));
		}
	}
	return length == INT_MAX ? 0 : length;
}

int minSubArrayLen(int target, int* nums, int numsSize){
	int length = INT_MAX;
	int sums = 0;
	int start = 0;

	for (int i = 0; i < numsSize; i++) {
		while (sums += nums[i] >= target) {
			length = fmin(length, i - start + 1);
			sums -= nums[start];
			start++;
		}
	}

	return length == INT_MAX ? 0 : length;
}
//求出 差值 数组
//
//reward1 = [3,3,1,1] k = 2
//reward2 = [4,4,3,3]
// 1 1 2 2
int cmp(const int *a, const int *b) {
	return *b - *a;
}
int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k){
	int diff[reward1Size];
	int maxSum = 0;
	int r1 = k,
		r2 = reward1Size - k;

	for (int i = 0; i < reward1Size; i++) {
		diff[i] = reward1[i] - reward2[i];
		maxSum += fmax(reward1[i], reward2[i]);
	}
	qsort(diff, reward1Size, sizeof(int), cmp)
		for (int i = 0; i < reward1Size; i++) {
			if (diff[i] > 0) {
				if (r1 > 0){
					r1--;
				} 
				else {
					maxSum -= fabs(diff[i]);
					r2--;
				}
			}
			else {
				if (r2 > 0) {
					r2--;
				} else {
					maxSum -= fabs(diff[i]);
					r1--;
				}
			}
		}
	return maxSum;
}
//1,0,2,0,0,6,7,0,8,6
//1, 4, 0, 2,0,0
int* applyOperations(int* nums, int numsSize, int* returnSize){
	for (int i = 0, last = -1; i < numsSize - 1;) {
		if (nums[i] == nums[i + 1]) {
			nums[i] = 2 * nums[i];
			nums[i + 1] = 0;
			if (nums[i] != 0) {
				int temp = nums[i];
				nums[i] = 0;
				nums[last + 1] = temp; 
				last++;
			}
			i += 2;
		}
		else {
			if (nums[i] != 0) {
				int temp = nums[i];
				nums[i] = 0;
				nums[last + 1] = temp; 
				last++;
			}

			i++;
		}
	}
	*returnSize = numsSize;
	return nums;
}

//[
//[3,2,1],
//[1,7,6],
//[2,7,7]]
//
3 3
3 2
2 1
1 2
1 3
7 1
6 2
2 3
7 1
7 2
//[[2,30,400],
//[40,7,6],
//[300,7,7]]
int equal(int row, int col, int gridSize, int **grid) {
	for (int i = 0; i < gridSize; i++) {
		if (grid[row][i] != grid[i][col]) return 0;
	}
	return 1;
}
int equalPairs(int** grid, int gridSize, int* gridColSize){

	int equalPairsCount = 0;
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (equal(i, j, gridSize, grid)) equalPairsCount++;
		}
	}

	return equalPairsCount;
}

int rowSize, colSize;
int directions[][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
int getIndex(int array[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (array[i] == value) 
			return i;
	}
	return -1;
}
int shortestPathAllKeys(char ** grid, int gridSize){

	const int QUEUE_SIZE = 32;
	int x, y;
	rowSize = gridSize;
	colSize = strlen(grid[0]);
	int map[27] = {0};
	int keySize = 0;

	int step[rowSize][colSize][128];
	int queue[QUEUE_SIZE][3];
	int start = -1,
	end = 0;

	memset(keyStr, 0, 7);

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			memset(step[i][j], -1, sizeof(step[i][j]));
			if (grid[i][j] == '@') {
				x = i;
				y = j;
			}
			else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
				map[keySize++] = grid[i][j];
			}
		}
	}
	int *p = queue[end++ % QUEUE_SIZE];
		
	p[0] = x;
	p[1] = y;
	p[2] = 0;
	
	step[x][y][0] = 0;

	while (start < end) {
		p = queue[++start % QUEUE_SIZE];
		int x = p[0],
		y = p[1],
		z = p[2];

		for (int i = 0; i < 4; i++) {
			int nx = x + directions[i][0],
			ny = y + directions[i][1];
			if (nx >= 0 && nx < rowSize && ny >= 0 && ny < colSize && grid[nx][ny] != '#') {
				if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {
					if (step[nx][ny][z] == -1) {
						step[nx][ny][z] = step[x][y][z] + 1;
						p = queue[end++ % QUEUE_SIZE];
						p[0] = nx;
						p[1] = ny;
						p[2] = z;
					}
				}
				else if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
					int idx = getIndex(map, keySize, grid[nx][ny]) + 1;
					if (step[nx][ny][z | (1 << idx)] == -1) {
						step[nx][ny][z | (1 << idx)] = step[x][y][z] + 1;
						p = queue[end++ % QUEUE_SIZE];
						p[0] = nx;
						p[1] = ny;
						p[2] = z | (1 << idx);
						if ((z | (1 << idx)) == (1 << keySize) - 1) {
							return step[nx][ny][z | (1 << idx)];
						} 
					}
				}
				else {
					int relatedKey = grid[nx][ny] + 0x20;
					int idx = getIndex(map, keySize, grid[nx][ny]) + 1;
					if (step[nx][ny][z] == -1 && (z && 1 << idx) != 0) {
						step[nx][ny][z] = step[x][y][z] + 1;
						p = queue[end++ % QUEUE_SIZE];
						p[0] = nx;
						p[1] = ny;
						p[2] = z;
					}
				}
			}
		}
	}
	return -1;
}
 #
#@#    0 4
 #

 ##
# @#   1 7
 ##

 ##
#  #   2 9
#@#    
 #

 ###
#@  #   3 11
 # #    
  #

  #
 #@#
#   #   4 12
 # #    
  #

3  4
5  8
7  12
15 * 4
  #
 # ##
#   @#   5 15
 # ##   
  #

    $
   $#$
  $# #$
 $#   #$    
  $# #$   
   $#$
    $
