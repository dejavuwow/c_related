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

Stack *newStack(void) {
	Stack *stackList = (Stack*)malloc(sizeof(Stack));
	stackList->top = stackList->bottom = NULL;
	stackList->length = 0;
	return stackList;
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
typedef struct TreeNode TreeNode;
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	Stack *stackList = newStack();
	push(stackList, root);
	int *head = NULL;
	*returnSize = 0;
	TreeNode *current = root;
	
	while(current->left) {
		current = current->left;
		push(stackList, current);
	}
	head = (int*)realloc(head, sizeof(int) * (*returnSize + 1));
	head[*returnSize] = current->val;
	*returnSize = *returnSize + 1;
	
	current = pop(stackList)->right;

}
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

