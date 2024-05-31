//[1,0]      [0]   [others]
//[0,1]      [0]  [others]
//
//[
//[0,0,0],
//[0,0,1],
//[1,1,0]]
//[] [0,1,2]
//[0,1] [2]
//[]
//
int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){

}

struct TreeNode *buildTree(int *nums, int left, int right) {
	if (left > right) return NULL;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	int max = INT_MIN;
	int index = -1;
	for (int i = left; i <= right; i++) {
		if (nums[i] > max) {
			max = nums[i];
			index = i;
		}
	}
	root->val = max;
	root->left = buildTree(nums, left, index - 1);
	root->right = buildTree(nums, index + 1, right);
	return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
	return buildTree(nums, 0, numsSize - 1);
}


#define SIZE 100
#define ENQUEUE(queue, node) (queue[++end % SIZE] = node)
#define DEQUEUE(queue) (queue(head++ % SIZE))
#define ISEMPTY (head > end)

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
	struct TreeNode *queue[SIZE];
	int head = 0;
	int end = -1;
	struct TreeNode *insertNode = malloc(sizeof(struct TreeNode));
	insertNode->val = val;
	insertNode->right = NULL;
	if (val > root->val) {
		insertNode->left = root;
		return insertNode;
	}
	ENQUEUE(root);
	while (!ISEMPTY) {
		struct TreeNode *cur = DEQUEUE(queue);
		if (cur->left) {
			ENQUEUE(queue, cur->left);
		}
		if (cur->right && cur->right->val > val) {
			ENQUEUE(queue, cur->right);
		}
		else {
			struct TreeNode *temp = cur->right;
			cur->right = insertNode;
			insertNode->left = temp;
			break;
		}
	}
	return root;
}
//[
//[1,1,0],  < = l - 1 - i
//[1,1,0],
//[0,0,1]
//f(i, n) = f(i, n -1) && a[i + n -1] = b[i + n - 1];
//f(i, n) = f(i, n -2) && f(i + n - 2, 2)
#define MATCH(s1, s2) ((s1[0] == 'X' && s2[0] == 'L' && s1[1] == 'L' && s2[1] == 'X') || (s1[0] == 'R' && s2[0] == 'X' && s1[1] == 'X' && s2[1] == 'R'))
bool canTransform(char * start, char * end){
	int l = strlen(start);
	int dp[l][l + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < l; i++) {
		dp[i][1] = start[i] == end[i];
		if (i < l - 1) {
			dp[i][2] = (dp[i][1] && dp[i + 1][1]) || MATCH((start + i), (end + i));
		}
	}
	for (int i = 3; i <= l; i++) {
		for (int j = 0; j <= l - i; j++) {
			for (int k = 1; k < i; k++) {
				if (dp[j][k] && dp[j + k][i - k]) {
					dp[j][i] = 1;
					break;
				}
			}
		}
	}
	return dp[0][l];
}
//RR L            
//    R R L
bool canTransform(char * start, char * end){
	int l = strlen(start);
	int i = 0, j = 0;
	for (; i < l;) {
		printf("%d \n", j);
		while (end[j] == 'X' && j < l) j++;
		while (i < l) {
			if (start[i] == end[j]) {
				if ((start[i] == 'L' && i >= j) || (start[i] == 'R' && i <= j)) {
					i++;
					j++;
					break;
				} else return false;
			} 
			else if (start[i] != 'X') return false;
			i++;
		}
	}
	printf("**%d", j);
	return j == l || end[j] == 'X';
}
//  5       8
// 8  5   5   10
//10
//
//				5
//		7 				9
//	8 		10 		6      7
//10
//1 
//**4
//**5  **9
//**5 **5 **10 **6 
//               4
//            5      4
//        5     5  10   9
//      6
//
//            4
//       5            9
//    5    5    10        6
//
//123
//
#define SWAP(a, b) {\
	int temp = a;\
	a = b;\
	b = temp;\
}
typedef struct {
	int heap[10000];
	int size;
	int k;
} KthLargest;

