int top = -1;
#define PUSH(stack, item) (stack[++top] = item)
#define POP(stack) (stack[top--])
#define IS_EMPTY (top < 0)
int parseInt(char *s) {
	int flag = 1;
	int res = 0;
	while (*s != '\0') {
		if (*s == '-') flag = -1;
		else {
			res = res * 10 + *s;
		}
		s++;
	}
	return flag * res;
}
int evalRPN(char ** tokens, int tokensSize){
	int stack[tokensSize];
	top = -1;
	for (int i = 0; i < tokensSize; i++) {
		int l = strlen(tokens[i]);
		int value;
		char cur = tokens[i][0];
		if (l == 1 && (cur == '+' || cur == '-' || cur == '*' || cur == '/')) {
			int second = POP(stack);
			int first = POP(stack);
			if (cur == '+') {
				value = first + second;
			} else if (cur == '-') {
				value = first - second;
			} else if (cur == '*') {
				value = first * second;
			} else {
				value = first / second;
			}
		} else {
			value = parseInt(tokens[i]);
		}
		PUSH(stack, value);
	}
	return stack[top];
}
//abcde
//bcdae
//f(x, y, k) = 
bool isScramble(char * s1, char * s2){
	int l = strlen(s1);
	int dp[l][l][l + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			dp[i][j][1] = s1[i] == s2[j];
		}
	}

	for (int len = 2; len <= l; len++) {
		for (int i = 0; i <= l - len; i++) {
			for (int j = 0; j <= l -len; j++) {
				for (int k = 1; k < len; k++) {
					if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
							(dp[i][j + len - k][k]) && dp[i + k][j][len - k]) {
						dp[i][j][len] = 1;
						break;
					}
				}
			}
		}
	}
	return dp[0][0][l];
}
//[a, b, c, d, e]
//     48
//	12     4
//3   4  2   2
//  2  2
int cmp(int *a, int *b) {
	return *a - *b;
}
int numFactoredBinaryTrees(int* arr, int arrSize){
	qsort(arr, arrSize, sizeof(int), cmp);
	int dp[arrSize];
	for (int i = 0; i < arrSize; i++) {
		dp[i] = 1;
		for (int left = 0, right = i - 1; left <= right; left++, right--) {
			if (arr[i] == arr[left] * arr[right]) {
				int t = dp[left] * dp[right];
				dp[i] += (left == right ? t : 2 * t);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < arrSize; i++) {
		sum += dp[i];
	}
	return sum;
}
int intToStr(int number, char *str) {
	int index = 0;
	int radix = 10;
	do {
		str[index++] = number % radix + '0';
		number /= radix;
	} while (number != 0);

	if (nums < 0) str[index++] = '-';

	for (int i = 0, j = index - 1; i < index; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	str[index] = '\0';
	return index;
}
//1000001
//111111
//10011
//10011
//11101
//11101
//-2^31
//o ~ 2^32 - 1
//0 ~ 127    -128 ~ -1
//128 ~ 255 => -128
//
//-0x1000 0000  2^28  * 2 * 3
//
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
	char **res = malloc(sizeof(char*) * numsSize);
	int index = 0;
	int start = nums[0], end = nums[0];
	char s1[12], s2[12];
	for (int i = 1; i < numsSize; i++) {
		if (end + 1 != nums[i]) {
			int l1 = intToStr(start, s1);
			int l2 = intToStr(end, s2);
			char *cur = malloc(sizeof(char) * 25);
			strcpy(cur, s1);

			if (end != start) {
				strcpy(cur + l1, "->");
				strcpy(cur + l1 + 2, s2);
				cur[l1 + l2 + 2] = '\0';
			} else {
				cur[l1] = '\0';
			}
			res[index++] = cur;
			start = nums[i];
		} 
		end = nums[i];
	}
	int l1 = intToStr(start, s1);
	int l2 = intToStr(end, s2);
	char *cur = malloc(sizeof(char) * 23);
	strcpy(cur, s1);
	if (end != start) {
		strcpy(cur + l1, "->");
		strcpy(cur + l1 + 2, s2);
		cur[l1 + l2 + 2] = '\0';
	} else {
		cur[l1] = '\0';
	}
	res[index++] = cur;

	*returnSize = index;
	return res;
}
//[3,2,3,1,2,4,5,5,6]
//65
//
//56
//
//1 2 
// 
//k != left && nums[start] != nums[end]
#define SWAP(a, b) {\
	int temp = a;\
	a = b;\
	b = temp;\
}
int quickSelect(int *nums, int start, int end, int k) {
	if (start == end) return nums[start];
	int pivot = (start + end) / 2;
	int base = nums[pivot];
	SWAP(nums[pivot], nums[end]);
	int left = start, 
		int right = end;
	while (left < right) {
		while (nums[left] > base && left < right) left++;
		while (nums[right] <= base && left < right) right--;
		if (left < right) {
			SWAP(nums[left], nums[right]);
		}
	}
	SWAP(nums[end], nums[left]);
	if (k == left) return nums[left];
	else if (k > left) return quickSelect(nums, left + 1, end, k);
	else  return quickSelect(nums, start, left - 1, k);
}
int findKthLargest(int* nums, int numsSize, int k){
	return quickSelect(nums, 0, numsSize - 1, k - 1);
}

//[1, n]
//1 + k
//1 + k + 2 * k
//1 + k  + 2 * k + 3 * k
//1 + k (1 + 2 + 3 + ...)
//1 + k (sa-1) < n
//1 + k (sa) > n
//
//1234
//1  
//1  4
//12 4
int* circularGameLosers(int n, int k, int* returnSize){
	int *ret = malloc(sizeof(int) * n);
	int retSize = 0;
	int temp[n];
	int index = 0;
	int last;
	temp[index++] = 1;
	int i, j;
	for (i = 1, j = 1; i <= n; j++) {
		i += j * k;
		temp[index++] = i;
	}
	last = i % 5;
	for (int a = 1, b = 0; a < n; a++) {
		if (a != temp[b] && a != last) {
			ret[returnSize++] = a;
		} else {
			b++;
		}
	}
	*returnSize = index;
	return ret;
}
// dp = n2 + 1
// dp =
// (pre + cost1) / cost2 + dp;
// pre = (pre + cost1) % cost2
long long waysToBuyPensPencils(int total, int cost1, int cost2){
	int max = fmax(cost1, cost2);
	int min = fmin(cost1, cost2);
	int n1 = total / max;
	int n2 = total % max / min;
	int pre = total % max % min;
	int dp = n2 + 1;
	long long sum = dp;

	for (int i = n1 - 1; i >= 0; i--) {
		int k = pre + max;
		pre = k % min;
		dp = dp + k/min;
		sum += dp;
	}
	return sum;
}
//abc defg kkd
//4512673
//
//4523671
//4573621
//45763213
//xx78666
//76
//
#define SWAP(a, b) {\
	int temp = a;\
	a = b;\
	b = temp;\
}
void quickSort(int * indices, char **sources, char **targets, int start, int end) {
	if (start >= end) return;
	int pivot = (start + end) >> 1;
	int base = indices[pivot];
	SWAP(indices[pivot], indices[end]);
	SWAP(sources[pivot], sources[end]);
	SWAP(targets[pivot], targets[end]);
	int left = start;
	int right = end;

	while (left < right) {
		while (left < right && indices[right] > base)right--;
		while (indices[left] < base) left++;

		//nums[left] >= base || left == right
		//nums[right] < base || right == left
		if (left < right) {
			SWAP(indices[left], indices[right]);
			SWAP(sources[left], sources[right]);
			SWAP(targets[left], targets[right]);
		}
	}
	SWAP(indices[left], indices[end]);
	SWAP(sources[left], sources[end]);
	SWAP(targets[left], targets[end]);
	quickSort(indices, sources, targets, start, left - 1);
	quickSort(indices, sources, targets, left + 1, end);

}
char * findReplaceString(char * s, int* indices, int indicesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize){
	int l = strlen(s);
	char *retStr = malloc(sizeof(char) * (l +  targetsSize * 50));
	quickSort(indices, sources, targets, 0, indicesSize - 1);
	int pre = 0;
	for (int i = 0; i < indicesSize; i++) {
		int sourcLen = strlen(sources[i]);
		if (strncmp(s + indices[i], sources[i], sourcLen) == 0) {
			if (indices[i] != pre) {
				strncpy(retStr, s[pre], indices[i] - pre);
				pre = indices[i];
			}
			strcpy(retStr, targets[i], strlen(targets[i]));
			pre += strlen(sources[i]);
		}
	}
	return retStr;
}

