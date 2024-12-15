//f(n) = fmax(f(n - k) ... f(n - 1)) + nums[n];
//f(n - 1) = fmax(f(n - k - 1)... f(n - 2)) + nums[n - 1]
//f(n - 2) = fmax(f(n - k - 2) ...f(n - 3)) + nums[n - 2]
//		  0
//		4   1
//   5   6 2  3
#define HEAP_ADD(value) {\
	int index = heapSize;\
	heap[index] = value;\
	for (int k = (index - 1) / 2; k >= 0 && heap[k] < heap[index]; index = k,  k = (index - 1) / 2) {\
		int temp = heap[index];\
		heap[index] = heap[k];\
		heap[k] = temp;\
	}\
	heapSize++;\
}
#define HEAP_REMOVE_MAX() {\
	heap[0] = heap[--heapSize];\
	for (int index = 0; index < heapSize;) {\
		int old = index;\
		int max = index;\
		int left = 2 * index + 1;\
		int right = left + 1;\
		if (left < heapSize && heap[left] > heap[max]) max = left;\
		if (right < heapSize && heap[right] > heap[max]) max = right;\
		if (index == max) break;\
		int temp = heap[index];\
		heap[index] = heap[max];\
		heap[max] = temp;\
	}\
}
int maxResult(int* nums, int numsSize, int k) {
	int map[numsSize];
	int heap[numsSize];
	int heapSize = 0;
	map[0] = nums[0];
	HEAP_ADD(nums[0]);
	for (int i = 1; i < numsSize; i++) {
		if (i > k && map[i - k - 1] == heap[0]) {
			HEAP_REMOVE_MAX();
		}
		map[i] = heap[0] + nums[i];	
		HEAP_ADD(map[i]);
		printf("%d: %d %d\n", i, map[i], heap[0]);
	}
	return map[numsSize - 1];
}
#define QUEUE_FIRST (queue[first])
#define QUEUE_LAST (queue[(first + length - 1) % k])
#define SHIFT() {\
	first = (first + 1) % k;\
	length--;\
}
#define PUSH(value) {\
	length++;\
	QUEUE_LAST = value;\
}
#define POP() {\
	length--;\
}
#define QUEUE_EMPTY (length == 0)
int maxResult(int* nums, int numsSize, int k) {
	int map[numsSize];
	int queue[k];
	int length = 0;
	int first = 0;
	map[0] = nums[0];
	PUSH(0);
	for (int i = 1; i < numsSize; i++) {
		while (!QUEUE_EMPTY && QUEUE_FIRST < i - k) {
			SHIFT();
		}
		map[i] = map[QUEUE_FIRST] + nums[i];
		while (!QUEUE_EMPTY && map[i] > map[QUEUE_LAST]) {
			POP();
		}
		PUSH(i);
	}
	return map[QUEUE_LAST];
}

#define MAX_SIZE 10000
int* postorder(struct Node* root, int* returnSize) {
	struct Node *stack[MAX_SIZE];
	struct Node *temp;
	struct Node *pre = NULL;
	int top = -1;
	stack[++top] = root;
	int *ret = malloc(sizeof(int) * MAX_SIZE);
	int index = 0;
	while (top > -1) {
		temp = stack[top];
		if (temp->numChildren == 0 || pre == temp->children[temp->numChildren - 1]) {
			ret[index++] = temp->val;
			top--;
			pre = temp;
		} else {
			for (int i = temp->numChildren - 1; i >= 0; i--) {
				stack[++top] = temp->children[i];
			}
		}
	}
	*returnSize = index;
	return ret;
}

char * smallestString(char * s){
	int l = strlen(s);
	int i = 0;
	while (s[i] == 'a') i++;
	for (; i < l && s[i] != 'a'; i++) {
		s[i] = s[i] - 1;
	}
	return s;
}
//poiintier
char* finalString(char* s) {
	int l = strlen(s);
	int fL = l;
	for (int i = 0; i < l; i++) {
		if (s[i] == 'i') fL--;
	}

	char *ret = malloc(sizeof(char) * (fL + 1));
	ret[fL] = '\0';
	for (int i = l - 1, right = fL - 1, left = 0, direction = -1; i >= 0; i--) {
		while (s[i] == 'i') {
			direction *= -1;
			i--;
		}
		if (direction == -1) {
			ret[right--] = s[i];
		} else {
			ret[left++] = s[i];
		}
	}
	return ret;
}
//分治 (自顶向下)
struct TreeNode** allPossibleFBT(int n, int* returnSize) {
	*returnSize = 0;
	struct TreeNode **ret = NULL;
	if (n % 2 == 0) {
		return ret;
	}
	if (n == 1) {
		ret = malloc(sizeof(struct TreeNode *));
		ret[0] = malloc(sizeof(struct TreeNode));
		ret[0]->val = 0;
		ret[0]->left = ret[0]->right = NULL;
		*returnSize = 1;
		return ret;
	}
	for (int i = 0; i <= n; i++) {
		int leftCount = 0;
		int rightCount = 0;
		struct TreeNode **leftTree = allPossibleFBT(i, &leftCount);
		struct TreeNode **rightTree = allPossibleFBT(n - 1 - i, &rightCount);
		*returnSize = lefCount * rightCount;
		ret = malloc(sizeof(struct TreeNode *) * *returnSize);
		int idx = 0;
		for (int left = 0; left < leftCount; left++) {
			for (int right = 0; right < rightCount; right++) {
				struct *root = malloc(sizeof(struct TreeNode));
				root->val = 0;
				root->left = leftTree[left];
				root->right = rightTree[right];
				ret[idx++] = root;
			}
		}
	}
	return ret;
}

//动态规划（自底向上）
#define MAX 5000
struct TreeNode** allPossibleFBT(int n, int* returnSize) {
	struct TreeNode **ret = NULL;
	*returnSize = 0;
	if (n % 2 == 0) {
		return ret;
	}
	struct TreeNode **dp[n + 1];
	int count[n + 1];
	for (int i = 1; i <= n; i += 2) {
		d[i] = NULL;
		count[i] = 0;
	}
	struct TreeNode **temp = malloc(struct TreeNode *);
	temp[0] = malloc(struct TreeNode);
	temp[0]->val = 0;
	temp[0]->left = temp[0]->right = NULL;
	dp[1] = temp;
	count[1] = 1;
	for (int i = 3; i <= n; i += 2) {
		dp[i] = malloc(sizeof(struct TreeNode*) * MAX);
		for (int j = 1; j < i; j += 2) {
			for (int k = 0; k < count[j]; k++) {
				for (int m = 0; m < count[i - 1 - j]; m++) {
					struct TreeNode *left = dp[j][k];
					struct TreeNode *right = dp[i - 1 - j][m];
					struct TreeNode *root = malloc(sizeof(struct TreeNode));
					root->val = 0;
					root->left = left;
					root->right = right;
					dp[i][count[i]++] = root;
				}
			}
		}
	}
	*returnSize = count[n];
	return dp[n];
}
// c/m = a/m - b/m
// gcd(a,b) = gcd(a,c) = gcd(c, b) = gcd(b, c - b) = gcd(a - 2b, b) = gcd(a - 3b) 
// gcd(7, 5)
// gcd(5, 2)
// gcd(2, 1)
// gcd(1, 0)
