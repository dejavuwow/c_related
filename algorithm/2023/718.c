char * addStrings(char * num1, char * num2){
	int l1 = strlen(num1),
		l2 = strlen(num2);
	int min = fmin(l1, l2);
	int max = fmax(l1, l2);
	char *res = malloc(sizeof(char) * (max + 2));
	int index = 0;
	int carry = 0;

	for (int i = 0; i < max; i++) {
		int num1Index = l1 - i - 1,
			num2Index = l2 - i - 1;
		int sum = (num1Index >= 0 ? num1[num1Index] - 0x30 : 0) + (num2Index >= 0 ? num2[num2Index] - 0x30 : 0) + carry;
		carry = sum > 9 ? 1 : 0;
		res[index++] = (carry ? sum - 10 : sum) + 0x30;
	}
	if (carry) {
		res[index++] = '1';
	}
	res[index] = '\0';

	for (int left = 0, right = index - 1; left < right;) {
		char temp = res[left];
		res[left] = res[right];
		res[right] = temp;
		left++;
		right--;
	}
	return res;
}
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	int *ret = malloc(sizeof(int) * 2);
	*returnSize = 2;
	for (int  start = 0; start < numbersSize - 1; start++) {
		int right = numbersSize - 1;
		int left = start + 1;
		while (left <= right) {
			int index = (left + right) / 2;
			int sum = numbers[start] + numbers[index];
			if (sum == target) {
				ret[0] = start + 1;
				ret[1] = index + 1;
				return ret;
			}
			else if (sum < target) {
				left = index + 1;
			}
			else {
				right = index - 1;
			}
		}
	}
	return ret;
}
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	int *ret = malloc(sizeof(int) * 2);
	*returnSize = 2;
	int left, right;
	for (left = 0, right = numbersSize - 1; left < right;) {
		int sum = numbers[left] + numbers[right];
		if (sum == target) {
			break;
		}
		else if (sum > target) {
			right--;
		}
		else {
			left++;
		}
	}
	ret[0] = left + 1;
	ret[1] = right + 1;
	return ret;
}
int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k){
	if (k <= numOnes) {
		return k;
	} 
	if (k > numOnes && k <= numOnes + numZeros) {
		return numOnes;
	}
	return numOnes -  (k - numOnes - numZeros);
}
//n (n + 1) / 2 = 10e10
//ne2 + n =  10e10 * 2
// (n + 1/2) -  1/4 = 10e10 * 2 + 0.25
//28  2  4    6   8
//	  26 22  16   8
long long* maximumEvenSplit(long long finalSum, int* returnSize){

	long long *ret = malloc(sizeof(long long) * 223607);
	int index = 0;
	for (long long base = 2; finalSum >= base; base += 2) {
		ret[index++] = base;
		finalSum -= base;
	}
	if (finalSum % 2) {
		*returnSize = index;
		ret[index - 1] += finalSum;
	}
	else {
		*returnSize = 0;
	}
	return ret;
}

void bal(double *arr, int index, int length) {
	int max = index;
	int left = index * 2 + 1,
		right = index * 2 + 2;

	if (left <= length - 1 && arr[max] < arr[left]) max = left;
	if (right <= length - 1 && arr[max] < arr[right]) max = right;

	double temp = arr[max];
	arr[max] = arr[index];
	arr[index] = temp;

	if (max != index) {
		bal(arr, max, length);
	}
}
void initHeap(double *arr, int length) {
	int index = length / 2 - 1;
	while (index >= 0) {
		bal(arr, index, length);
		index--;
	}
	return;
}
//x =  2 * a + 1
//y = 2 * a + 2
/
//          1                   2
//       2      3              4
//        					  8
//   4      5 6    7     
//
int halveArray(int* nums, int numsSize){
	double numsCopy[numsSize];
	int count = 0;
	double sum = 0;
	double half = 0;
	for (int i = 0; i < numsSize; i++) {
		numsCopy[i] = (double)nums[i];
		sum += (double)nums[i];
	}
	initHeap(numsCopy, numsSize);
	half = sum / 2;
	while (sum > half) {
		nums[0] = nums[0] / 2;
		sum -= nums[0];
		count++;
		bal(nums, 0, numsSize);
	}
	return count;
}
//[1,2,3,4,5,-1,7,8,9]
//       
int maxSubArray(int* nums, int numsSize){
	int max = 0;
	int ret = INT_MIN;
	for (int i = numsSize - 1; i >= 0; i--) {
		max = fmax(nums[i], nums[i] + max);
		ret = fmax(max, ret);
	}
	return ret;
}

