#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./mergesort.h"
#include "uthash.h"
#include <stdbool.h>
#ifndef version
#error yes this
#endif
void printArray(int array[], int array_size)
{
	for (int *temp = array; temp < array + array_size; temp++)
		printf("%d ", *temp);
	putchar('\n');
}


void swap(int *a, int *b) {
	int value = *a;
	*a = *b;
	*b = value;
}
void quickSort(int array[], int i, int j) {
	if (i >= j) return;
	int pivot = array[j];
	int end = j - 1;
	int start = i;
	while (1) {
		while (array[start] < pivot) start++;
		while (array[end] > pivot) end--;
		if (start < end) {
			swap(&array[start], &array[end]);
			start++;
			end--;
		}
		else break;
	}

	array[j] = array[start];
	array[start] = pivot;
	printf("%d %d\t", i, j);
	quickSort(array, i, start - 1);
	quickSort(array, start + 1, j);
}
_Bool containsDuplicate(int* nums, int numsSize){
	quickSort(nums, 0, numsSize - 1);
	for (int *k = nums; k < nums + numsSize; k++) {
		printf("%d\t", *k);
	}
	int i = 0;
	do {
		if (nums[++i] == nums[i - 1]) return 1;
	} while (i < numsSize - 1);
	return 0;
}
int comp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	qsort(nums1, nums1Size, sizeof(int), comp);
	qsort(nums2, nums2Size, sizeof(int), comp);
	printArray(nums1, nums1Size);
	printArray(nums2, nums2Size);
	int *returnArray = (int*)malloc(sizeof(int) * (nums1Size >= nums2Size ? nums1Size : nums2Size));
	int p1, p2;
	int p3 = 0;
	for (p1 = 0, p2 = 0; p1 < nums1Size && p2 < nums2Size;) {
		if (nums1[p1] == nums2[p2]) {
			//printf("%d, %d, %d\n", p1, p2, nums1[p1]);
			returnArray[p3++] = nums1[p1];
			p1++;
			p2++;
		}
		else {
			if (nums1[p1] < nums2[p2]) {
				p1++;
			}
			else p2++;
		}
	}
	*returnSize = p3;
	return returnArray;
}
char *ret(void) {
}

int reverse(int x){
	if (x == -0x7fffffff) return 0;
	int sign = x >= 0 ? 1 : -1;
	x = abs(x);
	int value;
	int arr[10];
	int length = 0;

	while (x >= 10) {
		value = x % 10;
		x /= 10;
		arr[length++] = value;
	}
	arr[length] = x;

	printArray(arr, length + 1);
	value = 0;
	if (length < 9) {
		for (int i = 0, j = length; i <= length; i++, j--) {
			value += arr[i] * pow(10, j);
		}
	}
	else {
		if (arr[0] > 2) value = 0;
		else {
			int i = 0, j = length;
			do {
				value += arr[i] * pow(10, j);
				printf("%d\n", value);
				if (value < 0) {
					if (!(value == -0x10000000 && sign == -1)) {
						value = 0;
					}
					break;
				}
				i++;
				j--;
			} while (i <= length);
		}
	}
	printf("%d", value * sign);
	return value * sign;

}
struct my_struct {
	int id;                    /* key */
	int num;
	UT_hash_handle hh;         /* makes this structure hashable */
};

struct my_struct *users = NULL; 

void delete_all() {
	struct my_struct *current_user, *tmp;

	HASH_ITER(hh, users, current_user, tmp) {
		HASH_DEL(users,current_user);  /* delete; users advances to next */
		free(current_user);            /* optional- if you want to free  */
	}
}
void add_user(int user_id){
	struct my_struct *s;

	s = malloc(sizeof(struct my_struct));
	s->id = user_id;
	s->num = 1;
	HASH_ADD_INT( users, id, s );  /* id: name of key field */
}

struct my_struct *find_user(int user_id) {
	struct my_struct *s;

	HASH_FIND_INT( users, &user_id, s );  /* s: output pointer */
	return s;
}
#define my you
#define you 'n'

bool isAnagram(char * s, char * t){
	struct my_struct *p = NULL;
	bool ret = true;
	for (int i = 0; s[i] != '\0'; i++) {
		if ((p = find_user(s[i])) != NULL) {
			p->num++;
		} else {
			add_user(s[i]);
		}
	}
	for (int i = 0; t[i] != '\0'; i++) {
		if ((p = find_user(t[i])) != NULL) {
			p->num--;
		}
	}
	for (struct my_struct *s = users; s != NULL; s = s->hh.next) {
		if (s->num > 0) {
			ret = false;
			break;
		}
	}
	return ret;
}
#define CHECK_ASC(c) (\
		((c) >= 0x30 && (c) <= 0x39)\
		? true\
		: ((c) >= 0x41 && (c) <= 0x5a)\
		? true\
		: ((c) >= 0x61 && (c) <= 0x7a)\
		? true\
		: false\
		)