void quickSort(int *number, int first, int last) {
	int i, j, pivot;
	int temp;
	if (first<last) {
		pivot = first;
		i = first;
		j = last;
		while (i<j) {
			while (number[i] <= number[pivot] && i<last)
				i++;
			while (number[j]>number[pivot])
				j--;
			if (i<j) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quickSort(number, first, j - 1);
		quickSort(number, j + 1, last);
	}
}
//  1          7
//2   3     8    9
//  4   5 10  11
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
	if (root1 = NULL) {
		return root2;
	}
	if (root2 = NULL) {
		return root1;
	}
	root1->val += root2->val;
	root1->left = mergeTrees(root1->left, root2->left);
	root1->right = mergeTrees(root1->right, root2->right);
	return root1;
}
//[10, 11, 12,7, 8][9, 10]
// 78 12 8
//[10,9,2,5,3,7,101,18]
//
//[2][2, 5] [3][3, 7] [3,7, 18]
//[0, m] [m + 1, n - 1];
//f(0, n - 1) = 
void search(int *dp, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) >> 1;
		if (dp[mid] < target ) {
			if (dp[mid + 1] > target) {
				dp[mid + 1] = target;
				break;
			} else if (dp[mid + 1] < target) {
				start = mid + 1;
			}
		} else if (dp[mid] > target) {
			end = mid - 1;
		}
	}
}
int lengthOfLIS(int* nums, int numsSize){
	int dp[2500];
	int lenth = 1;
	dp[length] = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (dp[length] < nums[i]) {
			dp[++length] = nums[i];
		} else if (dp[length] > nums[i]) {

		}
	}
}
int map[2001];
int min;
int dfs(int x, int a, int b, int step, int prem) {
	if (0 == x) {
		min = fmin(step, min);
		return 1;
	} 
	int s1 = 0, s2 = 0;
	if (x - a >= 0 && (x - a > 2000 || !map[x - a])) {
		s1 = dfs(x - a, a, b, step + 1, -1);
	} 
	if ((x + b > 2000 || !map[x + b] )&& s1 == 0 && prem != 1) {
		s2 = dfs(x + b, a, b, step + 1, 1);
	}
	return s1 || s2;
}

int minimumJumps(int* forbidden, int forbiddenSize, int a, int b, int x){
	min = INT_MAX;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < forbiddenSize; i++) {
		map[forbidden[i]] = 1;
	}
	return 	dfs(x, a, b, 0, 0) ? min : -1;
}

int map[2001];
#define ENQUEUE(queue, value, step, forward) {\
	int *temp = queue[++end % x];\
	temp[0] = value;\
	temp[2] = forward;\
	temp[1] = step;\
}
#define DEQUEUE(queue) (queue[head++ % x])
#define IS_EMPTY (head > end)
int minimumJumps(int* forbidden, int forbiddenSize, int a, int b, int x){
	memset(map, 0, sizeof(map));
	int queue[x][3];
	int head = 0;
	int end = -1;
	for (int i = 0; i < forbiddenSize; i++) {
		map[forbidden[i]] = 1;
	}
	ENQUEUE(queue, a, 1);
	while (!IS_EMPTY) {
		int *t = DEQUEUE(queue);
		if 
		int f = t[0] + a;
		if ()
	}


}
