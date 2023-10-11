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
//123
//
int kInversePairs(int n, int k){
	int max = n *  (n - 1) / 2;
	if (k > max) return 0;
	else if (k == max) return 1;
 	int dp[n + 1][k + 1];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i < max; i++) {
		for (int j = 1; j <= n; j++) {
				for (int k =)
			dp[j][k] =	dp[j - 1][k]
		}
	}
}
