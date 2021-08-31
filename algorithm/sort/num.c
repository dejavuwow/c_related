/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

void printArray(int array[], int array_size)
{
	for (int *temp = array; temp < array + array_size; temp++)
		printf("%d ", *temp);
	putchar('\n');
}
int* plusOne(int* digits, int digitsSize, int* returnSize){
   
    int carry = 1;
	int sum;
	int *returnArray = (int*)malloc(sizeof(int) * (digitsSize + 1));
	int index = digitsSize;

	for (int *temp = digits + digitsSize - 1; temp >= digits; temp--)
	{
		sum = carry + *temp;
		returnArray[index--] = sum >= 10 ? sum - 10 : sum;
		carry = sum >= 10 ? 1 : 0;
	}
	//printArray(returnArray, digitsSize+1);
	index = 0;
	if(carry == 1) {
		returnArray[0] = 1;
		*returnSize = digitsSize + 1;
		memmove(returnArray+1, returnArray+1, sizeof(int) * digitsSize);
	}

	else {
		*returnSize = digitsSize;
		memmove(returnArray, returnArray+1, sizeof(int) * digitsSize);
	}
    return returnArray;
}

void moveZero(int *nums, int start, int end) {
	while (start < end) {
		nums[start] = nums[start + 1];
		start++;
	}
	nums[start] = 0;

}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void moveZeroes(int* nums, int numsSize){
	int i = 0;
	int j = 0;
	while (j < numsSize) {
		if (nums[j]) {
			swap(&nums[i], &nums[j]);
			i++;
		}
		j++;
	}
}
#define HASH(value, size) ((value) % (size))
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	*returnSize = 2;
	int *hash = (int *)malloc(sizeof(int) * numsSize);
	for (int *i = hash; i < hash + numsSize; i++) {
		*i = -1;
	}
	int *returnArray = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++) {
		if (hash[HASH(target - nums[i], numsSize)] != -1) {
			returnArray[0] = i;
			returnArray[1] =  hash[HASH(target - nums[i], numsSize)];
			break;
		} else {
			hash[HASH(nums[i], numsSize)] = i;
		}
	}
	printArray(hash, numsSize);
	return returnArray;
}
int main(void) {
	int array[] = {0,1,0,3,12};
	int length;
	printArray(twoSum((int[]){2,7,11,15}, 4, 9, &length), 2);
}
