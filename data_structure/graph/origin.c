#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define hash(cha) ((cha) - 0x61)

char * originalDigits(char * s){
    int word[26] = {0};
	int nums[10] = {0};
	int count = 0;
	char *return_char = (char *)calloc(5000, sizeof(char));
	char *current;
	for (current = s; *current != '\0'; current++)
	{
		word[hash(*current)]++;
	}
	nums[0] = word[hash('z')];
	nums[2] = word[hash('w')];
	nums[4] = word[hash('u')];
	nums[6] = word[hash('x')];
	nums[8] = word[hash('g')];
	nums[3] = word[hash('r')] - nums[4] - nums[0];
	nums[7] = word[hash('s')] - nums[6];
	nums[5] = word[hash('v')] - nums[7];
	nums[9] = word[hash('i')] - nums[5] - nums[6] - nums[8];
	nums[1] = word[hash('o')] - nums[0] - nums[2] - nums[4];
	for (int i = 0; i < 10; i++)
	{
		while (nums[i]--) 
				return_char[count++] = i + 0x30;
	}
	return return_char;

}
int calSum(int *arr, int arrSize, int threshold)
{
	int sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += arr[i] > threshold ? threshold : arr[i];
	}
	return sum;
}
int findBestValue(int* arr, int arrSize, int target)
{
	int left = 0,
		mid,
		sum,
		right = target;

	while (left < right)
	{
		mid = (left + right) >> 2;
		sum = calSum(arr, arrSize, mid);
		if (sum < target) left = mid + 1;
		else right = mid;
	}


	return  calSum(arr, arrSize, left) - target >= target - calSum(arr, arrSize, left - 1) ? left - 1 : left;



}
int main(void)
{
	const int arr[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	printf("%d\n", arr[2][-2]);
	printf("%d", arr[-1][2]);
	printf("\n%#p, %#p, %#p", &arr[0][0], &arr[-1][2], &arr[2][-1]);
	return 0;
}
