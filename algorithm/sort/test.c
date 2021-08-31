#include <stdio.h>
#include <stdlib.h>
#include "./mergesort.h"

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
int main(void)
{
	int ar1[] = {1,2,2,1};
	int ar2[] = {2, 2};
	int array[] = {3,1};
	//int array[] = {35, 12, 4, 39, 28, 390, 207, 33};
	int returnSize;
	int *returnArray = intersect(ar1, 4, ar2, 2, &returnSize);
	/** putchar('\n'); */
	/** printArray(returnArray, returnSize); */
	/** int (*p)[3]; */
	/** printf("%#p %#p", p, p+1); */
	int *p1;
	int **p2;
	int p3 = 5;

	p2 = &p1;
	*p2 = &p3;
	p1 = (int*)ar1;

	//printf("%#p %#p", *p2, p1);
	typedef char (*func())[5];
	char *eng();

	func test;
	/** eng = ret; */
	return 0;
}
