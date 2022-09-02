#define NUMBER(x) ((x) - 0x30)
#define CHAR(x) ((x) + 0x30)
char * addBinary(char * a, char * b){
	int l1 = strlen(a),
		l2 = strlen(b);
	int l = l1 < l2 ? l2 : l1;
	char *ret = malloc(sizeof(char) * (l + 1));
	int carry = 0;
	ret[l] = 0;
	int i, j, k;

	for (i = l1 - 1, j = l2 - 1, k = l - 1; i >= 0 && j >= 0; i--, j--, k--) {
		int total = NUMBER(a[i]) + NUMBER(b[j]) + carry;
		ret[k] =  CHAR(total % 2);
		carry = total / 2; 
	}
	if (i < 0) {
		for (; j >= 0; j--, k--) {
			int total = NUMBER(b[j]) + carry;
			ret[k] =  CHAR(total % 2);
			carry = total / 2; 
		}
	}
	else {
		for (; i >= 0; i--, k--) {
			int total = NUMBER(a[i]) + carry;
			ret[k] =  CHAR(total % 2);
			carry = total / 2; 
		}
	}
	if (carry) {
		ret = realloc(ret, (l + 2) * sizeof(char));
		memmove(ret, ret + 1, sizeof(char) * (l + 1));
		ret[k] = '1';
	} 
	return ret;

}
func() {
	if ()
}
char *newRow(int length) {
	char *p = malloc(sizeof(char) * length);
	p[length - 1] = 0;
	memset(p, ' ', length - 1);
	return p;
}
char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
	char **ret = malloc(sizeof(char*) * wordsSize);
	char *p = newRow(maxWidth + 1);
	int n = 1;
	int index = 0;
	int rowWordNum = 0;
	int blankNum, avgBlank, remBlank;
	int backWord, backPos;
	for (int i = 0; i < wordsSize; i++) {
		int a = strlen(words[i]);
		if (index + a >= maxWidth) {
			memset(&p[backPos], ' ', maxWidth - backPos);
			if (rowWordNum > 1) {
				blankNum = maxWidth - index + rowWordNum + 1;
				avgBlank = blankNum / (rowWordNum - 1);
				remBlank = blankNum % (rowWordNum - 1);
			}
			while (backWord < i) {
				int k = avgBlank;
				if (remBlank > 0) {
					k++;
					remBlank--;
				}
				int l = strlen(words[backWord]);
				strncpy(&p[backPos += k], &words[backWord], l);
				backPos += l;
				backWord++;
			}
			ret[index++] = p;
			p = newRow(maxWidth + 1);
			index = 0;
			rowWordNum = 0;
			n++;
		}
		else {
			strncpy(&p[index], words[i], a);
			index += (a + 1);
			rowWordNum++;
			if (rowWordNum == 1) {
				backWord = i + 1;
				backPos = index;
			}
		}
	}
	*returnSize = n;
	return ret;
}
int mySqrt(int x){
	int start = 0, end = 0x7fffffff;
	long cur;
	int total;
	int flag = 0;
	for (; start <= end;) {
		cur = (start + end) / 2;
		total = cur * cur;
		if (total == x) {
			flag = 1;
			break;
		} 
		else if (total > x) start = cur + 1;
		else end = cur - 1;
	}
	return flag ? cur : end;
}

char *dirs[3000];
int top = -1;
int process = 1;
int start;

