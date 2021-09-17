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
	newStr[0] = '\0';
	char tt[3] = {'\0'};
	//char *temp = str + 1;
	//printf("%s\n", str);
	for (char *temp = str; *temp != '\0'; temp++) {
		if (*temp != *(temp + 1)) {
			tt[0] = i + 0x30;
			tt[1] = *temp;
			realloc(newStr, n += 2);
			strcat(newStr, tt);
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
int main(void)
{
	//printf("%d", strStr("ah", "h"));
	//printf("%s", genStr("111221"));
	printf("%s", countAndSay(5));
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
