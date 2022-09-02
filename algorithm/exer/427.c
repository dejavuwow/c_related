//123
//456
//789
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	int n = matrixColSize[0];
	int l = matrixSize * n;
	int top = 0,
		right = n - 1,
		bottom = n - 1,
		left = 0;

	int i = 0;
	int j = 0;
	int *ret = malloc(sizeof(int) * l);
	int index = 0;

	while (index < l) {
		while (j <= right) {
			ret[index++] = matrix[i][j];
			j++;
		}
		j--;
		i++;
		top++;

		while (i <= bottom) {
			ret[index++] = matrix[i][j];
			i++;
		}
		i--;
		j--
			right--;

		while (j >= left) {
			ret[index++] = matrix[i][j];
			j--;
		}
		j++;
		i--;
		bottom--;

		while (i >= top) {
			ret[index++] = matrix[i][j];
			i--;
		}
		i--;
		j++;
		left++;
	}
	*returnSize = l;
	return ret;
}
bool canJump(int* nums, int numsSize){
	int step, distance, temp;
	for (int i = 0; i < numsSize; ) {
		int l = nums[i];
		distance = 0;
		step = 0;
		for (;l > 0; l--) {
			if (i + l >= numsSize - 1) break;
			temp = nums[i + l] + l;
			step = distance < temp ? l : step; 
			distance = distance < temp ? temp : distance;
		}
		if (distance == l) return false;
		i += l;
	}
	return true;
}
//46 13
//
//[[1,3],[2,6],[8,10],[15,18]]
#define MAX(x, y)((x) < (y) ? (y) : (x))
int cmpfunc (const void * a, const void * b)
{
	return ( (*(int**)a)[0] - (*(int**)b)[0] );
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
	int index = 0;
	int *p;
	int **ret = malloc(sizeof(int*) * 10000);
	qsort(intervals, intervalsSize, sizeof(int*), cmpfunc);

	p = malloc(sizeof(int) * 2);
	memcpy(p, intervals[0], sizeof(int) * 2);
	ret[index++] = p;
	for (int i = 1; i < intervalsSize; i++) {
		if (intervals[i][0] <= ret[index - 1][1]) {
			ret[index - 1][1] = MAX(ret[index - 1][1], intervals[i][1]);
		}
		else {
			p = malloc(sizeof(int) * 2);
			memcpy(p, intervals[i], sizeof(int) * 2);
			ret[index++] = p;
		}
	}
	*returnSize = index;
	*returnColumnSizes = malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		(*returnColumnSizes)[i] = 2;
	}
	return ret;
}
#define MAX(x, y)((x) < (y) ? (y) : (x))
#define MIN(x, y)((x) < (y) ? (x) : (y))
int index;
void add(int **ret, int *src) {
	int *p = malloc(sizeof(int) * 2);
	memcpy(p, src, sizeof(int) * 2);
	ret[index++] = p;
}
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
	int **ret = malloc(sizeof(int*) * 10001);
	index = 0;
	int *p = malloc(sizeof(int) * 2);
	int k;

	for (int i = 0; i < intervalsSize; i++) {
		if (newInterval[0] < intervals[i][1]) {
			k = i;
			break;
		}
	}
	for (i = 0; i < k; i++) {
		add(ret, intervals[i]);
	}

	add(ret, newInterval);

	for (int i = k; i < intervalsSize; i++) {
		if (intervals[i][0] <= ret[index - 1][1]) {
			ret[index - 1][1] = MAX(ret[index - 1][1], intervals[i][1]);
		}
		else {
			add(ret, intervals[i]);
		}
	}
	*returnSize = index;
	*returnColumnSizes = malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		(*returnColumnSizes)[i] = 2;
	}
	return ret;
	
}
int lengthOfLastWord(char * s){
	int l = strlen(s);
	int start = -1,
		end = -1;
	for (i = l - 1; i >= 0; i--) {
		if (s[i] == ' ') {
			end = -1;
		}
		else {
			if (end == -1) {
				end = i;
			}
			start = i;
		}
	}
	return end == -1 ? 0 : end - start + 1;
}