void setDir(char *path, int end) {
	if (end - start == 2 && path[start] == '.' && path[start + 1] == '.') { //../
		free(dirs[top--]);
	}
	else if (path[start] != '.') {
		int l = end - start + 2;
		char *p = malloc(sizeof(char) * l);
		p[0] = '/';
		p[l - 1] = 0;
		strncpy(p + 1, path + start, end - start);
		dirs[++top] = p;
	}
	process = 0;

}
char * simplifyPath(char * path){
	int l = strlen(path);
	char *ret = malloc(sizeof(char) * (l + 1));
	int index = 0;
	ret[l] = 0;
	ret[index++] = '/';
	process = 0;
	for (int i = 1; i < l; i++) {
		if (path[i] != '/' && !process) {
			process = 1;
			start = i;
		}
		else if (process && path[i] == '/') {
			setDir(path, i);
		}
	}
	for (int i = 0; i <= top, i++) {
		int n = strlen(dirs[i]);
		strncpy(ret + index, dirs[i], n);
		index += n;
	}
	ret[index] = 0;
	return ret;
}
#define MIN(x, y) ((x) > (y) ? (y) : (x))
int minDistance(char * word1, char * word2){
	int m = strlen(word1),
		n = strlen(word2);

	int dp[m][n];
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		dp[i][0] = i; 
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = MIN(MIN(dp[i - 1][j] + 1, dp[i][j - 1] + 1), word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1]: dp[i - 1][j - 1] + 1);
		}
	}
	return dp[m][n];
}
//  123
//  456
//  789
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
	int m = matrixSize,
		n = matrixColSize[0];

	int start = 0,
		end = m * n - 1;

	int mid, i, j;
	for (; start <= end;) {
		mid = (start + end) / 2;
		i = mid / m;
		j = mid % m;
	}
}
//2101102
void swap(int *a, int *b) {
	int temp = *a;
	*b = *a;
	*a = temp;
}
void sortColors(int* nums, int numsSize){
	int left = 0,
		right = numsSize - 1;
	for (int i = 0; i <= right; i++) {
		if (nums[i] == 0) {
			swap(&nums[i], &nums[left++]);
		}
		else if (num[i] == 2) {
			swap(&nums[i], &nums[right--]);
			i--;
		}
	}
}
//BA    c
//s = "ADOBECODEBANC", t = "ABC"
//f[i][j] = f[i - 1][j]
//arr[0] = [[1,1], [7,7]]
//12345
//[[1,3], [3,5], [3,7]]
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
char * minWindow(char * s, char * t){
	int m = strlen(s),
		n = strlen(t);

	int arr[m][2];
	int index = 0;
	int *map[123];
	int size[123] = {0};
	for (int i = 0; i < 123; i++) {
		map[i] = NULL;
	}
	for (int i = 0, length = 0, ; i < m; i++) {
		if (!map[s[i]]) {
			map[s[i]] = malloc(sizeof(int));
		}
		else {
			map[s[i]] = realloc(map[s[i]], (size[s[i]] + 1) * sizeof(int));
		}
		map[s[i]][size[s[i]]++] = i;
	}

	for (int i = 0; i < n; i++) {
		int *store = map[t[i]];
		if (index == 0) {
			for (int j = 0; j < size[t[i]]; j++) {
				arr[index][0] = arr[index][1] = store[j];
				index++;
			}
			/** arr[index][0] = MIN(arr[index][0], store[j]); */
			/** arr[index][1] = MAX(arr[index][1], store[j]); */
			/** index++; */
		} 
		else {
			for (int j = 0; j < size[t[i]]; j++) {
				for (int q = 0; q < index; q++) {
					arr[q][0] = MIN(arr[q][0], store[j]);
					arr[q][1] = MAX(arr[q][1], store[j]);
				}
			}
		}
	}
}
for (int i =)
	}

char * minWindow(char * s, char * t){
	int m = strlen(s),
		n = strlen(t);
	int map[123] = {0};
	int copy[123] = {0};
	int start = -1, 
		end = -1;
	int size = 0;
	int left = -1, right = -1;

	for (int i = 0; i < n; i++) {
		map[t[i]]++;
		copy[t[i]]++;
	}

	for (int i = 0; i < m; i++) {
		if (size == 0 && map[s[i]] > 0) {
			start = end = i;

			size++;
			copy[s[i]]--;
		}
		else if (size == 1 && map[s[i]] == 1 && copy[s[i]] < 1) {
			start = end = i;
		}
		else if (map[s[i]] > 0) {
			if (copy[s[i]] > 0) {
				size++;
			}
			copy[s[i]]--;
			end = i;
		}
		while (size == n) {
			if (end - start < right - left) {
				left = start;
				right = end;
			}
			int k = start;
			do {
				if (map[s[start]] > 0) {
					copy[s[start]]++;
				}
				start++;
			} while (map[s[start]] > 0 && copy[s[k]] == 0)
		}
	}
	int l = right - left + 1;
	char *ret = malloc(sizeof(char) * (l + 1));
	ret[l] = 0;
	strncpy(ret, s+left, l);
	return ret;
}
//1234
//1 4 9 16
