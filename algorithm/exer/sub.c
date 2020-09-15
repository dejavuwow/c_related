#include <stdio.h>
#include <stdlib.h>

//{1,2,3}
void printSubArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			for (int k = i; k <= j; k++)
				printf("%d ", array[k]);
			
			putchar('\n');

		}
	}
}
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
	int sum = 0;
	int target = k * threshold;
	int counts = 0;
	int i;
	for (i = 0; i < k; i++)
		sum += arr[i];
	
	int diff = target - sum;
	int old = diff;
	if (diff <= 0) counts++;
	i = 1;
	while (i  < arrSize - (k-1))
	{
		if ((diff = arr[i+k-1] - arr[i - 1]) >= old ) counts++;
        old = old - diff;
        i++;
	}
	return counts;
}
struct People {
	char name[10];
	int age;
};
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int counts = 0;
    for (int i =0; i < numsSize; i++)
    {
        if (nums[abs(nums[i] - 1)] > 0) nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    int *ret = (int*)malloc(sizeof(int) * numsSize);
    counts = 0;
    int lsize = 0;
    for (int index = 0; index < numsSize; index++)
    {
		printf("%d ", nums[index]);
        if (nums[index] > 0) {
            ret[counts++] = index + 1;
            lsize++;
        }
    }
    *returnSize = lsize;
    return ret;

}
int main(void)
{
	int a;
	int *temp = &a;
	findDisappearedNumbers((int[]){1,1,2,2,3,4,5,6},8, temp);
	return 0;
}
