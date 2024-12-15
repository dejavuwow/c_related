int m, n, p, s, *t, *w;
int cmp(int *a, int *b) {
	return *a - *b;
}
#define SIZE 50000
typedef struct queue {
	int raw[SIZE];
	int head;
	int end;
} Queue;
#define INIT_QUEUE(queue) {\
	queue.head = 0;\
	queue.end = -1;\
}
#define PUSH(queue, item) (queue.raw[++queue.end % SIZE] = item)
#define POP(queue) (queue.raw[queue.head++ % SIZE])
#define POP_FRONT(queue) (queue.raw[queue.end-- % SIZE])
#define QUEUE_EMPTY(queue) (queue.head > queue.end)
#define QUEUE_FIRST(queue) (queue.raw[queue.head])
#define QUEUE_LAST(queue) (queue.raw[queue.end])
int check(int mid) {
	int j = n - 1;
	int pills = p;
	Queue queue;
	INIT_QUEUE(queue);
	for (int i = mid; i >= 0; i--) {
		for (; j >= n - mid - 1 && w[j] + s >= t[i]; j--) {
			PUSH(queue, w[j]);
		}
		if (QUEUE_EMPTY(queue)) {
			return 0;
		}
		if (pills < 1) return 0;
		if (QUEUE_FIRST(queue) >= t[i]) {
			POP(queue);
		} else{
			POP_FRONT(queue);
			pills--;
		} 
	}
	return 1;
}
int maxTaskAssign(int* tasks, int tasksSize, int* workers, int workersSize, int pills, int strength){
	m = tasksSize;
	n = workersSize;
	p = pills;
	s = strength;
	t = tasks;
	w = workers;

	qsort(tasks, m, sizeof(int), cmp);
	qsort(workers, n, sizeof(int), cmp);
	int maxSize = fmin(m, n);
	int ret = 0;

	for (int left = 0, right = maxSize - 1; left <= right;) {
		int mid = left + right >> 1;

		if (check(mid)) {
			ret = mid + 1;
			left = mid + 1;

		} else {
			right = mid - 1;
		}
	}
	return ret;
}
//1 + 8 + 16 + 64 + 256
//aa__bb___cc_ddd_eeeeeeeee
//eeeeeeee_cc___bb_aa__
//__aaa
//aaa__
//__aaa
//a--aa
//__aaa_bb____
void shift(char *s, int start, int end, int direction, int step) {
	int cur = direction == 1 ? end : start;
	int last = direction == 1 ? start : end;
	int k = step * direction;
	int size = end - start + 1
	while (size--) {
		s[cur + k] = s[cur];
		cur -= direction;
	}
}
char * reverseWords(char * s){
	int l = strlen(s);
	int blank = 0;
	for (; blank < l && s[blank] != ' '; blank++) {
		blank++;
	}
	shift(s, blank - 1, l - 1, -1, blank);
	for (int i = l - 1; s[i] != ' '; i++) {
		s[i] = '\0';
	}

}
//[0,0,1,1,1,0,1]
//0010012 10012
//f(0) = 0;
//f(1) = 2;
//f(i) = next[i - 1] == i - 1 ? f(i - 1) + 2 : (f(i - 1) - f(next[i - 1]) + 1) * 2 + f(next[i - 1])
#define IS_ODD(i) (i & 1)
int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize) {
	int n = nextVisitSize;
	int dp[n];
	memset(dp, 0, sizeof(dp));
	dp[1] = 2;
	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 1] - dp[next[i - 1]] + 1) * 2 + dp[next[i - 1]];
	}
	return dp[n - 1];
}

int longestCommonSubpath(int n, int** paths, int pathsSize, int* pathsColSize) {
    
}

#define GET(i, j) ((i >= 0 && j >= 0) ? dp[i - 1][j - 1] + 1 : 1)
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int m = nums1Size,
		n = nums2Size;
	int dp[m][n];
	int max = INT_MIN;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = nums1[i] == nums2[j] ? GET(i, j) : 0;
			max = fmax(dp[i][j], max);
		}
	}
	return max;
}

int getMaxLength(int *nums1Start, int *nums2Start, int len) {
	int k = 0;
	int max = INT_MIN;
	for (int i = 0; i < len; i++) {
		k = nums1Start[i] == nums2Start[i] ? k + 1 : 0;
		max = fmax(k, max);
	}
	return max;
}
//12: 34 35 36
//
//13: 24 25 26
//14: 23 25 26
//15: 23 24 26
//16: 23 24 25
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int m = nums1Size,
		n = nums2Size;
	int max = INT_MIN;
	for (int i = 0; i < m; i++) {

		int len = fmin(n, m - i);
		max = fmax(getMaxLength(nums1 + i, nums2, len), max);
	}
	for (int i = 0; i < n; i++) {
		int len = fmin(m, n - i);
		max = fmax(getMaxLength(nums2 + i, nums1, len), max);
	}
	return max;
}

#define MOD 1000000009
long long qPow(long long value, int exp) {
	if (exp == 0) return 1;
	if (exp == 1) return value;
	if (exp & 1) {
		return qPow(value * value % MOD, exp >> 1) * value % MOD;
	}
	return qPow(value * value % MOD, exp >> 1);
}
int contains(long long array[], int length, long long value) {
	for (int i = 0; i < length; i++) {
		if (array[i] == value) return 1;
	}
	return 0;
}
int check(int *nums1, int *num2, int len1, int len2, int checkLength) {
	long long setA[1000] = {0};
	int setAIndex = 0,
	long long base = 101;
	long long hashA = 0,
		 	  hashB = 0;

	for (int i = checkLength - 1, value = 1; i >= 0 ; i--, value = (base * value) % MOD) {
		hashA = (hashA + (nums1[i] * value) % MOD) % MOD;
		hashB = (hashB + (nums2[i] * value) % MOD) % MOD;
	}
	if (hashA == hashB) return 1;
	setA[setAIndex++] = hashA;
	for (int i = 1; i + checkLength < len1; i++) {
		hashA = ((hashA - nums1[i - 1] * qPow(base, checkLength - 1) % MOD) * base % MOD + nums1[i + checkLength - 1]) % MOD;
		if (hashA == hashB) return 1;
		setA[setAIndex++] = hashA;
	}
	for (int i = 1; i + checkLength < len2; i++) {
		hashB = ((hashB - nums2[i - 1] * qPow(base, checkLength - 1) % MOD) * base % MOD + nums2[i + checkLength - 1]) % MOD;
		if (contains(setA, setAIndex, hashB)) return 1;
	}
	return 0;
	
}

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int left = 1, right = fmin(nums1Size, nums2Size);
	while (left <= right) {
		int mid = left + right >> 1;
		if (check(nums1, nums2, nums1Size, nums2Size, mid)) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return right;
}
//[0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0]
//
//[0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0]

int longestCommonSubpath(int n, int** paths, int pathsSize, int* pathsColSize) {
    
}
