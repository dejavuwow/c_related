#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H_
#define STACK_H_

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

typedef struct Stack {
	StackEle *bottom;
	StackEle *top;
	int length;
} Stack;

#define IS_EMPTY(stackList) ((stackList)->length == 0)

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
	TreeNode *p = root;
	while (p != NULL || !IS_EMPTY(stackList)) {
		while (p != NULL) {
			push(stackList, p);
			p = p->left;
		}
		p = (TreeNode*)(((StackEle*)pop(stackList))->ele);
		push(stackList, p);
		p = p->right;
		if (p == NULL) {
			p = (TreeNode*)(((StackEle*)pop(stackList))->ele);
			printf("%d ", p->val);
			p = NULL;
		} 
	}
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
//	32		49		67		79

void main(void) {
	TreeNode *root;
	TreeNode *new = root = newTreeNode(50);
	new->left = newTreeNode(43);
	new->right = newTreeNode(70);
	new = root->left;
	new->left = newTreeNode(32);
	new->right = newTreeNode(49);
	new = root->right;
	new->left = newTreeNode(67);
	new->right = newTreeNode(79);

	//traversePreorder(root);
	traversePostorder(root);
}


#endif