int maxSubarraySumCircular(int* nums, int numsSize){
	int max = 0;
	int ret = INT_MIN;
	int rightMax[numsSize + 1];
	int left = nums[0];
	rightMax[numsSize] = 0;
	for (int i = numsSize - 1; i >= 0; i--) {
		max = fmax(nums[i], nums[i] + max);
		ret = fmax(max, ret);
		rightMax[i] = fmax(rightMax[i + 1], rightMax[i + 1] + nums[i]);
	}
	ret = fmax(ret, left + rightMax[1]);
	for (int i = 1; i < numsSize - 1; i++) {
		left = fmax(nums[i] + left, left);
		ret = fmax(ret, left + rightMax[i + 1]);
		printf("%d %d %d\n", left, rightMax[i + 1], ret);
	}
	return ret;
}

int maxSubarraySumCircular(int* nums, int numsSize){
	int sum = 0;
	int max = nums[0];
	int min = nums[0];
	for (int i = 1; i < numbersSize; i++) {
		max = fmax(nums[i], max + nums[i]);
		min = fmin(nums[i] + min, min);
		sum += nums[i];
	}
	return fmax(max, sum - min);
}
int maxSubarraySumCircular(int* nums, int numsSize){
	int leftMax[numsSize];
	int ret = nums[0];
	int	max = nums[0];
	leftMax[0] = nums[0];
	int sums = nums[0];

	for (int i = 1; i < numsSize; i++) {
		max = fmax(max + nums[i], nums[i]);
		ret = fmax(max, ret);
		leftMax[i] = fmax(leftMax[i - 1], sums += nums[i]);
	}

	int rightMax = nums[numsSize - 1];
	int sums = nums[numsSize - 1];
	for (int i = numsSize - 2; i > 0; i--) {
		rightMax = fmax(rightMax, sums += nums[i]);
		ret = fmax(ret, rightMax + leftMax[i - 1]);
	}
	return ret;
}
struct Node {
	int value;
	struct Node *left;
	struct Node *right;
}
struct Node *revBinaryTree(struct Node *root) {
	if (!root) return root;
	struct Node *temp = root->left;
	root->left = root->right;
	root->right = temp;
	revBinaryTree(root->left);
	revBinaryTree(root->right);
}

#define IS_EMPTY (end < head)

int maxSubarraySumCircular(int* nums, int numsSize){
	int length = 2 * numsSize;
	int queue[length][2];
	int head = 0,
		end = -1;
	int total = 0;
	int res = INT_MIN;

	for (int i = 0; i < length; i++) {
		while (!IS_EMPTY && queue[head % length][0] < i - numsSize) {
			head++;
		}
		total += nums[i % numsSize];
		res = fmax(res, total - !IS_EMPTY ? queue[head % length][1]: 0);
		while (!IS_EMPTY && queue[end % length][1] > total) {
			end--;
		}
		queue[++end % length][0] = i;
		queue[end % length][1] = total;
	}
	return res;
}
#define IS_EMPTY (end < head)

int maxSubArray(int* nums, int numsSize){
	int length = numsSize;
	int queue[length][2];
	int head = 0,
		end = -1;
	int total = nums[0];
	int res = nums[0];
	queue[++end % length][0] = 0;
	queue[end % length][1] = nums[0];

	for (int i = 1; i < length; i++) {
		total += nums[i % numsSize];
		res = fmax(res, total - queue[head % length][1]);
		printf("%d\n", res);
		while (!IS_EMPTY && queue[end % length][1] > total) {
			end--;
		}
		queue[++end % length][0] = i;
		queue[end % length][1] = total;
	}
	return res;
}
int maxAbsoluteSum(int* nums, int numsSize){
	int max = nums[0],
	min = nums[0],
	resMax = nums[0],
	resMin = nums[0];

	for (int i = 1; i < numsSize; i++) {
		max = fmax(max + nums[i], nums[i]);
		resMax = fmax(resMax, max);
		min = fmin(min + nums[i], nums[i]);
		resMin = fmin(resMin, min);
	}
	return fmax(abs(resMax), abs(resMin));
}
struct List Node *current;