void push(KthLargest *obj, int value) {
	++obj->size;
	int cur = obj->size - 1;
	int parent = (obj->size >> 1) - 1;
	obj->heap[cur] = value;
	while (parent >= 0) {
		if (obj->heap[cur] >= obj->heap[parent]) break;
		SWAP(obj->heap[cur], obj->heap[parent]);
		cur = parent;
		parent = (parent + 1 >> 1) - 1;
	}
}
void pop(KthLargest *obj) {
	int parent, left, right;
	int pre = 0;
	for (left = 1; left < obj->size;) {
		right = left + 1 < obj->size ? left + 1 : left;
		int lVal = obj->heap[left],
		rVal = obj->heap[right];
		parent = pre;
		obj->heap[parent] = lVal <= rVal ? lVal : rVal;
		pre = lVal <= rVal ? left : right;
		left = (pre << 1) + 1;
	}
	parent = (left + 1 >> 1) - 1;
	obj->heap[parent] = obj->heap[obj->size - 1];
	while (parent >= 0) {

		int p = (parent + 1 >> 1) - 1;
		if (obj->heap[parent] >= obj->heap[p]) break;
		SWAP(obj->heap[parent], obj->heap[p]);
		parent = p;
	}
	obj->size--;
}
int kthLargestAdd(KthLargest* obj, int val);
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
	KthLargest *ret = malloc(sizeof(KthLargest));
	ret->size = 0;
	ret->k = k;
	while (numsSize--) {
		kthLargestAdd(ret, nums[numsSize]);
	}
	return ret;
}

int kthLargestAdd(KthLargest* obj, int val) {
	if (obj->size < obj->k || val > obj->heap[0]) {
		push(obj, val);
	} 
	if (obj->size > obj->k) {
		pop(obj);
	}
	return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
	free(obj);
}
//k--
//n--
//f (n)
//f(n, k) = f(n - 1, k) + ()
//
//while (k >= 0) {
//	f(n - 1, k)
//}
//1234
//
//3214
//
//231   2341
//312   3142
//4123
// 2431
// 3412
// 
//
// 1342 
// 2143
// 1243
//
// 123
//123
//
//
//3124
//2314
//54321
//1423
//1342
//2143
//
//12       21 1
//123      213  132
//
//3241
//xxx
//1234
//2134
//1324
//1243
//3 + 2 +1  n ()
// (n - 1) * (n - 1) / 2
//123
//12 (n)()
// (n - 1) * 1
//(4，5) = 3
//(5,6) = ()
//1234 5     3
//          5
//          6
//          5
//          k - q <= j
//12
//k - q <= j - 1
//123
// 
//     1234
//
//  5 10 46
//  59  46  45
//  58  46    44
//	57  46.... 43
//	56  46 45 44 43 42
//	55  45 44 43 42  41     i - (j - 1) - 1
//  54  44 43 42 41 40
//  53  43 42 41 40
//  52  42 41 40
//  51  41 40
//  50  40
//	
//	46 33
//	45 33 32
//  44 33 32 31
//  43 33 32 31 30
//  42 32 31 30
//
//  21 10
//  20 10
//
//  33 21
//  32 21 20
//  31 21 20
//  
//  33 21
//  32 21 20
//  31 21 20
//  30 20
//
//  21 10
//  20 10
int kInversePairs(int n, int k){
	int max = n *  (n - 1) / 2;
	if (k > max) return 0;
	else if (k == max) return 1;
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	max = 0;
	int bound = 0;
	for (int j = 2; j <= n; j++) {
		int preMax = max;
		max += j - 1;
		bound = fmin(max, k);
		for (int i = 1; i <= bound; i++) {
			dp[j][i] = dp[j][i - 1];
			if (i <= preMax) {
				dp[j][i] += dp[j - 1][i];
			}
			if (i > j - 1) {
				dp[j][i] -= dp[j - 1][i - j];
			}
		}
	}
	return dp[n][k];
}      *******
//112 112
//122 112
//122 122 112 112 212 112 122
// 5   4   5   5   **
//pre count 0, pre char 1 
// 2,
// pre count 1, prechar 2
//11
//2
int next() {
}
int magicalString(int n){
	if (n < 3) return 1;
	int size = n * 3 / 4;
	int temp[size];
	int index = 1;
	int end = 1;
	temp[0] = 1;
	temp[1] = 2;
	n -= 2;
	int count = 1;
	while (n--) {
		++end;
		if (temp[index] == 2) {
			temp[end] = temp[end - 1];
		} else {
			temp[end] = temp[end - 1] == 1 ? 2 : 1;
			++index;
		}
		if (temp[end] == 1) count++;
	}
	return count;
}
//f1(a) = n
//f2(b) = m
//f3(c) = k: f1(c) = j > n, f2(c) = p > m
//2 4 6 
//3 6 
// 
//2        21
//3        14
//3 6 9 12         f1(a) + f2(a) - f3(a)
//6          42: 7
// c = 
// n * f (c) =  n (c / a + c / b - 1)
// f1(c) + f2(c) - f3(c) = n;         
// f1(c) / k + f2(c) k - = n / f3(c)                
// c / a / (c / m)
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	int g = gcd(a, b);
	return g == 1 ? a * b : fmax(a, b);
}