#define CHECK_EQUAL(a, b) (\
		(a) == (b)\
		? true\
		: (((a) >= 0x41 && (a) <= 0x5a) && (a) == (b) - 0x20)\
		? true\
		: (((a) >= 0x61 && (a) <= 0x7a) && (a) - 0x20 == (b))\
		? true\
		: false\
		)
bool isPalindrome(char * s){
	bool ret = true;
	int length;
	int head = 0;
	for (char *temp = s; *temp != '\0'; temp++, length++);
	int tail = length - 1;

	while (&s[head] < &s[tail]) {
		if (!CHECK_ASC(s[head])) {
			head++;
			continue;
		} 
		if (!CHECK_ASC(s[tail])) {
			tail--;
			continue;
		}
		if (!CHECK_EQUAL(s[head], s[tail]))	{
			printf("%c %c\n", s[head], s[tail]);
			ret = false;
			break;
		}
		head++;
		tail--;
	}
	return ret;
}
int myAtoi(char * s){
	int sign = 1;
	char *temp = s;
	int ret = 0;
	while (*temp == ' ') temp++;
	if (*temp == '-') {
		temp++;
		sign = -1;
	} else if (*temp == '+') temp++;
	if (*temp < 0x30 || *temp > 0x39) ret = 0;
	else {
		while (*temp >= 0x30 && *temp <= 0x39) {
			int a = ((long long)ret * 10) + sign * (*temp - '0');
			if ((a - sign * (*temp - '0')) / 10 != ret) {
				printf("***");
				ret = sign == -1 ? -0x80000000 : 0x7fffffff;
				break;
			} 
			ret = ret * 10 + sign * (*temp - '0');
			temp++;
		}
	}
	return ret;
}
//ababa
int *getNext(char *needle, int needleLength) {
	int *next = (int*)malloc(sizeof(int) * (needleLength + 1));
	int j = -1;
	int i = 0;
	next[0] = -1;
	for (; needle[i] != '\0';) {
		if (-1 == j || needle[i] == needle[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	return next;

}
int strStr(char * haystack, char * needle){
	int needleLength = 0 ,haystackLength = 0;
	for (char *temp = needle; *temp != '\0'; temp++, needleLength++);
	for (char *temp = haystack; *temp != '\0'; temp++, haystackLength++);
	int *next = getNext(needle, needleLength);
	for (int i = -1, j = -1; i < haystackLength; i++) {
		if (j == -1 || needle[j] == haystack[i]) {
			j++;
		} else {
			j = next[j];
			i--;
		}
		printf("%d %d\n", j, i);
		if (j == needleLength) return i - j + 1;
	}
	free(next);
	return -1;
}
//1
//11
//21
//1211
//111221
//312211
//12112221
//1112213211

char *genStr(char *str)
{
	int i = 1;
	int n = 1;
	char *newStr = (char*)malloc(sizeof(char));
	newStr[0] = '1';
	newStr[1] = '\0';
	char tt[3] = {'\0'};
	//char *temp = str + 1;
	//printf("%s\n", str);
	for (char *temp = str; *temp != '\0'; temp++) {
		if (*temp != *(temp + 1)) {
			tt[0] = i + 0x30;
			tt[1] = *temp;
			realloc(newStr, n += 3);
			strncat(newStr, "nih", 2);
			i = 1;
		} else {
			i++;
		}
		/** printf("%s\n", tt); */
		/** printf("%s", newStr); */
	}
	free(str);

	return newStr;
}
char * countAndSay(int n){
	char *str = (char*)malloc(sizeof(char) * 2);
	str[0] = '1';
	str[1] = '\0';
	while(n > 1) {
		str = genStr(str);
		n--;
	}
	return str;
}
char * longestCommonPrefix(char (*strs)[5], int strsSize){
	char *commonPrefix = (char*)malloc(sizeof(char) * 201) ;
	int index = 0;
	char temp;
	int end = 0;
	for (int i = 0; strs[0][i] != '\0'; i++) {
		temp = strs[0][i];
		for (int j = 1; j < strsSize; j++) {
			if (temp != strs[j][i]) {
				end = 1;
				break;
			};
		}
		if (end) break;
		else {
			commonPrefix[index++] = temp;
		}
	}
	commonPrefix[index] = '\0';
	return commonPrefix;

}
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL) return NULL;
	struct ListNode *current = head;
	struct ListNode *pre = NULL;
	for (struct ListNode *temp;
			current != NULL; current = temp)
	{
		temp = current->next;
		current->next = pre;
		pre = current;
	}
	return pre;

}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *head;
	struct ListNode *temp;
	struct ListNode *current = NULL;
	struct ListNode *temp1 = l1;
	struct ListNode *temp2 = l2;

	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->val <= temp2->val) {
			temp = temp1;
			temp1 => temp1->next;
		}
		else {
			temp = temp2;
			temp2 = temp2->next;
		}
		if (current == NULL) {
			current = head = temp;
		}
		else {
			current->next = temp;
			current = temp;
		}
	}
	temp = temp1 != NULL ? temp1 : temp2;
	while (temp != NULL) {
		current->next = temp;
	}
	return head;

}
bool isPalindrome = true;
void checkEqual(struct ListNode **head, struct ListNode *tail) {
	
	if (tail->next == NULL) return;
	checkEqual(head, tail->next);
	*head = (*head)->next;
	if ((*head)->val != tail->val) { isPalindrome = false;}

}
bool isPalindrome(struct ListNode* head){
	checkEqual(&head, head);
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *temp;
	if (l1 == NULL && l2 == NULL) return NULL;
	else if (l1 == NULL) return l2;
	else if (l2 == NULL) return l1;
	else  {
		if (l1->val > l2->val) {
			temp = l2;
			l2->next = mergeTwoLists(l2->next, l1);
		}
		else {
			temp = l1
			l1->next = mergeTwoLists(l1->next, l2);
		}
	}
	return temp;
}