struct ListNode *reverse(struct ListNode *node, struct ListNode **head) {
	if (node->next == NULL) {
		*head = node;
	} else {
		reverse(node->next, head)->next = node;
	}
	return node;
}
void reorderList(struct ListNode* head){
	int length = 0;
	struct ListNode *pivot = head;
	struct ListNode *subHead;
	for (struct ListNode *temp = head; temp != NULL; temp = temp->next) {
		length++;
	}
	for (int i = 1; i <= (length - 1) / 2; i++) {
		pivot = pivot->next;
	}
	subHead = pivot->next;
	reverse(subHead, &subHead)->next = NULL;

	if (length / 2) {
		pivot->next = NULL;
	}

	for (struct ListNode *h1 = head, *h2 = subHead; h1 != NULL && h2 != NULL;) {
		struct ListNode *temp1 = h1->next;
		struct ListNode *temp2 = h2->next;
		h1->next = h2;
		h1 = h2->next = temp1;
		h2 = temp2;
	}
}
struct TreeNode *stack[100];
int top = -1;
#define PUSH(node) {\
	stack[++top] = node;\
}
#define POP() (stack[top--])
#define IS_EMPTY (top <= -1)

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	top = -1;
	int *ret = malloc(sizeof(int) * 100);
	int size = 0;
	struct TreeNode *pre = NULL;

	for (struct TreeNode *current = root; current != NULL; current = current->left) {
		PUSH(current);
	}
	while (!IS_EMPTY) {
		while (stack[top]->right && pre == stack[top]->right || stack[top]->right == NULL) {
			pre = current = POP();
			ret[size++] = current->val;
		}

		for (current = stack[top]->right; current != NULL; current = current->left) {
			PUSH(current);
		}

	}
	*returnSize = size;
	return ret;
}
//morris
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int *ret = malloc(sizeof(int) * 100);
	int size = 0;
	struct TreeNode *cur1, *cur2;
	cur1 = root;

	while (cur1 != NULL) {
		cur2 = cur1->left;
		if (cur2 != NULL) {
			while (cur2->right != cur1 && cur2->right != NULL) {
				cur2 = cur2->right;
			}
			if (cur2->right == NULL) {
				ret[size++] = cur1->val;
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;
			}
		}
		else {
			ret[size++] = cur1->val;
		}
		cur1 = cur1->right; //实际是移动到右边子节点或者返回到该节点的父节点
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int *ret = malloc(sizeof(int) * 100);
	int size = 0;
	struct TreeNode *cur1, *cur2;
	cur1 = root;

	while (cur1 != NULL) {
		cur2 = cur1->left;
		if (cur2 != NULL) {
			while (cur2->right != cur1 && cur2->right != NULL) {
				cur2 = cur2->right;
			}
			if (cur2->right == NULL) {
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				ret[size++] = cur1->val;
				cur2->right = NULL;
			}
		}
		else {
			ret[size++] = cur1->val;
		}
		cur1 = cur1->right; //实际是移动到右边子节点或者返回到该节点的父节点
	}
}
struct TreeNode *reverseNodeList(struct TreeNode *node) {
	struct TreeNode *pre = NULL;
	struct TreeNode *tmp;
	for (struct TreeNode *cur = node; node != NULL;) {
		tmp = node->right;
		node->right = pre;
		pre = node;
		node = tmp;
	}
	return pre;
}
void output(struct TreeNode *node, int *ret, int *size) {
	struct TreeNode *head = reverseNodeList(node);
	for (struct TreeNode *cur = head; cur != NULL; cur = cur->right) {
		ret[(*size)++] = cur;
	}
	reverseNodeList(head);
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	int *ret = malloc(sizeof(int) * 100);
	int size = 0;
	struct TreeNode *cur1, *cur2;
	cur1 = root;

	while (cur1 != NULL) {
		cur2 = cur1->left;
		if (cur2 != NULL) {
			while (cur2->right != cur1 && cur2->right != NULL) {
				cur2 = cur2->right;
			}
			if (cur2->right == NULL) {
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;
				output(cur1->left, ret, &size);
			}
		}
		cur1 = cur1->right; //实际是移动到右边子节点或者返回到该节点的父节点
	}
	output(root, ret, &size);
	*returnSize = size;
	return ret;
}

//从中序和先序遍历数组中构建二叉树
int idx;
struct TreeNode *buildRoot(int *preorder, int *inorder, int left, int right) {
	if (right < left) return NULL;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	int pivot;
	root->val = preorder[idx++];
	for (int i = left; i <= right; i++) {
		if (preorder[idx] == inorder[i]) {
			pivot = i;
			break;
		}
	}
	root->left = buildRoot(preorder, inorder, left, pivot - 1);
	root->right = buildRoot(preorder, inorder, pivot + 1, right);
	return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	idx = 0;
	return buildRoot(preorder, inorder, 0, inorderSize - 1);

}

struct TreeNode *stack[3000];
int top = -1;
#define PUSH(node) {\
	stack[++top] = node;\
}
#define POP() (stack[top--])
#define IS_EMPTY (top <= -1)
#define NEW_NODE(node, value) {\
	node = malloc(sizeof(struct TreeNode));\
	node->val = value;\
	node->left = node->right = NULL;\
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	struct TreeNode *root, *pre;
	int index = 0;
	pre = NULL;
	NEW_NODE(root, preorder[0]);
	struct TreeNode *head = root;
	PUSH(root);
	for (int i = 1; i < preorderSize; i++) {
		if (stack[top]->val != inorder[index]) {
			NEW_NODE(root, preorder[i]);
			stack[top]->left = root;
			PUSH(root);
		}
		else {
			while (stack[top] == inorder[index]) {
				pre = POP();
				index++;
			}
			NEW_NODE(root, preorder[i]);
			pre->right = root;
		}
	}
	return head;
}

