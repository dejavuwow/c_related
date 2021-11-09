#include <stdio.h>
void sortedArrayToSet(int *nums, int *size) {
	int p1 = 0,
		p2 = 1;

	for (; p2 < *size - 1;) {
		nums[p1+1] = nums[p2];
		if (nums[p1] != nums[p1+1]) {
			p1++;
		}
		p2++;
	}
	*size = p1 + 1;
}
//
int getCount(int *nums, int start, int end, int target) {
	int count = 0;
	for (int i = start; i <= end; i++) {
		if (target == nums[i]) count++;
	}
	return count;
}
int getMajorNum(int *nums, int start, int end) {
	if (start == end) return nums[start];
	int mid = (end + start) / 2;
	int majorLeft = getMajorNum(nums, start, mid);
	int majorRight = getMajorNum(nums, mid + 1, end);
	if (majorLeft == majorRight) return majorLeft;
	return getCount(nums, start, end, majorLeft) < getCount(nums, start, end, majorRight) ? majorRight : majorLeft;
}
int majorityElement(int* nums, int numsSize){
	return getMajorNum(nums, 0, numsSize - 1);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

}
void main(void) {
	int ar1[] = {1,2,3, 3,3 ,5, 6, 6, 7, 9, 9};
	int size = 11;
	//
	sortedArrayToSet(ar1, &size);
	for (int *i = ar1; i < ar1 + 11; i++) {
		printf("%d ", *i);
	}

}
