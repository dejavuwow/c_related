#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define printArray(nums, size)\
{\
	for (int *i = nums; i < nums + size; i++) {\
		printf("%d ", *i);\
	}\
	putchar('\n');\
}
//[-4, -1, 1, 2, 6]
//-1 1
//-1 2
//-1 6
//1 2
//1 6
//2 6
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int threeSumClosest(int* nums, int numsSize, int target){
	qsort(nums, numsSize, sizeof(int), cmpfunc);
	int sum = 0;
	int min = INT_MAX;
	int targetSum = INT_MAX;
	for (int i = 0; i < numsSize - 2;i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;


		for (int j = i + 1; j < numsSize - 1; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			for (int k = j + 1; k < numsSize; k++) {
				if (k > j + 1 && nums[k] == nums[k - 1]) continue;
				sum = nums[i] + nums[j] + nums[k];
				printf("%d %d %d %d == %d %d %d\n",target, nums[i], nums[j], nums[k], sum, abs(target - sum), min);
				if (abs(target - sum) < min) {
					min = abs(target - sum);
					targetSum = sum;
				}
			}
		}
	}
	printf("\n%d", targetSum);
	return targetSum;
}
char (*letterCombinations(char * digits, int* returnSize))[5] {
	int len = strlen(digits);
	int q = 0;
	int tempSize;
	char keyPlate[][5] = {
		{0,0,0,0, 0},
		{'a', 'b', 'c', 0, 0},
		{'d', 'e', 'f', 0, 0},
		{'g', 'h', 'i', 0, 0},
		{'j', 'k', 'l', 0, 0},
		{'m', 'n', 'o', 0, 0},
		{'p', 'q', 'r', 's', 0},
		{'t', 'u', 'v', 0, 0},
		{'w', 'x', 'y', 'z', 0}
	};
	char (*selected)[5] = (char(*)[5])malloc(len * 5 * sizeof(char));
	for (char *i = digits; *i != '\0'; i++, q++) {
		strncpy(selected[q], keyPlate[*i - 0x30 - 1], 5);
	}
	*returnSize = 1;
	for (int i = 0; i < len; i++) {
		*returnSize *= strlen(selected[i]);
	}

	tempSize = *returnSize;
	char (*ret)[len + 1] = (char(*)[len + 1])calloc(*returnSize * (len + 1), sizeof(char));
	/** for (int i = 0; i < *returnSize; i++) { */
	/** for (int j = 0; j < len + 1; j++) { */
	/**     printf("%d ", ret[i][j]); */
	/** } */
	/** putchar('\n'); */
	/** } */
	int *map = (int*)calloc(len, sizeof(int));
	int b = len - 1;
	for (int p = 0; p < tempSize; p++) {
		for (int i = 0; i < len; i++) {
			ret[p][i] = selected[i][map[i]];
		}
		map[len - 1] = map[len - 1] + 1;
		for (int i = len - 1; i >= 0; i--) {
			if (map[i] > strlen(selected[i]) - 1) {
				map[i] = 0;
				map[i - 1] = map[i - 1] + 1;
			}
			else break;
		}
	}
	return ret;
	//wxyz
	//abc
	//mnoy
	//00 10 20
	//00 10 21
	//00 10 22
	//========
	//00 11 20
	//00 11 21
	//00 11 22
	//========
	//00 12 20
	//00 12 21
	//00 12 22
	//========
	//01 10 20
	//



}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
	qsort(nums, numsSize, sizeof(int), cmpfunc);
	int **ret = (int**)malloc(sizeof(int*));
	int n = 0;
	int val;
	int k, l;
	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int));
	for (int i = 0; i < numsSize - 3; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		for (int j = i + 1; j < numsSize - 2; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			val = target - nums[i] - nums[j];
			k = j + 1;
			l = numsSize - 1;
			while (k < l) {
				if (k > j + 1 && nums[k] == nums[k - 1]) {
					k++;
					continue;
				};
				if (nums[k] + nums[l] == val) {
					ret = (int**)realloc(ret, (n + 1) *  sizeof(int*));
					ret[n] = (int*)malloc(sizeof(int) * 4);
					(*returnColumnSizes) = (int*)realloc(*returnColumnSizes, (n + 1) * sizeof(int));
					ret[n][0] = nums[i];
					ret[n][1] = nums[j];
					ret[n][2] = nums[k];
					ret[n][3] = nums[l];
					*(*returnColumnSizes + n)= 4;
					*returnSize = *returnSize + 1;
					n++;
					k++;
					l--;
				}
				else {
					if (nums[k] + nums[l] < val) k++;
					else l--;
				}
			}
		}
	}
	for (int i = 0; i < *returnSize; i++) {
		printf("%d %d %d %d\n", ret[i][0], ret[i][1], ret[i][2], ret[i][3]);
	}
	return ret;
}
//p(i, j) = true;
//p(i, j) = p(i+1, j -1) && p[i] = p[j]
#define copyChar(s, t, start, end) {\
	for (int i = 0; i < end - start; i++) {\
		s[i] = t[start + i];\
	}\
}
char * longestPalindrome(char * s){
	int dp[1001][1001] = {0};
	char *ret = (char*)calloc(1001, sizeof(char));
	ret[0] = s[0];
	int len = 0;
	int maxLen = 1;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
		dp[i][i] = 1;
	}
	int l, r;
	for (int l = 0; l < len; l++) {
		for (i = 2; (r = l + i - 1 ) < len; l++) {
			if (s[l] == s[r]) {
				if (i > 2) {
					if (dp[l][r] = dp[l + 1][r - 1]) {
						if (i > maxLen) {
							maxLen = i;
							copyChar(ret, s, l, r);
						}
					}
				} else {
					dp[l][r] = 1;
					if (i > maxLen) {
						maxLen = i;
						copyChar(ret, s, l, r);
					}
				}
			} else {
				dp[l][r] = 0;
			}
		}

	}
	return ret;
}
char * convert(char * s, int numRows){
    int len = strlen(s);

	if (len <= numRows) return s;

	int loopContainCount = (numRows - 2) + numRows;
	int rows = len / loopContainCount  * (numRows - 1) + 1 + (len % loopContainCount);
	char map[numRows][rows];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rows; j++) {
            map[i][j] = '\0';
        }
    }
	int x = -1;
	int y = 0;
	int flag = -1;
	int step = numRows;
	for (int i = 0; i < len; i++) {
		
        
		if (step % numRows == 0) {
			step = 1;
			flag = -flag;
		}
		if (flag) {
			x++;
		} else {
			x--;
			y++;
		}
		step++;
        printf("%d %d %d\n", x, y, step);
        map[x][y] = s[i];
	}
	char *ret = (char*)malloc(sizeof(char) * (len + 1));
	int n = 0;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < rows; j++) {
			if (map[i][j] == '\0') {
				continue;
			}
			ret[n]  = map[i][j];
			n++;
		}
	}
	ret[n] = '\0';
	return ret;
}
void main(void) {
	/** int nums[] = { -1, 2, 1, -4}; */
	/** threeSumClosest(nums, 4, 1); */
	/** int size; */
	/** char *digits = "2349"; */
	/** char (*ret)[5] = letterCombinations(digits, &size); */
	/**  */
	/** for (int i = 0; i < size; i++) { */
	/**     printf("%s \n", ret[i]); */
	/** } */
	//fourSum((int[]){-2,-1,-1,1,1,2,2}, 7, 0, &returnSize, &column);
	//

}