int maxDepth(struct TreeNode* root){
	
	if (root == NULL) return 0;
	int leftHeight = maxDepth(root->left),
		rightHeight = maxDepth(root->right);
		
	return (leftHeight < rightHeight ? rightHeight : leftHeight) + 1;
	
}
//[120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]
//                        120
//                    70       140
//                  50 100  130   160
//                20
//[5,1,4,null,null,3,6]
//                     5
//                    1 4
//						3 6		
bool checked = true;
// 2
//1 3
struct TreeNode *getMax(struct TreeNode *root) {
	struct TreeNode *max = root;
	while ((max = max->right) != NULL);
	return max;
}
struct TreeNode *getMin(struct TreeNode *root) {
	struct TreeNode *min = root;
	while ((min = min->left) != NULL);
	return max;
}
void check(struct TreeNode *root) {
	if (root == NULL) return;
	check(root->left);
	check(root->right);
	if ((root->left != NULL && getMax(root->left)->val >= root->val) ||
		((root->right) != NULL && getMin(root->right)->val <= root->val))
	{
		checked = false;
	}
}
bool treeValid(struct TreeNode *root) {
	
	while (stack.length != 0 || root != NULL) {
		stack.push()
	}
}

bool validBst(struct TreeNode *root) {
	if (root == NULL) return true;
	if (!validBst(root->left)) {
		return false;
	}
	if (pre != NULL && root->val <= pre->val) returnse;
	pre = root;
	if (!validBst(root->right)) {
		return false;
	}
	return true;
}

bool checkNodeValRange(struct TreeNode *root, int min, int max) {
	if (root == NULL) return true;
	if (root->val <= min || root->val >= max) return false;
	return checkNodeValRange(root->left, min,  root->val) && checkNodeValRange(root->right, root->val, max);
}
bool isValidBST(struct TreeNode* root){
	checked = true;
	check(root);
	return checked;

}
int main(void)
{
	//printf("%d", strStr("ah", "h"));
	//printf("%s", genStr("111221"));
	char this[][4] = {
		"ni",
		"nih",
		"niha"
	};
	printf("%s", longestCommonPrefix((char[][5]){
				"nix",
				"nih3",
				"nih6",
				"niw"
				}, 4));

	/** printf("%s", countAndSay(2)); */
	/** printf("%s", countAndSay(3)); */
	/** printf("%s", countAndSay(4)); */
	//printf("%d", isPalindrome("A man, a plan, a canal: Panama"));
	//printf("%d", myAtoi("-91283472332"));


	//printf("%d", firstUniqChar(string));
	/** int ar1[] = {1,2,2,1}; */
	/** int ar2[] = {2, 2}; */
	/** int array[] = {3,1}; */
	/** //int array[] = {35, 12, 4, 39, 28, 390, 207, 33}; */
	/** int returnSize; */
	/** int *returnArray = intersect(ar1, 4, ar2, 2, &returnSize); */
	/** [> putchar('\n'); <] */
	/** [> printArray(returnArray, returnSize); <] */
	/** [> int (*p)[3]; <] */
	/** [> printf("%#p %#p", p, p+1); <] */
	/** int *p1; */
	/** int **p2; */
	/** int p3 = 5; */
	/**  */
	/** p2 = &p1; */
	/** *p2 = &p3; */
	/** p1 = (int*)ar1; */
	/**  */
	/** //printf("%#p %#p", *p2, p1); */
	/** typedef char (*func())[5]; */
	/** char *eng(); */
	/**  */
	/** func test; */
	/** eng = ret; */
	//reverse(1563847412);

	return 0;
}
