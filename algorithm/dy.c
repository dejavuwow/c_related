#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
//abcdd
int lengthOfLongestSubstring(char * s){
	int l = strlen(s);
	int map[128] = {0};
	int max = 0;
	int left = 0, right = 0;
	for (int left = 0; left < l; left++) {
		while (right < l && map[s[right]] == 0) {
			map[s[right]]++;
			right++;
		}
		max = MAX(max, right - left);
		map[s[left]]--;
	}
	return max;
}
// 123321
// d[i] = d[j] && check[i+1]; 
//dy[i] = dy[i - 1] && s[ihhhhhhhh]
#define CHECK(j , i) (s[j] == s[j+i] ? ((i == 0 || i == 1) ? 1 : dy[j + 1][i-2]) :  0)
char * longestPalindrome(char * s){
	int l = strlen(s);
	int dy[10][10] = {-1};
	int max = 0;
	char *str = (char*)malloc(sizeof(char) * 1001);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j + i < l; j++) {
			if (j == 0 && i == 2) {
				printf("%d %d\n", s[j] == s[i+ j], dy[1][1]);
			}
			if (dy[j][i] = CHECK(j, i)) {
				if (max < i + 1) {
					strncpy(str, &s[j], i+ 1);
					str[i+1] = '\0';
					max = i + 1;
				}

			}
		}
	}
	return str;
}
bool increasingTriplet(int* nums, int numsSize){

}
//1->2->3->4->5
//1->3->2->5->4->7->6
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* oddEvenList(struct ListNode* head){
	ListNode *oddHead = head;
	ListNode *oddCur = head;
	ListNode *evenHead = head->next;
	ListNode *evenCur = head->next;
	ListNode *current = head->next->next;
	int i = 2;
	while (current) {
		if (++i % 2 == 1) {
			oddCur->next = current;
			oddCur = oddCur->next;
		} else {
			evenCur->next = current;
			evenCur = evenCur->next;
		}
		current = current->next;
	}
	oddCur->next = evenHead;
	evenCur->next = NULL;

	return head;
}
// 1 2 3 4
// 		   6 7 8
// 	   8 10	
// 1234578 8 9 678
// 8967812 3 4 678
//   l -  k = f;
//
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	ListNode *current;
	ListNode *o_current;
	int la = 1;
	int lb = 1;
	for (current = headA; current != NULL; current = current->next, la++);
	for (current = headB; current != NULL; current = current->next, lb++);
	current = la - lb > 0 ? headA : headB;
	o_current = current == headA ? headB : headA;
	for (int i = 0; current != NULL; current = current->next, i++) {
		if (current == o_current) break;
		if (i >= abs(la - lb)) {
			o_current = o_current->next;
		}
	}
	return current;
}
#define IS_EMPTY(stackList) ((stackList)->length == 0)
typedef struct StackEle {
	void *ele;
	struct StackEle *pre;
	struct StackEle *next;
} StackEle;

typedef struct Stack {
	StackEle *bottom;
	StackEle *top;
	int length;
} Stack;

typedef StackEle QueueEle;

typedef struct Queue {
	QueueEle *head;
	QueueEle *end;
	int length;
} Queue;

Stack *newStack(void) {
	Stack *stackList = (Stack*)malloc(sizeof(Stack));
	stackList->top = stackList->bottom = NULL;
	stackList->length = 0;
	return stackList;
}
Queue *newQueue(void) {
	Queue *queueList = (Queue*)malloc(sizeof(Queue));
	queueList->head = queueList->end = NULL;
	queueList->length = 0;
	return queueList;
}
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

QueueEle *dequeue(Queue * const queueList) {
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
StackEle *pop(struct Stack * const stackList) {
	if (stackList->length == 0) return NULL;
	StackEle *top = stackList->top;
	stackList->top = top->pre;
	stackList->length--;
	if (stackList->length == 0) stackList->bottom = NULL;
	else stackList->top->next = NULL;

	return top;
}
typedef struct TreeNode TreeNode;
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	Stack *stackList = newStack();
	push(stackList, root);
	int *head = NULL;
	*returnSize = 0;
	TreeNode *current = root;

	while (current || stackList->lenth > 0) {
		while(current) {
			push(stackList, current);
			current = current->left;
		}
		current = (TreeNode*)pop(stackList)->ele;
		head = (int*)realloc(head, sizeof(int) * (*returnSize + 1));
		head[*returnSize] = current->val;
		*returnSize = *returnSize + 1;

		current = current->right;
	}
	return head;

}
void reverse(int *array, int size) {
	int temp;
	for (int i = 0; i < size / 2; i++) {
		temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i -1] = temp;
	}
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	Queue *queueList = newQueue();
	Queue *temp = newQueue();
	QueueEle *item;
	struct TreeNode *node;
	int *subArray;
	int leftToRight = 1;
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
			if (!leftToRight) {
				reverse(subArray, size);
			}
			leftToRight = !leftToRight;
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
//[root,[left], [right]]
//[[left], root, [right]]
typedef struct TreeNode TreeNode;
struct TreeNode *buildSubTree(int *preorder, int *index, int *map, int start, int end) {
	if (start > end) return NULL;
	TreeNode *root = malloc(sizeof(TreeNode));
	root->val = preorder[*index];
	int findIndex = map[root->val];
	*index = *index + 1;
	root->left = buildTree(preorder, index, map, start, findIndex - 1);
	root->right = buildTree(preorder, index, map, findIndex + 1, end);
	return root;

}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	int map[inorderSize];
	for (int i = 0; i < inorderSize; i++) {
		map[inorder[i]] = i;
	}
	int index = 0;
	return buildSubTree(preorder, &index, map, 0, inorderSize - 1)

}

#define SIZE 6000

#define NEW_NODE(val, node) {\
	node = malloc(sizeof(TreeNode));\
	node->val = val;\
	node->left = NULL;\
	node->right = NULL;\
}
struct TreeNode* buildTreeLoop(int* preorder, int preorderSize, int* inorder, int inorderSize){
	TreeNode *stack[SIZE];
	int top = -1;
	int index = 0;
	TreeNode *root;
	TreeNode *right;
	NEW_NODE(preorder[0], root);
	TreeNode *ans = root;
	stack[++top] = root;
	for (int i = 1; i < preorderSize; i++) {
		if (stack[top]->val != inorder[index]) {
			NEW_NODE(preorder[i], root);
			stack[++top] = root;
		} else {
			root = stack[top--];
			NEW_NODE(preorder[i], right);
			root->right = right;
			index++;
		}
	}
	return ans;

}
//   1
// 2   3
//4 5 6 7
// 1 
int main(void) {
	int ar[5] = {1,2,3,4,5};
	ListNode *head, *current;
	ListNode *pre = NULL;
	for (int i = 0; i < 5; i++) {
		current = (ListNode*)malloc(sizeof(ListNode));
		current->val = ar[i];
		current->next = NULL;
		if (!pre) {
			head = current;
		}
		else {
			pre->next = current;
		}
		pre = current;
	}
	/** for (ListNode *k = head; k != NULL; k = k->next) { */
	/**     printf("%d \n", k->val); */
	/** } */
	ListNode *ret = oddEvenList(head);
	for (ListNode *k = ret; k != NULL; k = k->next) {
		printf("%d \n", k->val);
	}


	return 0;
}