int search(int n, int low, int large, int c) {
	int left = low;
	int right = n * low;
	int mid;
	while (left <= right) {
		mid = left + right >> 1;
		int ilow = mid / low,
			ilarge = mid / large,
			ic = mid / c;
		int res = ilow + ilarge - ic;
		if (res == n) break;
		else if (res > n) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return mid % low > mid % large ? (mid / large * large) : (mid / low * low);
}
//n = m
int nthMagicalNumber(int n, int a, int b){
	int c = lcm(a, b);
	int unit = c / a + c / b - 1;
	int count = n / unit;
	int rem = n - count * unit;

	long long value = (long long)count * c;
	for (int i = 1, j = 1; rem >= 0; rem--) {
		if (i * a <= j * b) {
			value += a;
			i++;
		} else {
			value += b;
			j++;
		}
	}
	return value % (long long) % (1e9 + 7);
}
//9 8 2 3
//7 6 2 3
int nthMagicalNumber(int n, int a, int b){
	int c = lcm(a, b);
	int low = fmin(a, b);
	int max = n * low;
	int large = low == a ? b : a;
	return search(n, low, large, c);
}
//基本思想：
//令尽可能多的workers[i] >= tasks[i], 分配pills尽可能多的让原本 workers[i] < task[i] 变得 >=
//贪心思想
//1:
//1: 搜索workers里的元素, 试图找出每一位workers[i] >= tasks[j] && 差值是最小的
//2: 
//a = b: left = b
//a < b: left = b
// 30 20  12  8  7  4
//  22   9  6  5   3    n - 1    k   8 9                 
//
//  if (strength + k >= m && pills >) ？ cur
// res = [workers[i]...];
// max = res + min(pills, diffWorkers, diffTasks)
//
//t:[5,9,8,5,9] [19,19,8,5,5]
//w:[1,6,4,2,6] [7,6,4,2,1]
//5 5
//97761
//
#define SIZE 50000
typedef struct queue {
	int head;
	int end;
	int raw[SIZE];
} Queue;

typedef struct stack {
	int top;
	int raw[SIZE];
}
//queue
#define INIT_QUEUE(queue) {\
	queue.head = 0;\
	queue.end = -1;\
}
#define ENQUEUE(queue, node) (queue.raw[++queue.end % SIZE] = node)
#define DEQUEUE(queue) (queue.raw[queue.head++ % SIZE])
#define QUEUE_EMPTY(queue) (queue.head > queue.end)

//stack
#define INIT_STACK(stack) {\
	stack.top = -1;\
}
#define PUSH(stack, node) (stack.raw[++stack.top] = node)
#define POP(stack) (stack.raw[stack.top--])
#define STACK_EMPTY(stack) (stack.top < 0)

int cmp(int *a, int *b) {
	return *a - *b;
}
int search(int *workers, int l, int r, int target) {
	int left = l,
		right = r;

	while (left <= right) {
		int mid = left + right >> 1;
		if (workers[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return left;
}
int maxTaskAssign(int* tasks, int tasksSize, int* workers, int workersSize, int pills, int strength){
	int m = tasksSize,
		n = workersSize;
	qsort(tasks, m, sizeof(int), cmp);
	qsort(workers, n, sizeof(int), cmp);
	int max = fmin(m, n);
	
	int j = 0;
	int min = n - max;
	int j = max - 1;
	int queue[SIZE];
	Queue can;
	Stack cant
	INIT_QUEUE(can);
	INIT_STACK(cant);
	for (int i = max - 1; i >= 0; i--) {
		int up = search(workers, min, j, tasks[j]);
		if (up > j) {
			if (pills > 0) {
				if (STACK_EMPTY(cant)) {
					int r = search(workers, min, j, tasks[j] - strength);

				}
			}
		} else {
			int maxWorkder = QUEUE_EMPTY(can) ? j + 1 : can.end;
			for (int i = up; i < maxWorkder; i++) {
				ENQUEUE(can, i);
			}	
			DEQUEUE(can);
			j--;
		}
	}
	return res;
}
//         12      		13 14 15 16
//      34   35   36 	24
//		56   46   45
