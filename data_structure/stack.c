#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H_
#define STACK_H_
#define true 1
#define false 0
typedef _Bool bool;

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct StackEle {
	void *ele;
	struct StackEle *pre;
	struct StackEle *next;
} StackEle;

struct Stack;

typedef StackEle QueueEle;

typedef struct Queue {
	QueueEle *head;
	QueueEle *end;
	int length;
} Queue;

typedef struct Stack {
	StackEle *bottom;
	StackEle *top;
	int length;
} Stack;

#define IS_EMPTY(stackList) ((stackList)->length == 0)
void enqueue(Queue * const queueList, void *item) {
	QueueEle *one = (QueueEle*)malloc(sizeof(QueueEle));
	one->ele = item;
	one->next = NULL;
	if (queueList->length == 0) {
		queueList->head = one;
		one->pre = NULL;
	} 
	else {
		one->pre = queueList->end;
	}
	queueList->end = one;
	queueList->length++;
}

void *dequeue(Queue * const queueList) {
	if (queueList->length == 0) return NULL;
	QueueEle *head = queueList->head;
	queueList->head = head->next;
	queueList->length--;
	if (queueList->length == 0) queueList->end = NULL;
	return head;
}

void push(struct Stack * const stackList, void *item) {
	StackEle *one = (StackEle*)malloc(sizeof(StackEle));
	one->ele = item;
	one->next = NULL;
	if (stackList->length == 0) {
		stackList->bottom = one;
		one->pre = NULL;
	} 
	else {
		one->pre = stackList->top;
	}
	stackList->top = one;
	stackList->length++;
}
void *pop(struct Stack * const stackList) {
	if (stackList->length == 0) return NULL;
	StackEle *top = stackList->top;
	stackList->top = top->pre;
	stackList->length--;
	if (stackList->length == 0) stackList->bottom = NULL;
	else stackList->top->next = NULL;

	return top;
}

Queue *newQueue(void) {
	Queue *queueList = (Queue*)malloc(sizeof(Queue));
	queueList->head = queueList->end = NULL;
	queueList->length = 0;
	return queueList;
}
Stack *newStack(void) {
	Stack *stackList = (Stack*)malloc(sizeof(Stack));
	stackList->top = stackList->bottom = NULL;
	stackList->length = 0;
	return stackList;
}
TreeNode *newTreeNode(int val) {
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = node->right = NULL;
	node->val = val;
	return node;
}
void traversePreorder(TreeNode *root) {
	Stack *stackList = newStack();
	StackEle *item;
	push(stackList, root);
	while (!IS_EMPTY(stackList)) {
		item = pop(stackList);
		printf("%d ", ((TreeNode*)(item->ele))->val);
		if (((TreeNode*)(item->ele))->right) push(stackList, ((TreeNode*)(item->ele))->right);
		if (((TreeNode*)(item->ele))->left) push(stackList, ((TreeNode*)(item->ele))->left);
	}
}