//从中序和后序数组中构建二叉树
int idx;
struct TreeNode *buildRoot(int *postorder, int *inorder, int left, int right) {
	if (right < left) return NULL;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	int pivot;
	root->val = postorder[idx--];
	for (int i = left; i <= right; i++) {
		if (root-> val == inorder[i]) {
			pivot = i;
			break;
		}
	}
	root->right = buildRoot(postorder, inorder, pivot + 1, right);
	root->left = buildRoot(postorder, inorder, left, pivot - 1);
	return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	idx = postorderSize - 1;
	return buildRoot(postorder, inorder, 0, inorderSize - 1);
}

struct TreeNode *stack[3000];
int top = -1;
#define PUSH(node) {\
	stack[++top] = node;\
}
#define POP() (stack[top--])
#define IS_EMPTY (top <= -1)
#define NEW_NODE(node, value) {\
	node = malloc(sizeof(struct TreeNode));\
	node->val = value;\
	node->left = node->right = NULL;\
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	struct TreeNode *root, *pre;
	int idx = inorderSize - 1;
	NEW_NODE(root, postorder[postorderSize - 1]);
	struct TreeNode *head = root;
	PUSH(root);
	for (int i = postorderSize - 2; i >= 0; i--) {
		if (stack[top]->val != inorder[idx]) {
			NEW_NODE(root, postorder[i]);
			stack[top]->right = root;
			PUSH(root);
		}
		else {
			while (!IS_EMPTY && stack[top]->val == inorder[idx]) {
				pre = POP();
				idx--;
			}
			NEW_NODE(root, postorder[i]);
			pre->left = root;
			PUSH(root);
		}
	}
	return head;
}

//从先序和后序遍历构建二叉树
struct TreeNode *stack[30];
int top = -1;
#define PUSH(node) {\
	stack[++top] = node;\
}
#define POP() (stack[top--])
#define IS_EMPTY (top <= -1)
#define NEW_NODE(node, value) {\
	node = malloc(sizeof(struct TreeNode));\
	node->val = value;\
	node->left = node->right = NULL;\
}
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
	struct TreeNode *root, *pre;
	int map[31];
	int idx = 0;
	int cmpIdx = postorderSize - 1;
	NEW_NODE(root, preorder[0]);
	struct TreeNode *head = root;
	PUSH(root);

	for (int i = 0; i < postorderSize; i++) {
		map[postorder[i]] = i;
	}
	for (int i = 1; i < preorderSize; i++) {
		NEW_NODE(root, preorder[i]);
		if (map[stack[top]->val] == idx) {
			while(map[stack[top]->val] == idx) {
				POP();
				idx++;
			}
			stack[top]->right = root;
		}
		else {
			stack[top]->left = root;
		}
		PUSH(root);
	}
	return head;
}
//1245367
//4526731
struct TreeNode *buildTree(int *preorder, int l1, int r1, int *postorder, int l2, int r2) {
	if (l1 > r1) return NULL;
	struct TreeNode *root;
	int k;
	NEW_NODE(root, preorder[l1]);
	if (l1 == r1) return root;
	
	for (int i = l2; i < r2; i++) {
		if (preorder[l1 + 1] == postorder[i]) {
				k = i;
				break;
		}
	}
	int length = k - l2 + 1;
	root->left = buildTree(preorder, l1 + 1, l1 + length, postorder, l2, k - 1);
	root->right = buildTree(preorder, l1 + length + 1, r1, postorder, k + 1, r2 - 1);

	return root;
}

struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
	return buildTree(preorder, 0, preorderSize - 1, postorder, 0, postorderSize - 1);
}
//      1
//  2		3
//4   5   6   7
//12 34
//123 45
//-1 -2 -3
// pre + nums[i] 
// 符号相同，比之前绝对值大, 累加更新最大值, 竞争数置为 0
// 符号相同，比之前绝对值小，{
//	
//	累加值 vs 当前数
//
//}
// 符号不同，最大值更新为当前数 + 另一个竞争数
//
// 5 -3 1 -8 {
//	
// }
// 5 -3 -3
//
// 5 -7 6
//
// -9 7 -5
//1 2 3 4 5 6
// 5 -3 5 5 -3
//8 -4 7 2
//
// i - j <= n
//  j >= i - n
//  i + j <= n + 2j
//
