typedef struct Queue {
	struct TreeNode *list[0x400];
	int head;
	int end;
};
typedef struct Stack {
	struct TreeNode *list[0x800];
	int top;
};
#define QUEUE_EMPTY(queue) (queue.head > queue.end)
#define STACK_EMPTY(stack) (stack.top >= 0)
#define PUSH_STACK(stack, item) (stack.list[++stack.top] = item)
#define POP_STACK(stack) (stack.list[stack.top--])
#define ENQUEUE(queue, item) (queue.list[++queue.end % 0x400] = item)
#define DEQUEUE(queue) (queue.list[queue.head++ % 0x400])

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	int *temp, num;
	Queue queue;
	queue.head = 0;
	queue.end = -1;
	int **ret = malloc(sizeof(int*) * 0x800);
	*returnColumnSizes = malloc(sizeof(int) * 0x800);
	int length = 0;

	while (!QUEUE_EMPTY(queue)) {
		struct TreeNode *list = malloc(sizeof(struct TreeNode) * 0x400);
		int subLen = 0;
		while (!QUEUE_EMPTY(queue)) {
			list[subLen++] = DEQUEUE(queue);
		}
		for (int i = 0; i < subLen; i++) {
			if (list[i]->left) {
				ENQUEUE(queue, list[i]->left);
			}
			if (list[i]->right) {
				ENQUEUE(queue, list[i]->right);
			}
		}
		if (subLen > 0) {
			for (int i = 0; i < subLen; i++) {
				ret[length][i] = list[i]->val;
			}
			(*returnColumnSizes)[length++] = subLen;
		}
	}
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		temp = ret[i];
		num = (*returnColumnSizes)[i];
		ret[i] = ret[j];
		(*returnColumnSizes)[i] = (*returnColumnSizes)[j];
		ret[j] = temp;
		(*returnColumnSizes)[j] = num;
	}
	*returnSize = length;
	return ret;

}
//12345678
//[0,-10,5,null,-3,null,9]            
//              0
//          -10   5
//        null -3 null 9
struct TreeNode *build(struct ListNode *start, struct ListNode *end) {
	if (start == end) return NULL;
	struct ListNode *c1, *c2;
	c1 = c2 = start;
	while (1) {
		if (c2->next == end) {
			break;
		}
		if (c2->next->next == end) {
			c2 = c2->next;
			break;
		}
		c1 = c1->next;
		c2 = c2->next->next;
	}
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->val = c1->val;
	root->left = build(start, c1);
	root->right = build(c1->next, end);
	return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
	return build(head, NULL);
}

//优化
//    		0
//   -10         0
//  null -10  null  0
//[-10,-3,0,5,9]
//[0,-10,0,null,-10,null,0]
struct TreeNode *build(struct ListNode **head, int start, int end) {
	if (start > end) return NULL;
	int mid = (start + end) / 2;
	root->left = build(head, start, mid - 1);
	root->val = (*head)->val;
	root->right = build(head, mid + 1, end);
	*head = (*head)->next;
	return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
	int l = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next, l++);
	return build(&head, 0, l - 1);
}
int max;
void dfs(struct TreeNode *root, int height) {
	height++;
	if (root->left == NULL && root->right == NULL) {
		max = height < max ? height : max;
	}
	else if (root->right) {
		dfs(root->right, height);
	}
	else {
		dfs(root->left, height);
	}
}
int minDepth(struct TreeNode* root){
	max = INT_MAX;
	if (root == NULL) return 0;
	dfs(root, 0);
	return max;
}

bool hasPathSum(struct TreeNode* root, int targetSum){
	if (root == NULL || root->val > targetSum) return false;
	else if (root->val == targetSum) return true;
	return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

//[1,-2,-3,1,3,-2,null,-1]
//-1
//                 1
//            -2       -3
//         1    3    -2   null
//      -1
int list[5000];
int l;
void dfs(struct TreeNode *root, int targetSum, int **ret, int *returnColumnSizes, int length) {

	if (root == NULL || targetSum < root->val) return;
	if (targetSum == root->val && root->left == NULL && root->right == NULL) {
		list[length++] = root->val;
		int *group = malloc(sizeof(int) * length);
		ret[l] = group;
		returnColumnSizes[l++] = length;
		return;
	}
	if (targetSum > root->val) {
		list[length++] = root->val;
		dfs(root->left, targetSum - root->val, length);
		dfs(root->right, targetSum - root->val, length);
	}

}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
	int **ret = malloc(sizeof(int*) * 3000);
	(*returnColumnSizes) = malloc(sizeof(int) * 3000);
	l = 0;
	dfs(root, targetSum, ret, *returnColumnSizes, 0);
	*returnSize = l;
	return ret;
}
void dfs(struct TreeNode *root, struct TreeNode **pre) {
	if (root == NULL) return;
	if (*pre) {
		(*pre)->right = root;
		(*pre)->left = NULL;
	}
	*pre = root;
	dfs(root->left, pre);
	dfs(root->right, pre);
}
void flatten(struct TreeNode* root){
	struct TreeNode *pre = NULL;
	dfs(root, &pre);
}