void traversePostorder(TreeNode *root) {
	Stack *stackList = newStack();
	Stack *rightChecked = newStack();
	TreeNode *p = root;
	_Bool *checkRight;

	while (p != NULL || !IS_EMPTY(stackList)) {
		while (p != NULL) {
			push(stackList, p);
			checkRight = (_Bool*)malloc(sizeof(_Bool));
			*checkRight = 0;
			push(rightChecked, checkRight);
			p = p->left;
		}
		if (*(checkRight  = (_Bool*)(((StackEle*)pop(rightChecked))->ele)) == 1) {
			p = (TreeNode*)(((StackEle*)pop(stackList))->ele);
			printf("%d ", p->val);
			p = NULL;
		} else {
			p = (TreeNode*)(((StackEle*)pop(stackList))->ele);
			*checkRight = 1;
			push(rightChecked, checkRight);
			push(stackList, p);
			p = p->right;
		}

	}
}
//		1
//	2	    2
//4  3	 3   4
bool isSymmetric(struct TreeNode* root){
	if (root == NULL) return true;
	Stack *stackList = newStack();
	TreeNode *left, *right;
	push(stackList, root->left);
	push(stackList, root->right);
	while(!IS_EMPTY(stackList)) {
		left = (TreeNode*)(((StackEle*)pop(stackList))->ele);
		right = (TreeNode*)(((StackEle*)pop(stackList))->ele);
		if ((left == NULL && right != NULL) || (right == NULL && left != NULL)) return false; 
		if (left != NULL && right != NULL) {
			if (left->val != right->val) return false;
			push(stackList, left->right);
			push(stackList, right->left);
			push(stackList, left->left);
			push(stackList, right->right);
		}
	}
	return true;
}
bool checkMirror(struct TreeNode *left, struct TreeNode *right) {
	if (left == NULL && right == NULL) return true;
	else if (left == NULL || right == NULL) return false;
	else if (left->val != right->val) return false;
	return checkMirror(left->right, right->left) && checkMirror(left->left, right->right);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	Queue *queueList = newQueue();
	Queue *temp = newQueue();
	QueueEle *item;
	struct TreeNode *node;
	int *subArray;
	int size;
	*returnSize = 0;
	*returnColumnSizes = NULL;
	int **retArray = NULL;

	enqueue(queueList, root);
	while(!IS_EMPTY(queueList)) {
		subArray = NULL;
		size = 0;
		while (!IS_EMPTY(queueList)) {
			item = dequeue(queueList);
			enqueue(temp, item);
			subArray = (int*)realloc(subArray, (++size) * sizeof(int));
			subArray[size - 1] = ((TreeNode*)(item->ele))->val;
		}
		if (size != 0) {
			retArray = (int**)realloc(retArray, (*returnSize+1) * sizeof(int*));
			*returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize+1) * sizeof(int));
			retArray[*returnSize] = subArray;
			(*returnColumnSizes)[*returnSize] = size;
			*returnSize = *returnSize + 1;
		}
		while(!IS_EMPTY(temp)) {
			node = (TreeNode*)(dequeue(temp)->ele);
			if (node->left != NULL) enqueue(queueList, node->left);
			if (node->right != NULL) enqueue(queueList, node->right);
		}
	}
	return retArray;
}
/** void traverseInorder(TreeNode *root)  */
/** Stack *stackList = newStack(); */
/** StackEle *item; */
/** TreeNode *node; */
/**  */
/** while (!IS_EMPTY(stackList) || ) */
/** if (node == NULL) { */
/**     item = pop(stackList); */
/**     printf("%d ", item->ele->val); */
/** } */
/** if (node->right) push(stackList, node->right); */
/** if (node->left) push(stackList, node->left); */
/**  */
/** } */
//				50
//		43				70
//	32		49		67		79struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

}
/** mid = (numsSize - 1) / 2; */
/** node root = nums[(numsSize - 1) / 2]; */
/** root->left = sortedArrayToBST(nums, mid); */
/** root->right = sortedArrayToBST(nums + mid + 1); */
//	<Del>[-10,-3,0,5,9]
//			    0
//-10 			null
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	int mid = (numsSize - 1) / 2;
	root->val = nums[mid];
	root->left = NULL;
	root->right = NULL;
	if (numsSize >= 2) {
		root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
		if (numsSize > 2) {
			root->left = sortedArrayToBST(nums, mid);
		}
	} 
	return root;
}
//[12345000
//[1,1,2,3,3,3,5,6,7,7]
//[]
void sortedArrayToSet(int *nums, int size) {
	int p1 = 0,
		p2 = 1;

	int temp;
	for (; p2 < size - 1;) {
		if (nums[p2] == nums[p1]) {
			nums[p1 + 1] = nums[p2+1];
		}
		else {
			p1++;
		}
		p2++;
	}
}
void reverse(int *nums, int size) {
	int i = 0;
	int temp;
	while (i < size / 2) {
		temp = nums[i];
		nums[i] = nums[size - i - 1];
		nums[size - i - 1] = temp;
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	
	reverse(nums1, nums1Size);
	reverse(nums1, n);
	reverse(nums1 + n, m);
	printf("ddddd");
	int temp;
	int i = 0;
	int p1 = n - 1,
		p2 = 0;

	while (p2 < nums2Size && p1 < nums1Size) {
		if (nums1[p1] > nums2[p2]) {
			nums1[i++] = nums2[p2];
			p2++;
		}
		else {
			nums1[i++] = nums1[p1];
			p1++;
		}
	}
	while (p2 < nums2Size) {
		nums1[i++] = nums2[p2++];
	}
	return nums1;
}

void main(void) {
	/** TreeNode *root; */
	/** TreeNode *new = root = newTreeNode(50); */
	/** new->left = newTreeNode(43); */
	/** new->right = newTreeNode(43); */
	/** new = root->left; */
	/** new->left = newTreeNode(32); */
	/** new->right = newTreeNode(2); */
	/** new = root->right; */
	/** new->left = newTreeNode(21); */
	/** new->right = newTreeNode(32); */
    /**  */
	/** printf("%d ", isSymmetric(root)); */
	//traversePreorder(root);
	//traversePostorder(root);
	/** int ar1[] = {1,2,3,0,0,0}, */
	/**     ar2[] = {2, 5, 6}; */

	/** merge(ar1, 6, 3, ar2, 3, 3); */
	int ar1[] = {1,2,3, 3,3 ,5, 6, 6, 7, 9, 9}
	sortedArrayToSet(ar1, 11);
	for (int *i = ar1; i < ar1 + 11; i++) {
		printf("%d ", *i);
	}
	
}


#endif

