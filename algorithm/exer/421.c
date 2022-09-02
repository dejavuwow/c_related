#include <stdio.h>
//12*
//123222
//f[i][j] 表示字符串s的前i位和p的前j位是否匹配 
//f[0][0] = true
//
//p[j - 1] != *
//p[i - 1] == .: f[i][j] = true
//f[i][j] = s[i - 1] == p[j - 1]
//
//p[j - 1] = *
//匹配0次, f[i][j] = f[i][j - 2]
//匹配多次, f[i][j] = f[i - 1][j]
//
//.*
bool isMatch(char * s, char * p){
#define MATCH(i, j) (i == 0 ? false : p[j - 1] == '.' ? true : s[i - 1] == p[j - 1])
	int l = strlen(s);
	int n = strlen(p);
	bool map[l+1][n+1];
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= n; j++) {
			map[i][j] = false;
		}
	}
	map[0][0] = true;

	for (int i = 0; i <= l; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j-1] == '*') {
				map[i][j] = map[i][j-2];
				if (MATCH(i, j - 1)) {
					map[i][j] |= map[i - 1][j];
				}

			} else {
				if (MATCH(i, j)) {
					map[i][j] |= map[i - 1][j - 1];
				}
			}
		}
	}
	return map[l][n];
}

//123457
//321754
//12*4*7
bool isMatch(char * s, char * p){
	#define MATCH(i, j) (i == 0 ? false : p[j - 1] == '?' ? true : s[i - 1] == p[j - 1])
	int l = strlen(s),
		n = strlen(p);

	bool map[l+1][n+1];
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= n; j++) {
			map[i][j] = false;
		}
	}
	map[0][0] = true;
	for (int i = 0; i <= l; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[i-1] == '*') {
				map[i][j] = map[i][j - 1];
				map[i][j] |= map[i - 1][j];
			} else {
				if (MATCH(i, j)) {
					map[i][j] = map[i - 1][j - 1];
				}
			}
		}
	}
}
int maxRotateFunction(int* nums, int numsSize){
	int total = 0;
	int max = 0;
	int current = 0;
	for (int i = 0; i < numsSize; i++) {
		total += nums[i];
		current += nums[i] * i;
	}
	max = current;

	for (int i = 1; i < numsSize; i++) {
		current = current + total - (numsSize - 1) * nums[numsSize - i];
		max = max < current ? current : max;
	}
	return max;
}
// 1 ~ a[i]
//a[0] + a[a[0]] >= n
// x  + a[x] +... a[..a[x]] >= n
// x >= n: 1
//1 ~ x + a[1 ~ x]
//37351118
// x + n - x =
//e[]
//6743210
int dfs(int *nums, int rest, int n, int k) {
	if (nums[k] == 0) return 0;
	n++;
	int min = 0;
    int temp;
	for (int i = nums[k]; num[i + k] + i > nums[k]; i--) {
		if (i >= rest) return n;
		else {
			temp = dfs(nums, rest - i, n, k + i);
			if (temp) {
				if (!min) min = temp;
				else min = temp < min ? temp : min;
			}
		}
	}
	return min;
}
int jump(int* nums, int numsSize){
    if (numsSize == 1) return 0;
	return dfs(nums, numsSize - 1, 0, 0);
}
